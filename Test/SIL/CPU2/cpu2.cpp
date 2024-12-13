 #include <windows.h>

extern int main();

 extern "C" {
     __declspec(dllexport) void TriggerMain() {
         main();
     }
 }