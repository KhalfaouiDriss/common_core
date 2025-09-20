#include <iostream>

class Car
{
public:
    void start()
    {
        std::cout << "Car started 🚗" << std::endl;
    }

    static void companyInfo()
    {
        std::cout << "This is Tesla company ⚡" << std::endl;
    }
};

void start()
{
    std::cout << "Car started 🚗" << std::endl;
}

int main()
{
    void (*ptr)() = &start;

    (ptr)();

    std::cout << sizeof(ptr);
}
