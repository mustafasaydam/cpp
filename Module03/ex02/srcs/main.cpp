#include "../includes/FragTrap.hpp"

int	main(void){
	FragTrap Personne;
	FragTrap MrOne("MrOne");

	Personne.attack("MrWhite");
	Personne.beRepaired(100);
	Personne.takeDamage(110);
	Personne.beRepaired(100);
	Personne.highFivesGuys();
	MrOne.takeDamage(9);
	MrOne.takeDamage(2);
	MrOne.highFivesGuys();
	MrOne.takeDamage(10);
	MrOne.attack("L'autre");
}