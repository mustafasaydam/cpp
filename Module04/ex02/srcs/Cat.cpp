#include "../includes/Cat.hpp"

Cat::Cat() : AAnimal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Constructor of Cat" << std::endl;
}

Cat::Cat(const Cat &src) : AAnimal()
{
this->_type = "Cat";
	this->_brain = new Brain();
	*(this->_brain) = *(src.getBrain());
	std::cout << "Constructor Copy of Cat" << std::endl;
}

Cat&	Cat::operator=(const Cat &src){
	if (this == &src)
		return (*this);
	this->_type = src.getType();
	*(this->_brain) = *(src.getBrain());
	return (*this);
}


void	Cat::makeSound()const{
	std::cout << "Miaouuuuuuuuuuuuuuuuuuuu Miaouuuuuuuuuuuuu" << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Destructor of Cat" << std::endl;
}

Brain*	Cat::getBrain()const{
	return (this->_brain);
}