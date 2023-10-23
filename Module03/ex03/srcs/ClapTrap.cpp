/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:16:31 by achane-l          #+#    #+#             */
/*   Updated: 2022/07/25 03:35:33 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Unknown"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) : _name(src._name)
{
	std::cout << "Copy Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target){
	if (this->_HitPoints == 0 || this->_EnergyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't attack !" << std::endl;
		return;
	}
	this->_EnergyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->_HitPoints == 0 || this->_EnergyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't be repaired !" << std::endl;
		return;
	}
	this->_EnergyPoints--;
	if (amount + this->_HitPoints < this->_HitPoints)
		this->_HitPoints = UINT_MAX;
	else
		this->_HitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " add " << amount << " of Hit points." << std::endl;  
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (this->_HitPoints == 0 || this->_EnergyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot take enought Damage." << std::endl;
		return;
	}
	if (amount > this->_HitPoints)
		this->_HitPoints = 0;
	else
		this->_HitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " lost " << amount << " of Damage points." << std::endl;  
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &src){
	this->_name = src._name;
	this->_HitPoints = src._HitPoints;
	this->_EnergyPoints = src._EnergyPoints;
	this->_AttackDamage = src._AttackDamage;
	return (*this);
}