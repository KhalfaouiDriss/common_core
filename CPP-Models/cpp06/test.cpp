#include <iostream>

int main()
{
    // float f = 2.8;

    // void *p = reinterpret_cast<void*>(&f);

    // std::cout << p << std::endl;
    // std::cout << &f << std::endl;
    // float *t = reinterpret_cast<float*>(p);
    // std::cout << t << std::endl;

    // int i = 97;

    // char c = static_cast<char>(i);
    // std::cout << c << std::endl;


    float *k = new float(7);

    int *j = dynamic_cast<int*>(k); 
    std::cout << *k << std::endl;


}