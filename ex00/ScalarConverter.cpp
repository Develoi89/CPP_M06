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

    std::cout << "char: " << "'" << _c << "'" << std::endl;
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
            std::cout << "char: " << "'" << _c << "'" << std::endl;
        else
            std::cout << "char: Non displayable." << std::endl;
        std::cout << "int: " << _i << std::endl;
        std::cout << "float: " << _f << "f" << std::endl;
        std::cout << "double: " << _d << std::endl;
    }
    catch(std::out_of_range& e)
    {
        std::cout << "char: Non displayable." << std::endl;
        std::cout << "int: out of range." << std::endl;
        std::cout << "float: impossible." <<std::endl;
        std::cout << "double: impossible." << std::endl;
    }
}

void ScalarConverter::notANumber(std::string s)
{
    const char *istr[2] = {"nan", "nanf"};
    if (!s.compare(istr[0]))
    {
        std::cout << "HOLIIIII" << std::endl;
        _d = std::stod(s);
        _f = static_cast<float>(_d);

        std::cout << "char: impossible." << std::endl;
        std::cout << "int: impossible." << std::endl;
        std::cout << "float: " << _f << "f." << std::endl;
        std::cout << "double: " << _d << "." << std::endl;
    }
    else if (!s.compare(istr[1]))
    {
        std::cout << "HOLAAAAAAA" << std::endl;
        _f = std::stof(s);
        _d = static_cast<double>(_f);
        std::cout << "char: impossible." << std::endl;
        std::cout << "int: impossible." << std::endl;
        std::cout << "float: " << _f << "f." << std::endl;
        std::cout << "double: " << _d << "." <<  std::endl;
    }
    else
        std::cout << "WRONG ARGUMENT: is a string of chars" << std::endl;
}

void ScalarConverter::infFD(std::string s)
{
    const char *istr[4] = {"+inff", "-inff" , "-inf", "+inf"};
    int         i = 0;
    while (i < 4)
    {
        if (!s.compare(istr[i]))
        {
            if (istr[i][4] == 102)
            {
                _f = std::stof(s);
                _d = static_cast<double>(_f);
                _c = static_cast<char>(_f);
                _i = static_cast<int>(_f);
                std::cout << "char: impossible." << std::endl;
                std::cout << "int: impossible." << std::endl;
                std::cout << "float: " << _f << "f." << std::endl;
                std::cout << "double: " << _d << "." <<  std::endl;
                break;
            }
            else
            {
                _d = std::stod(s);
                _f = static_cast<float>(_d);
                _c = static_cast<char>(_d);
                _i = static_cast<int>(_d);
                std::cout << "char: impossible." << std::endl;
                std::cout << "int: impossible." << std::endl;
                std::cout << "float: " << _f << "f." << std::endl;
                std::cout << "double: " << _d << "." <<  std::endl;
                break;
            }
        }
        i++;
    }
    if (i == 4)
        std::cout << "WRONG ARGUMENT: is a string of chars" << std::endl;
}

void ScalarConverter::isFloat(std::string s)
{   
    int p = 0;
        while (s[p] != 46)
            p++;
    try 
    {
        long double temp = std::stof(s);

        std::cout << std::fixed << std::setprecision(1);
        if (temp >= std::numeric_limits<float>::lowest() && temp <= std::numeric_limits<float>::max() && p < 9)
        {
        _f = temp;
        _c = static_cast<char>(_f);
        
            if(std::isprint(_f))
                std::cout << "char: " << "'" << _c << "'" << std::endl;
            else
                std::cout << "char: Non displayable." << std::endl;
            if (temp >= std::numeric_limits<int>::lowest() && temp <= std::numeric_limits<int>::max())
            {
                _i = static_cast<int>(_f);
                std::cout << "int: " << _i << std::endl;
            }
            else
                std::cout << "int: out of range." << std::endl;
            std::cout << "float: " << _f << "f" << std::endl;
            if (temp >= std::numeric_limits<double>::lowest() && temp <= std::numeric_limits<double>::max() &&
                temp == static_cast<float>(_f))
            {
                _d = static_cast<float>(_f);
                std::cout << "double: " << _d << std::endl;
            }
            else
                std::cout << "double: out of range." <<std::endl;
        }
        else
        {
            std::cout << "char: Non displayable." << std::endl;
            std::cout << "int: impossible." << std::endl;
            std::cout << "float: impossible." <<std::endl;
            std::cout << "double: out of range." << std::endl;
        }
    }
    catch(std::out_of_range& e)
    {
        std::cout << "char: Non displayable." << std::endl;
        std::cout << "int: impossible." << std::endl;
        std::cout << "float: out of range." <<std::endl;
        std::cout << "double: impossible." << std::endl;
    }
}

void ScalarConverter::isDouble(std::string s)
{   
    int p = 0;
    while (s[p] != 46)
        p++;

    try 
    {
        long double temp = std::stod(s);

        std::cout << std::fixed << std::setprecision(1);
        if (temp >= std::numeric_limits<double>::lowest() && temp <= std::numeric_limits<double>::max() && p < 19)
        {
        _d = temp;
        _c = static_cast<char>(_d);
        
            if(std::isprint(_d))
                std::cout << "char: " << "'" << _c << "'" << std::endl;
            else
                std::cout << "char: Non displayable." << std::endl;
            if (temp >= std::numeric_limits<int>::lowest() && temp <= std::numeric_limits<int>::max())
            {
                _i = static_cast<int>(_d);
                std::cout << "int: " << _i << std::endl;
            }
            else
                std::cout << "int: out of range." << std::endl;
            if (temp >= std::numeric_limits<float>::lowest() && temp <= std::numeric_limits<float>::max() &&
                temp == static_cast<float>(_d))
            {
                _f = static_cast<float>(_d);
                std::cout << "float: " << _f << "f" << std::endl;
            }
            else
                std::cout << "float: out of range." <<std::endl;
            std::cout << "double: " << _d << std::endl;
        }
        else
        {
            std::cout << "char: Non displayable." << std::endl;
            std::cout << "int: impossible." << std::endl;
            std::cout << "float: impossible." <<std::endl;
            std::cout << "double: out of range." << std::endl;
        }
    }
    catch(std::out_of_range& e)
    {
        std::cout << "char: Non displayable." << std::endl;
        std::cout << "int: impossible." << std::endl;
        std::cout << "float: impossible." <<std::endl;
        std::cout << "double: out of range." << std::endl;
    }
}
// std::ostream &operator << ( std::ostream & o, const ScalarConverter &f )
// {
//     return o;
// }