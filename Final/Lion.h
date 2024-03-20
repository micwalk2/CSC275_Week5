#pragma once
#include "Combatant.h"

class Lion : public Combatant
{
public:
	// Constructor with parameters.
	Lion(const std::string& name, int health, int attack, int defense);

	// Method to attack another combatant.
	int Attack(Combatant& combatant) const override;
};