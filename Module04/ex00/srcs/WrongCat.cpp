#include "../includes/WrongCat.hpp"

WrongCat::WrongCat()
{
	this->_type = "WrongCat";
	std::cout << "Constructor of WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
	*this = src;
	std::cout << "Constructor Copy of WrongCat" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat &src){
	if (this == &src)
		return (*this);
	*this = src;
	return (*this);
}

void	WrongCat::makeSound()const{
	std::cout << "Wrong Miaouuuuuuuuuuuuuuuuuuuu Miaouuuuuuuuuuuuu" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor of WrongCat" << std::endl;
}