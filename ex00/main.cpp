#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        std::cout << "invalid number of arguments" << std::endl;
        return 0;
    }
    std::string s = argv[1];
    ScalarConverter x;
    x.convert(s);
    return 0;
}