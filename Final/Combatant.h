#pragma once
#include <iostream>
#include <string>

class Combatant
{
public:
	// Default constructor.
	Combatant();
	// Constructor with parameters.
	Combatant(const std::string& name, int health, int attack, int defense);
	// Getter method for combatant name.
	std::string GetName() const;
	// Getter method for combatant health.
	int GetHealth() const;
	// Getter method for combatant defense.
	int GetDefense() const;
	// Getter method for retrieving the value of the last damage dealt.
	int GetLastDamageDealt() const;
	// Setter method for m_LastDamageDealt.
	void SetLastDamageDealt(int damage);
	// Method to check if the combatant is alive.
	virtual bool IsAlive() const;
	// Method to take damage.
	virtual void TakeDamage(int damage);

protected:
	// Method to attack another combatant.
	virtual void Attack(Combatant& combatant) const = 0;

	std::string m_Name;
	int m_Health;
	int m_Attack;
	int m_Defense;
	int m_LastDamageDealt;
};