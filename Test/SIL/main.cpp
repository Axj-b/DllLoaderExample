#include <windows.h>
#include <iostream>
#include <vector>
#include <functional>
#include <thread>
// Define the signature for the function you want to load
typedef void (*TriggerMainFunc)();

int main()
{
    // Names of the DLLs to load
    std::vector<std::string> dllNames = {
        "CPU1.dll",
        "CPU2.dll"

    };

    // Container to store the function pointers
    std::vector<TriggerMainFunc> triggerFunctions;

    // Load each DLL and retrieve the function
    for (const auto& dllName : dllNames) {
        HMODULE hModule = LoadLibraryA(dllName.c_str());
        if (!hModule) {
            std::cerr << "Failed to load DLL: " << dllName << std::endl;
            return -1;
        }

        // Get the function address
        auto func = (TriggerMainFunc)GetProcAddress(hModule, "TriggerMain");
        if (!func) {
            std::cerr << "Failed to find function TriggerMain in: " << dllName << std::endl;
            FreeLibrary(hModule);
            return -1;
        }

        // Store the function pointer
        triggerFunctions.push_back(func);

        std::cout << "Successfully loaded function from " << dllName << std::endl;
    }

    std::thread* cpuThreads[3];

    int cpuCounter = 0;
    // Call the collected functions
    for (const auto& func : triggerFunctions) {
        cpuThreads[cpuCounter] = new std::thread([func]() { func(); });
        //func(); // Call the function
        cpuCounter++;

    }
    // Join the threads to ensure they complete before exiting
    for (int i = 0; i < cpuCounter; ++i) {
        if (cpuThreads[i] && cpuThreads[i]->joinable()) {
            cpuThreads[i]->join();  // Wait for the thread to complete
            delete cpuThreads[i];   // Clean up the thread pointer
            cpuThreads[i] = nullptr;
        }
    }


    // Optionally, unload the DLLs (if no longer needed)
    for (const auto& dllName : dllNames) {
        HMODULE hModule = GetModuleHandleA(dllName.c_str());
        if (hModule) {
            FreeLibrary(hModule);
        }
    }

    return 0;
}
