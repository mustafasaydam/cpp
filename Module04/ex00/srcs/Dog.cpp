#include "../includes/Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	std::cout << "Constructor of Dog" << std::endl;
}

Dog::Dog(const Dog &src) : Animal()
{
	*this = src;
	std::cout << "Constructor Copy of Dog" << std::endl;
}

Dog&	Dog::operator=(const Dog &src){
	if (this == &src)
		return (*this);
	*this = src;
	return (*this);
}

void	Dog::makeSound()const{
	std::cout << "Wouuuuuuuuuuufff Wouuuuuuuuuuuffffff" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructor of Dog" << std::endl;
}