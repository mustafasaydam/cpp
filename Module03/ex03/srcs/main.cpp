/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:30:47 by achane-l          #+#    #+#             */
/*   Updated: 2022/07/25 03:12:35 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

int	main(void){
	DiamondTrap	MrOne("MrOne");

	MrOne.highFivesGuys();
	MrOne.takeDamage(110);
	MrOne.beRepaired(10);
	MrOne.attack("tony");
	MrOne.whoAmI();
}