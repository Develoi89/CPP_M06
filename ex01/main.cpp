#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data* tmp = new Data;
    tmp->n = 42;

    Serializer tester;
    uintptr_t x = tester.serialize(tmp);
    std::cout << x << std::endl;
    Data* r = tester.deserialize(x);
    std::cout << r->n << std::endl;
    delete tmp;
    return 0;
}