#ifndef HATEVER_HPP
#define HATEVER_HPP

template <typename S>
void swap(S &a, S &b)
{
    S temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename S>
S min(S &a, S &b)
{
     return (a < b) ?  a :  b;   
}

template <typename S>
S max(S &a, S &b)
{
    return (a > b) ?  a :  b; 
}

#endif