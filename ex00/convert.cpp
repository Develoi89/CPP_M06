#include "ScalarConverter.hpp"

void ScalarConverter::convert()
{
    //en esta parte comprobamos que solo tenga un digito no numerico para saber si es un char.
    if((_slenght == 1) && (_s[0] >= 32 && _s[0] <= 126) && !(_s[0] >= 48 && _s[0] <= 57))
        std::cout << "is a displayable char!!!" << std::endl;
    //en esta otra parte comprobamos que este unico digito es numerico para saber si es un int.
    else if((_slenght == 1) && (_s[0] >= 32 && _s[0] <= 126) && (_s[0] >= 48 && _s[0] <= 57))
        std::cout << "is a int!!!" << std::endl;
    //en el siguiente "else if" empezamos a evaluar los casos en los que la string es de mas de un digito.
    else if (_slenght > 1)
    {
        //en el primer if, evaluamos la posibilidad que el primer digito sea un signo i los siguientes todos numericos
        //y asi lo podemos catalogar si o si como entero.
        if(((_s[0] == 45 || _s[0] == 43) || (_s[0] >= 48 && _s[0] <= 57)) && (_s[1] >= 48 && _s[1] <= 57))
        {
            int i = 1;
            while(i < _slenght && (_s[i] >= 48 && _s[i] <= 57))
                i++;
            if (i == _slenght)
                std::cout << "is a int!!!" << std::endl;
            //con este else if buscamos el punto para catalogar la variable como float o double.
            else if (_s[i] == 46)
            {
                i++;
                while(i < _slenght && (_s[i] >= 48 && _s[i] <= 57))
                    i++;
                if (i == _slenght && (_s[i - 1] >= 48 && _s[i- 1] <= 57))
                    std::cout << "is a double!!!" << std::endl;
                else if (i == _slenght - 1 && (_s[i] == 102))
                    std::cout << "is a float!!!" << std::endl;
                else
                    std::cout << "is a wrong argument" << std::endl;
            }
            else
                std::cout << "is a wrong argument" << std::endl;
        }
        //comprobamos las excepciones de los infinitos para los floats y los doubles.
        else if((_s[0] == 45 || _s[0] == 43) && (_s[1] < 48 || _s[1] > 57))
        {
            const char *istr[4] = {"+inff", "-inff" , "-inf", "+inf"};
            int         i = 0;
            while (i < 4)
            {
                if (!_s.compare(istr[i]))
                    std::cout << "is float or double: " << istr[i] << std::endl;
                i++;
            }
        }//comprobamos los "nan" para doubles y floats.
        else if(!(_s[0] >= 48 && _s[0] <= 57))
        {
            const char *istr[2] = {"nan", "nanf"};
            if (!_s.compare(istr[0]))
                std::cout << "is float or double: " << istr[0] << std::endl;
            else if (!_s.compare(istr[1]))
                std::cout << "is float or double: " << istr[1] << std::endl;
            else
                std::cout << "is a string of chars" << std::endl;
        }
    }
}