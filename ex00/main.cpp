#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if(argc < 2)
        return 0;
    std::string s = argv[1];
    ScalarConverter x(s);
    return 0;
}