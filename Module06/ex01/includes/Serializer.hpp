#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
#include <iostream>

struct Data{
	int c;
	std::string n;
};

class Serializer {
    private:
        Serializer();
        Serializer(const char* argv);
        ~Serializer();
        Serializer(const Serializer& src);
        Serializer& operator=(const Serializer& src);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif