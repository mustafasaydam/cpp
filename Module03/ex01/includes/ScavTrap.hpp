#ifndef SCAVTRAP_H
# define SCAVTRAP_H
#include "./ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &src);
		ScavTrap	&operator=(ScavTrap const &src);
		void	attack(const std::string& target);
		void	guardGate();
		~ScavTrap();
};

#endif