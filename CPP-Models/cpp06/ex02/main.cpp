#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(NULL));

    for (int i = 0; i < 5; i++) {
        std::cout << "--- Test " << i + 1 << " ---" << std::endl;
        
        Base* instance = generate();

        std::cout << "Identify by pointer:   ";
        identify(instance);

        std::cout << "Identify by reference: ";
        identify(*instance);

        delete instance;
        std::cout << std::endl;
    }

    return 0;
}