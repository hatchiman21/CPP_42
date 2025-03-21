/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 05:50:47 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/17 19:50:58 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Constructors
Character::Character()
{
	for (int i = 0; i < MAX_MATERIAS; i++)
		materias[i] = NULL;
	name = "Default";
	trashMCount = 0;
	trashM[0] = NULL;
}

Character::Character(const Character &copy)
{
	*this = copy;
	trashMCount = 0;
	trashM[0] = NULL;
}

Character::Character(std::string name)
{
	for (int i = 0; i < MAX_MATERIAS; i++)
		materias[i] = NULL;
	this->name = name;
	trashMCount = 0;
	trashM[0] = NULL;
}

// Destructor
Character::~Character()
{
	int i;

	for (i = 0; i < MAX_MATERIAS; i++)
		if (materias[i])
			delete materias[i];
	for (i = 0; i < trashMCount; i++)
		if (trashM[i])
			delete trashM[i];
}

// Operators
Character & Character::operator=(const Character &assign)
{
	name = assign.getName();
	for (int i = 0; i < MAX_MATERIAS; i++)
		if (materias[i])
			delete materias[i];
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (assign.getMateria(i))
			materias[i] = assign.getMateria(i)->clone();
		else
			materias[i] = NULL;
	}
	return *this;
}

//getters / setters
std::string const	&Character::getName() const
{
	return name;
}

AMateria*	Character::getMateria(int idx) const
{
	if (idx < 0 || idx >= MAX_MATERIAS)
		return NULL;
	return materias[idx];
}

//Member functions
void Character::equip(AMateria* m)
{
	int i = 0;

	while (materias[i] && i < MAX_MATERIAS)
		i++;
	if (i < MAX_MATERIAS)
		materias[i] = m->clone();
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= MAX_MATERIAS || !materias[idx])
		return;
	if (trashMCount == 99)
	{
		for (int i = 0; i < trashMCount; i++)
			if (trashM[i])
				delete trashM[i];
		trashMCount = 0;
		trashM[0] = NULL;
	}
	trashM[trashMCount++] = materias[idx];
	trashM[trashMCount] = NULL;
	materias[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= MAX_MATERIAS || !materias[idx])
		return;
	materias[idx]->use(target);
}
