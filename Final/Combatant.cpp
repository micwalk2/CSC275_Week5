#include "Combatant.h"

Combatant::Combatant()
{
	m_Name = "Unknown";
	m_Health = 0;
	m_Attack = 0;
	m_Defense = 0;
}

Combatant::Combatant(const std::string& name, int health, int attack, int defense)
{
	m_Name = name;
	m_Health = health;
	m_Attack = attack;
	m_Defense = defense;
}

std::string Combatant::GetName() const
{
	// Return the combatant's name.
	return m_Name;
}

int Combatant::GetHealth() const
{
	// Return the combatant's health.
	return m_Health;
}

int Combatant::GetDefense() const
{
	// Return the combatant's defense.
	return m_Defense;
}

bool Combatant::IsAlive() const
{
	// Return true if the combatant's health is greater than 0.
	return m_Health > 0;
}

int Combatant::Attack(Combatant& combatant) const
{
	// Calculate the damage.
	int damage = m_Attack - combatant.m_Defense;
	if (damage < 0)
	{
		damage = 0;
	}

	return damage;
}

void Combatant::TakeDamage(int damage)
{
	// Reduce the combatant's health by the damage amount.
	m_Health -= damage;
}