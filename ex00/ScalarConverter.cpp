#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(std::string s): _s(s)
{
    _slenght = _s.length();
}

ScalarConverter::ScalarConverter(ScalarConverter const & c): _s(c._s), _c(c._c), _i(c._i), _f(c._f), _d(c._d), _slenght(c._slenght)
{
}

ScalarConverter & ScalarConverter::operator = (ScalarConverter const &c)
{
    _s = c._s;
    _c = c._c;
    _i = c._i;
    _f = c._f;
    _d = c._d;
    _slenght = c._slenght;
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

std::ostream &operator << ( std::ostream & o, const ScalarConverter &f )
{
    o << "String: " << f.getStr() << std::endl;
    o << "String: " << f.getLen() << std::endl;
    return o;
}