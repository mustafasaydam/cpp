#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << this->_name << " is new Zombie" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " Destructor Called" << std::endl;
}

void	Zombie::announce(void){
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
