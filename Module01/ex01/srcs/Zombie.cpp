#include "../includes/Zombie.hpp"

Zombie::Zombie()
{
	std::cout << this->_name << " Constructor Called" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " Destructor Called" << std::endl;
}

void	Zombie::setname(std::string name){
	this->_name = name;
}

void	Zombie::announce(void){
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

