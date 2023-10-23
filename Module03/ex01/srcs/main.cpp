#include "../includes/ScavTrap.hpp"

int	main(void){
	ScavTrap Personne;
	ScavTrap MrOne("MrOne");

	Personne.attack("MrWhite");
	Personne.beRepaired(100);
	Personne.takeDamage(110);
	Personne.beRepaired(100);
	Personne.guardGate();
	MrOne.takeDamage(9);
	MrOne.takeDamage(2);
	MrOne.guardGate();
	MrOne.takeDamage(10);
	MrOne.attack("L'autre");
}
