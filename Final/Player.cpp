#include "Player.h"

Player::Player(const std::string& name, int health, int attack, int defense)
{
	// Set the combatant's name, health, attack, and defense.
	m_Name = name;
	m_Health = health;
	m_Attack = attack;
	m_Defense = defense;
}

int Player::Attack(Combatant& combatant) const
{
	// Calculate the damage factoring in target's defense.
	int damage = (m_Attack * 10) - combatant.GetDefense();
	if (damage < 0)
	{
		damage = 0;
	}

	// Deal the damage to the other combatant.
	combatant.TakeDamage(damage);

	// Set the last damage dealt.
	combatant.SetLastDamageDealt(damage);

	std::cout << m_Name << " attacks " << combatant.GetName() << " for " << damage << " damage!" << std::endl;
	std::cout << combatant.GetName() << " has " << combatant.GetHealth() << " health remaining." << std::endl;

	return damage;
}

void Player::Defend(int damage)
{
	// Calculate damage taken as a percentage reduction based on the defense value.
	int damageTaken = damage - m_Defense;

	// Call the TakeDamage method.
	TakeDamage(damageTaken);

	std::cout << m_Name << " defends and takes " << damageTaken << " damage!" << std::endl;
	std::cout << m_Name << " has " << m_Health << " health remaining." << std::endl;
	
	// Pause the screen for user input.
	system("pause");
}