#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
#include <cstdint>
#include "Data.hpp"

class Serializer
{
    public:
        Serializer();
        Serializer(Serializer const &c);
        ~Serializer();
        Serializer  & operator = (Serializer const &c);
        static uintptr_t   serialize(Data* ptr);
        static Data*       deserialize(uintptr_t raw);
};

#endif