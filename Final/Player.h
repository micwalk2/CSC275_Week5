#pragma once
#include "Combatant.h"

class Player : public Combatant
{
public:
	// Constructor with parameters.
	Player(const std::string& name, int health, int attack, int defense);

	// Method to attack another combatant.
	int Attack(Combatant& combatant) const override;
	// Method to defend against an attack.
	void Defend(int damage);
};