#pragma once
#include <iostream>
#include "Combatant.h"
#include "Player.h"
#include "Lion.h"

class Game
{
public:
	// Function to start the game.
	void StartGame();

private:
	// ONLY accessible to the Game class.
	// Function to display the winner of the game.
	void DisplayWinner(const Combatant& gladiator, const Combatant& lion) const;
};