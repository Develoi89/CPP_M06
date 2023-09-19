#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
    private:
        std::string _s;
        char        _c;
        int         _i;
        float       _f;
        double      _d;
        int         _slenght;
    public:
        ScalarConverter();
        ScalarConverter(std::string s);
        ScalarConverter(ScalarConverter const & c);
        ScalarConverter & operator = (ScalarConverter const &c);
        std::string getStr()const;
        int getLen()const;
        void convert(std::string s);
};

std::ostream &operator << ( std::ostream & o, const ScalarConverter &f );

#endif