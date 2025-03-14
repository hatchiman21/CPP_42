/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:01:59 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/12 19:22:20 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ScavTrap robot1("M9");
	ScavTrap robot2("6-JA");

	robot1.attack("6-JA");
	robot2.guardGate();
	robot2.takeDamage(20);
	robot2.beRepaired(20);
	robot2.attack("M9");
	robot1.beRepaired(20);
	robot1.beRepaired(20);
	robot1.takeDamage(120);
	robot1.takeDamage(20);
	ScavTrap robot3(robot1);
	robot3.attack("6-JA");
	robot3.takeDamage(20);
	robot3 = robot2;
	robot3.attack("6-JA");
	robot3.takeDamage(20);
	return 0;
}
