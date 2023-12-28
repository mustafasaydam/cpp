#include "../includes/Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Default constructor is called!" << std::endl;
}

Serializer::Serializer(const char *argv)
{
    std::cout << "Constructor with parameter is called!" << std::endl;
}

Serializer::~Serializer()
{
    std::cout << "Destructor is called!" << std::endl;
}

Serializer::Serializer(const Serializer &src)
{
    std::cout << "Copy Constructor is called!" << std::endl;
    *this = src;
}

Serializer&  Serializer::operator=(const Serializer& src){
    std::cout << "Assigment operator is called!" << std::endl;
    *this = src;
    return (*this);
}

uintptr_t	Serializer::serialize(Data*	ptr){
	uintptr_t	value;

	value = reinterpret_cast<uintptr_t>(ptr);
	return (value);
}

Data*	Serializer::deserialize(uintptr_t raw){
	return (reinterpret_cast<Data*>(raw));
}
