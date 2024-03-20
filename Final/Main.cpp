// Michael Walker
// CSC275: C++ Programming II
// 
// Week 5: Final Project

// TODO: Create multiple threads to handle different processes in the game.
// TODO: Use smart pointers to manage memory.
// TODO: Create a base class and two derived classes.

#include <iostream>
#include <string>
#include "Game.h"

int main()
{
	// Set the seed for the random number generator based on the current time.
	// This will ensure that the random numbers are different each time the program is run.
	srand(static_cast<unsigned>(time(nullptr)));

	// Create a game object and start the game.
	Game game;
	game.StartGame();
}