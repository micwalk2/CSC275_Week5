#include "Enemy.h"

Enemy::Enemy(const std::string& name, int health, int attack, int defense)
{
	// Set the combatant's name, health, attack, and defense.
	m_Name = name;
	m_Health = health;
	m_Attack = attack;
	m_Defense = defense;
}

void Enemy::Attack(Combatant& combatant) const
{
	// Calculate the damage.
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