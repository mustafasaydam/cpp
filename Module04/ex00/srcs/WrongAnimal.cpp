#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->_type = "Unknown";
	std::cout << "Constructor of WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	*this = src;
	std::cout << "Constructor Copy of WrongAnimal" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &src){
	if (this == &src)
		return (*this);
	*this = src;
	return (*this);
}

void	WrongAnimal::makeSound()const{
	std::cout << "No sound for this WrongAnimal" << std::endl;
}

const std::string	WrongAnimal::getType()const{
	return (this->_type);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor of WrongAnimal" << std::endl;
}
