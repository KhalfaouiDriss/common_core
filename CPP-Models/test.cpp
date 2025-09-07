#include <iostream>
#include <string>

int main() {
    std::string name;
    std::string age;

    std::cout << "Enter your age: ";
    std::getline(std::cin, age);  // will read '\n' directly → empty string
    // std::cin >> age;   // user enters: 22⏎

    // '\n' is still left in the buffer here

    std::cout << "Enter your full name: ";
    // std::cin.ignore(100, '\n');
    std::getline(std::cin, name);  // will read '\n' directly → empty string

    std::cout << "Age: " << age << ", Name: " << name << std::endl;
    return 0;
}
