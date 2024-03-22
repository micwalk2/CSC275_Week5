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

int Combatant::GetLastDamageDealt() const
{
	// Return the last damage dealt.
	return m_LastDamageDealt;

}

void Combatant::SetLastDamageDealt(int damage)
{
	// Set the last damage dealt.
	m_LastDamageDealt = damage;
}

bool Combatant::IsAlive() const
{
	// Return true if the combatant's health is greater than 0.
	return m_Health > 0;
}

void Combatant::Attack(Combatant& combatant) const
{
	// Calculate the damage.
	int damage = m_Attack - combatant.m_Defense;
	if (damage < 0)
	{
		damage = 0;
	}

	// Deal the damage to the other combatant.
	combatant.TakeDamage(damage);

	// Set the last damage dealt.
	combatant.SetLastDamageDealt(damage);
}

void Combatant::TakeDamage(int damage)
{
	// Reduce the combatant's health by the damage amount.
	m_Health -= damage;

	// Check for death.
	if (m_Health < 0)
	{
		m_Health = 0;
	}
}