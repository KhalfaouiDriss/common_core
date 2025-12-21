#include <iostream>

using namespace std;


/*

1- every obj has two static type and dynamic type

- the compiler does create a virtual table for that class, and a vptr pointing to this virtual table

func(1, 2);

return type doesn't makayd5lch fl overloading


the work done on runtime is often called dynamic dispatch
static binding | dynamic binding
*/


// class Base 
// {
//     public:
//         Base()
//         {
//             cout << "Base class created\n";
//         }
// };

class A
{
    public:
        A()
        {
            cout << "A class created\n";
        }
        void    func()
        {

        }
};

class B
{
    public:
        B()
        {
            cout << "B class created\n";
        }
        void    func()
        {
            std::cout << "secodn" << std::endl;
        }
};

class C : public A, public B
{
    public:
        using   B::func;
};



int     main()
{
   C    obj;

   obj.func();
}