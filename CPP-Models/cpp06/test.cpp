#include <iostream>

class Animal {
public:
    virtual ~Animal() {}
    virtual void speak() { std::cout << "I am Animal\n"; }
};

class Dog : public Animal {
public:
    void speak() override { std::cout << "I am Dog\n"; }
    void special() { std::cout << "I am Dog!\n"; }
};

class cat : public Animal {
public:
    void speak() override { std::cout << "I am cat\n"; }
    void special() { std::cout << "I am cat!\n"; }
};

int main() {
    try
    {
        Animal* An = new Dog();
        Dog* StaticDog = static_cast<Dog*>(An);
        StaticDog->speak();
        Dog* DynamicDog = dynamic_cast<Dog*>(An);
        if(DynamicDog)
            std::cout << "Animal is dog\n";
        void* address = reinterpret_cast<void*>(An);
        std::cout << "An add :" << An << " | Memory Address in integer format: " << address << std::endl;
        std::string str = "hello";
        std::cout << reinterpret_cast<std::string*>(&str) << std::endl;
        std::cout << &str;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}


