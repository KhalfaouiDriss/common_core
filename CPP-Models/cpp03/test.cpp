#include <iostream>

class Base 
{
    public:
        void member()
        {
            std::cout << "Base mameber\n";
        }
};

class Sec : virtual public Base
{
    public:
        void fct()
        {
            std::cout << "Sec mameber\n";
        }
};

class Thu : public virtual Base, public Sec
{
    public:
        void fct()
        {
            std::cout << "Sec mameber\n";
        }
};

int main()
{
    Thu x;

    x.member();
    x.fct();
}