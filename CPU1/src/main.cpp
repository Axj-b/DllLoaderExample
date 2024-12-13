
#include <iostream>

int main(){
    
    std::cout << "CPU1 run" << std::endl;

    while (1) {
        _sleep(500);
        std::cout << "cpu1 ping" << std::endl;
    }

    return 0;

}