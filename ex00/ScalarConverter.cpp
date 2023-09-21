#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter const & c): _c(c._c), _i(c._i), _f(c._f), _d(c._d)
{
}

ScalarConverter & ScalarConverter::operator = (ScalarConverter const &c)
{
    _c = c._c;
    _i = c._i;
    _f = c._f;
    _d = c._d;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::isChar(std::string s)
{
    _c = s[0];
    _i = static_cast<int>(_c);
    _f = static_cast<float>(_c);
    _d = static_cast<double>(_c);

    std::cout << std::fixed << std::setprecision(1);

    std::cout << "char: " << _c << std::endl;
    std::cout << "int: " << _i << std::endl;
    std::cout << "float: " << _f << "f" << std::endl;
    std::cout << "double: " << _d << std::endl;
}

void ScalarConverter::isInt(std::string s)
{
    try
    {
        std::cout << std::fixed << std::setprecision(1);

        _i = std::stoi(s);
        _f = static_cast<float>(_i);
        _d = static_cast<double>(_i);
        _c = static_cast<char>(_i);
        if(std::isprint(_i))
            std::cout << "char: " << _c << std::endl;
        else
            std::cout << "char: Non displayable." << std::endl;
        std::cout << "int: " << _i << std::endl;
        std::cout << "float: " << _f << "f" << std::endl;
        std::cout << "double: " << _d << std::endl;
    }
    catch(std::out_of_range&)
    {
        std::cout << "char: Non displayable." << std::endl;
        std::cout << "int: out of range." << std::endl;
        std::cout << "float: impossible." <<std::endl;
        std::cout << "double: impossible." << std::endl;
    }
}
// std::ostream &operator << ( std::ostream & o, const ScalarConverter &f )
// {
//     return o;
// }