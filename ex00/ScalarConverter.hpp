#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

class ScalarConverter
{
    private:
        char        _c;
        int         _i;
        float       _f;
        double      _d;
    public:
        ScalarConverter();
        ScalarConverter(ScalarConverter const & c);
        ScalarConverter & operator = (ScalarConverter const &c);
        ~ScalarConverter();

        void convert(std::string s);

        void isChar(std::string s);
        void isInt(std::string s);
        void isFloat(std::string s);
        void isDouble(std::string s);
};

// std::ostream &operator << ( std::ostream & o, const ScalarConverter &f );

#endif