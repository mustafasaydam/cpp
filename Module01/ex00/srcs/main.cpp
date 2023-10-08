#include "../includes/Zombie.hpp"

int	main(void){
	Zombie my_Zombie("ZombieOnStack");
	Zombie *heap_zombie = newZombie("ZombieOnHeap");

	my_Zombie.announce();
	heap_zombie->announce();

	randomChump("ZombieOnChump");
	delete heap_zombie;
	return (0);
}