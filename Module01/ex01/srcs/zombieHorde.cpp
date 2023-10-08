#include "../includes/Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name){
	Zombie*	hordezombie;

	if (N <= 0)
		return (NULL);
	hordezombie = new Zombie[N];
	for (int i = 0; i < N; ++i){
		hordezombie[i].setname(name);
		hordezombie[i].announce();
	}
	return (hordezombie);
}