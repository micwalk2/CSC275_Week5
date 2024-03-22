#include "Player.h"

Player::Player(const std::string& name, int health, int attack, int defense)
{
	// Set the combatant's name, health, attack, and defense.
	m_Name = name;
	m_Health = health;
	m_Attack = attack;
	m_Defense = defense;
}

void Player::Attack(Combatant& combatant) const
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
}

void Player::Defend(int damage)
{
	// Calculate damage taken as a percentage reduction based on the defense value.
	int damageTaken = damage * (100 - m_Defense) / 100;

	// Call the TakeDamage method.
	TakeDamage(damageTaken);
}