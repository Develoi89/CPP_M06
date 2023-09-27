#include "Serializer.hpp"

Serializer::Serializer()
{}

Serializer::Serializer(Serializer const &c)
{}

Serializer::~Serializer()
{}

Serializer& Serializer::operator = (Serializer const &c)
{
    return *this;
}

uintptr_t   Serializer::serialize(Data* ptr)
{
    uintptr_t r;

    r = reinterpret_cast<uintptr_t>(ptr);

    return r;
}

Data*       Serializer::deserialize(uintptr_t raw)
{
    Data* r = reinterpret_cast<Data*>(raw);
    return r;
}