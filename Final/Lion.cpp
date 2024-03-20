#include "Lion.h"

Lion::Lion(const std::string& name, int health, int attack, int defense)
{
	// Set the combatant's name, health, attack, and defense.
	m_Name = name;
	m_Health = health;
	m_Attack = attack;
	m_Defense = defense;
}

int Lion::Attack(Combatant& combatant) const
{
	// Calculate the damage.
	int damage = m_Attack - combatant.GetDefense();
	if (damage < 0)
	{
		damage = 0;
	}

	return damage;
}