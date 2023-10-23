#include "../includes/ClapTrap.hpp"

int	main(void){
	ClapTrap Personne;
	ClapTrap MrOne("MrOne");

	Personne.attack("MrWhite");
	Personne.beRepaired(100);
	Personne.takeDamage(110);
	Personne.beRepaired(100);
	MrOne.takeDamage(9);
	MrOne.takeDamage(2);
	MrOne.takeDamage(10);
	MrOne.attack("L'autre");
}