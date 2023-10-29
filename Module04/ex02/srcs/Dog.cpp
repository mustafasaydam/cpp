#include "../includes/Dog.hpp"

Dog::Dog() : AAnimal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Constructor of Dog" << std::endl;
}

Dog::Dog(const Dog &src) : AAnimal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	*(this->_brain) = *(src.getBrain());
	std::cout << "Constructor Copy of Dog" << std::endl;
}

Dog&	Dog::operator=(const Dog &src){
	if (this == &src)
		return (*this);
	this->_type = src.getType();
	*(this->_brain) = *(src.getBrain());
	return (*this);
}


void	Dog::makeSound()const{
	std::cout << "Wouuuuuuuuuuufff Wouuuuuuuuuuuffffff" << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Destructor of Dog" << std::endl;
}

Brain*	Dog::getBrain()const{
	return (this->_brain);
}