#include "../includes/AAnimal.hpp"

AAnimal::AAnimal()
{
	this->_type = "Unknown";
	std::cout << "Constructor of AAnimal" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	*this = src;
	std::cout << "Constructor Copy of AAnimal" << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal &src){
	if (this == &src)
		return (*this);
	this->_type = src.getType();
	return (*this);
}

const std::string	AAnimal::getType()const{
	return (this->_type);
}

AAnimal::~AAnimal(){
	std::cout << "Destructor of AAnimal" << std::endl;
}