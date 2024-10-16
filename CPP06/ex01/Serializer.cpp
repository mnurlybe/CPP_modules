#include "Serializer.hpp"

/* Constructors and Destructors */

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &source)
{
    *this = source;
}
Serializer& Serializer::operator=(const Serializer &source)
{
	if (this == &source)
		return *this;
	return *this;
}

Serializer::~Serializer() {}

/* Static Method implementation */
uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}
Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

/* reinterpret_cast -> Casting pointers to other unrelated types (e.g., int to float, void*) */