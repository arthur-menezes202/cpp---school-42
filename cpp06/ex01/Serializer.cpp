#include "Serializer.hpp"


Serializer::Serializer() {}
Serializer::~Serializer() {}
Serializer::Serializer(const Serializer &other) { *this = other; }
Serializer &Serializer::operator=(const Serializer &other) {
	(void)other;
	return *this;
}

intptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(intptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

