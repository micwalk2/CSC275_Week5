#pragma once
#include "Combatant.h"

class Enemy : public Combatant
{
public:
	// Constructor with parameters.
	Enemy(const std::string& name, int health, int attack, int defense);

	// Method to attack another combatant.
	void Attack(Combatant& combatant) const override;
};