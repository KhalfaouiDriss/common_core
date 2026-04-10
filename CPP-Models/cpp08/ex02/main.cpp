#include <iostream>
#include <stack>
#include "MutantStack.hpp"

int main()
{
	// std::stack<int> st;
	MutantStack<int> mst;

    // st.push(1);
    // st.push(2);
    // st.push(3);
    // st.push(4);

    mst.push(1);
    mst.push(2);
    mst.push(3);
    mst.push(4);
    
    MutantStack<int>::iterator it = mst.begin();
    while (it != mst.end())
    {
        std::cout << *it << std::endl;
        it++;
    }
    // int t = st.top();
    // st.pop();
    // std::cout << st.top() << std::endl;
    // st.push(t);
    // std::cout << st.top() << std::endl;

    OtherData t;
    t.iterator()
}