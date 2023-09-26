#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if(argc < 2 || argc > 2)
    {
        std::cout << "invalid number of arguments" << std::endl;
        return 0;
    }
    std::string s = argv[1];
    ScalarConverter x;
    x.convert(s);
    return 0;
}

// int main()
// {
//     ScalarConverter x;
//     std::cout << "input: '0'." << std::endl;
//     std::cout << std::endl;
//     x.convert("0");
//     std::cout << std::endl;
//     std::cout << "input: 'nan'." << std::endl;
//     std::cout << std::endl;
//     x.convert("nan");
//     std::cout << std::endl;
//     std::cout << "input: '42.0f'." << std::endl;
//     std::cout << std::endl;
//     x.convert("42.0f");
//     std::cout << std::endl;
//     std::cout << "input: '125.15'." << std::endl;
//     std::cout << std::endl;
//     x.convert("125.15");
//     std::cout << std::endl;
//     std::cout << "input: 'hola que tal'." << std::endl;
//     std::cout << std::endl;
//     x.convert("hola que tal");
//     std::cout << std::endl;
//     std::cout << "input: '-inff'." << std::endl;
//     std::cout << std::endl;
//     x.convert("-inf");
//     std::cout << std::endl;
//     std::cout << "input: '-infg'." << std::endl;
//     std::cout << std::endl;
//     x.convert("-infg");
//     std::cout << std::endl;
//     std::cout << "input: '1654864354684'." << std::endl;
//     std::cout << std::endl;
//     x.convert("1654864354684");
// }