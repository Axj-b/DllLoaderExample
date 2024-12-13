
#include <iostream>

int main(){
    
    std::cout << "CPU2 run" << std::endl;
    while (1) {
        _sleep(600);
        std::cout << "cpu2 ping" << std::endl;
    }

    return 0;

}