#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

#include "./ClapTrap.hpp"
#include "./FragTrap.hpp"
#include "./ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap();
		DiamondTrap(std::string const name);
		DiamondTrap(DiamondTrap const &src);
		DiamondTrap	&operator=(DiamondTrap const &src);
		void	attack(const std::string &target);
		void	whoAmI();
		~DiamondTrap();
};

#endif