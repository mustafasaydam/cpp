/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 01:12:03 by achane-l          #+#    #+#             */
/*   Updated: 2022/07/25 01:25:10 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
	std::cout << "Default Constructor of FragTrap" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
	std::cout << "Constructor of FragTrap" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src){
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
	*this = src;
	std::cout << "Copy Constructor of FragTrap" << std::endl;

}

FragTrap	&FragTrap::operator=(FragTrap const &src){
	this->_name = src._name;
	this->_HitPoints = src._HitPoints;
	this->_EnergyPoints = src._EnergyPoints;
	this->_AttackDamage = src._AttackDamage;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor of FragTrap" << std::endl;
}

void	FragTrap::highFivesGuys(void){
	std::cout << this->_name << " asking for getting an High Five !!" << std::endl;
}