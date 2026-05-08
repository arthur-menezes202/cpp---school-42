#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <cmath>
#include <fstream>
#include <stdint.h>

struct Data
{
    int id;
    float value;
	std::string name;
};

class Serializer {
	public:
		Serializer();
		~Serializer();
		Serializer & operator=(const Serializer &other);
		Serializer(const Serializer &other);
		static intptr_t serialize(Data* ptr);
		static Data* deserialize(intptr_t raw);
};



#endif