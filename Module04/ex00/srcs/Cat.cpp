#include "../includes/Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << "Constructor of Cat" << std::endl;
}

Cat::Cat(const Cat &src): Animal()
{
	*this = src;
	std::cout << "Constructor Copy of Cat" << std::endl;
}

Cat&	Cat::operator=(const Cat &src){
	if (this == &src)
		return (*this);
	*this = src;
	return (*this);
}

void	Cat::makeSound()const{
	std::cout << "Miaouuuuuuuuuuuuuuuuuuuu Miaouuuuuuuuuuuuu" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructor of Cat" << std::endl;
}