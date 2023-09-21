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

std::string ScalarConverter::getStr()const
{
    return _s;
}

int ScalarConverter::getLen()const
{
    return _slenght;
}

// std::ostream &operator << ( std::ostream & o, const ScalarConverter &f )
// {
//     return o;
// }