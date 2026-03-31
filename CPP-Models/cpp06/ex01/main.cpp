#include "Serializer.hpp"

void fct(uintptr_t ptr)
{
    Data db = *Serializer::deserialize(ptr);
    std::cout << db.id << std::endl;
}

int main()
{
    Data mydb;
    mydb.id = 3;
    mydb.code = 'o';
    uintptr_t ptr = Serializer::serialize(&mydb);
    fct(ptr);
}