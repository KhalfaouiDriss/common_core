#include <iostream>
#include <exception>

class test
{
private:
    int *g;
public:
    test(int a);
    ~test();
};

test::test(int a)
{
    std::cout << "class created\n";
    if (a > 5)
        throw a;
    g = new int;
    *g = a;
}

test::~test()
{
    std::cout << "class deleted\n";
    delete g;
}


void fct(int i)
{
    std::cout << "Before throwing exception\n";
    // int *g = new int;
    test n(i);
    // if (i > 5)
    //     throw 0;
    std::cout << "This line will never run\n";
    // delete g;
}

int main()
{
    try
    {
        fct(6);
    }
    catch (const int a)
    {
        std::cout << "Caught exception: " << a << std::endl;
    }

    std::cout << "Program continues normally\n";
    return 0;
}