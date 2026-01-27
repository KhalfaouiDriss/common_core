#include <iostream>

class Base {
public:
    virtual ~Base() {}
    virtual void speak() { std::cout << "I am Base\n"; }
};

class Child : public Base {
public:
    void speak() override { std::cout << "I am Child\n"; }
    void special() { std::cout << "Child only!\n"; }
};

int main() {
    try
    {
        Base a;
        Child& c = dynamic_cast<Child&>(a);
        std::cout << "success\n";
        // c.special(); 
        // c.speak();
        (void)c;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
