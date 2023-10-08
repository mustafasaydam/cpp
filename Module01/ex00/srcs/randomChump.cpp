#include "../includes/Zombie.hpp"

void	randomChump(std::string name){
	Zombie	myZombie(name);
	myZombie.announce();
	return;
}