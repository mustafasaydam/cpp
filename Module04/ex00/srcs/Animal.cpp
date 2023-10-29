#include "../includes/Animal.hpp"

Animal::Animal()
{
	this->_type = "Unknown";
	std::cout << "Constructor of Animal" << std::endl;
}

Animal::Animal(const Animal &src)
{
	*this = src;
	std::cout << "Constructor Copy of Animal" << std::endl;
}

Animal&	Animal::operator=(const Animal &src){
	if (this == &src)
		return (*this);
	*this = src;
	return (*this);
}

void	Animal::makeSound()const{
	std::cout << "No sound for this Animal" << std::endl;
}

const std::string	Animal::getType()const{
	return (this->_type);
}

Animal::~Animal()
{
	std::cout << "Destructor of Animal" << std::endl;
}