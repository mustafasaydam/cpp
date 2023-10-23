#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "./ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap const &src);
	FragTrap	&operator=(FragTrap const &src);
	void	highFivesGuys(void);
	~FragTrap();
};

#endif