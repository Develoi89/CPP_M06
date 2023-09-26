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

int isRationalNumber(std::string s)
{
    unsigned long i = 1;
    while(i < s.length() && isNumeric(s[i]))
        i++;
    if (i == s.length())
        return 0;
    else if (s[i] == 46)
    {
        i++;
        while(i < s.length() && isNumeric(s[i]))
            i++;
        if (i == s.length() && isNumeric(s[i - 1]))
            // std::cout << "is a double!!!" << std::endl;
            return 1;
        else if (i == s.length() - 1 && (s[i] == 102))
            // std::cout << "is a float!!!" << std::endl;
            return 2;
        else
            // std::cout << "is a wrong argument" << std::endl;
            return 3;
    }
    else
        // std::cout << "is a wrong argument" << std::endl;
        return 3;
}

void ScalarConverter::convert(std::string s)
{
    if((s.length() == 1) && isDisplayable(s[0]) && !isNumeric(s[0]))
        isChar(s);
    else if((s.length() == 1) && isDisplayable(s[0]) && isNumeric(s[0]))
        isInt(s);
    else if (s.length() > 1)
    {
        if((((s[0] == 45 || s[0] == 43) || isNumeric(s[0]))) &&
            (isNumeric(s[1]) || (s[1] == 46)))
            {
            if(!isRationalNumber(s))
                isInt(s);
            else if (isRationalNumber(s) == 2)
                isFloat(s);
            else if (isRationalNumber(s) == 1)
                isDouble(s);
            else
                std::cout << "is a wrong argument" << std::endl;
            }
        else if((s[0] == 45 || s[0] == 43) && !isNumeric(s[1]))
            infFD(s);
        else if(!isNumeric(s[0]))
            notANumber(s);
        else
            std::cout << "impossible to sort" << std::endl;
    }
}