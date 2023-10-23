/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:11:12 by achane-l          #+#    #+#             */
/*   Updated: 2022/07/25 00:57:22 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap()
{
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	std::cout << "Default Constructor of ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	std::cout << "Constructor of ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src):ClapTrap(src)
{
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	*this = src;
	std::cout << "Copy Constructor of ScavTrap called" << std::endl;
}


ScavTrap::~ScavTrap()
{
	std::cout << "Destructor of ScavTrap called" << std::endl;
}

void	ScavTrap::attack(const std::string& target){
	if (this->_HitPoints == 0 || this->_EnergyPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't attack !" << std::endl;
		return;
	}
	this->_EnergyPoints--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &src){
	this->_name = src._name;
	this->_HitPoints = src._HitPoints;
	this->_EnergyPoints = src._EnergyPoints;
	this->_AttackDamage = src._AttackDamage;
	return (*this);
}

void	ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->_name << " is in Gate keeper Mode !!!" << std::endl;
}