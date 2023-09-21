#include "ScalarConverter.hpp"

bool isDisplayable(char c)
{
    if(c >= 32 && c <= 126)
        return true;
    else
        return false;
}

bool isNumeric(char c)
{
    if(c >= 48 && c <= 57)
        return true;
    else
        return false;
}

void isRationalNumber(std::string s)
{
    unsigned long i = 1;
    while(i < s.length() && (s[i] >= 48 && s[i] <= 57))
        i++;
    if (i == s.length())
        std::cout << "is a int!!!" << std::endl;
    else if (s[i] == 46)
    {
        i++;
        while(i < s.length() && (s[i] >= 48 && s[i] <= 57))
            i++;
        if (i == s.length() && (s[i - 1] >= 48 && s[i - 1] <= 57))
            std::cout << "is a double!!!" << std::endl;
        else if (i == s.length() - 1 && (s[i] == 102))
            std::cout << "is a float!!!" << std::endl;
        else
            std::cout << "is a wrong argument" << std::endl;
    }
    else
        std::cout << "is a wrong argument" << std::endl;
}

void infFD(std::string s)
{
    const char *istr[4] = {"+inff", "-inff" , "-inf", "+inf"};
    int         i = 0;
    while (i < 4)
    {
        if (s.compare(istr[i]))
            std::cout << "is float or double: " << istr[i] << std::endl;
        i++;
    }
}

void notANumber(std::string s)
{
    const char *istr[2] = {"nan", "nanf"};
    if (!s.compare(istr[0]))
        std::cout << "is float or double: " << istr[0] << std::endl;
    else if (!s.compare(istr[1]))
        std::cout << "is float or double: " << istr[1] << std::endl;
    else
        std::cout << "is a string of chars" << std::endl;
}

void ScalarConverter::convert(std::string s)
{
    if((s.length() == 1) && isDisplayable(s[0]) && !isNumeric(s[0]))
        std::cout << "is a displayable char!!!" << std::endl;
    else if((s.length() == 1) && isDisplayable(s[0]) && isNumeric(s[0]))
        std::cout << "is a int!!!" << std::endl;
    else if (s.length() > 1)
    {
        if((((s[0] == 45 || s[0] == 43) || isNumeric(s[0]))) &&
            (isNumeric(s[1]) || (s[1] == 46)))
            isRationalNumber(s);
        else if((s[0] == 45 || s[0] == 43) && !isNumeric(s[1]))
            infFD(s);
        else if(!isNumeric(s[0]))
            notANumber(s);
        else
            std::cout << "impossible to sort" << std::endl;
    }
}