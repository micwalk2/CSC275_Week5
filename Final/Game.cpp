#include <thread>
#include <mutex>
#include "Game.h"

// Global variables.
std::mutex g_Mutex;

void Game::StartGame()
{
	// Create two combatants using unique pointers.
	// std::unique_ptr<Player> Gladiator = std::make_unique<Player>("Gladiator", 100, 10, 25);
	// std::unique_ptr<Enemy> Lion = std::make_unique<Enemy>("Lion", 100, 15, 20);
	// Create two combatants using raw pointers.
	Player* Gladiator = new Player("Gladiator", 100, 10, 25);
	Enemy* Lion = new Enemy("Lion", 100, 15, 20);

	std::cout << "\n\n";
	std::cout << "\t*---------------------------------------*\n";
	std::cout << "\t|             THE COLISSEUM             |\n";
	std::cout << "\t*---------------------------------------*\n\n";
	std::cout << "As the Emperor enters the grand coliseum, a hushed anticipation envelops the arena, each spectator rising in deference to witness the sovereign's presence.\n";
	std::cout << "The Emperor raises his hand, and the crowd falls silent. The Emperor speaks, 'Let the games begin!'  The crowd erupts into cheers!\n\n";

	// Pause the system for user input.
	system("pause");

	// Introduce the player combatant.
	std::cout << "\nUnder the crowd's oppressive noise, a formidable gladiator emerges, their sinewy frame adorned in glistening armor, embodying the epitome of strength and prowess.\n";
	std::cout << "The crowd roars in approval as the gladiator raises their weapon, a testament to their unwavering resolve.\n\n";

	// Pause the system for user input.
	system("pause");

	// Introduce the second combatant.
	std::cout << "\nThe crowd's fervor reaches a fever pitch as a ferocious lion is released from its cage, its primal roar reverberating throughout the coliseum.\n";
	std::cout << "The lion's eyes gleam with an insatiable hunger, its powerful muscles rippling beneath its golden fur.\n\n";

	// Pause the system for user input.
	system("pause");

	// Set up the control loop based on the combatants' alive status.
	while (Gladiator->IsAlive() && Lion->IsAlive())
	{
		// Variable to store the user's choice.
		int choice;

		// Clear the console screen.
		system("cls");

		// Display the combatant options Attack or Defend.
		std::cout << "The gladiator and the lion face each other, ready to engage in combat.\n";
		std::cout << "The gladiator has " << Gladiator->GetHealth() << " health remaining.\n";
		std::cout << "The lion has " << Lion->GetHealth() << " health remaining.\n\n";

		// Prompt the user to select an action.
		std::cout << "Select an action for the gladiator:\n";
		std::cout << "1. Attack\n";
		std::cout << "2. Defend\n";
		std::cout << "Choice: ";
		std::cin >> choice;

		// Process the user's choice.
		switch (choice)
		{
			case 1:
			{
				// Create two threads to handle the combatants' attacks.
				std::thread combatant1Thread(&Player::Attack, Gladiator, std::ref(*Lion));
				std::thread combatant2Thread(&Enemy::Attack, Lion, std::ref(*Gladiator));

				// Join the threads to synchronize the actions.
				combatant1Thread.join();
				combatant2Thread.join();
				break;
			}
			case 2:
			{
				// Call the attack method for combatant2.
				Lion->Attack(*Gladiator);
				// Access the damage dealt after the attack.
				int damage = Lion->GetLastDamageDealt();
				// Call the Defend method for the gladiator.
				Gladiator->Defend(damage);
				break;
			}
			default:
			{
				// Display an error message for an invalid choice.
				std::cout << "Invalid choice. Please try again.\n";
				break;
			}
		}
	}

	// Display the winner of the game.
	DisplayWinner(*Gladiator);
}

void Game::DisplayWinner(const Combatant& gladiator) const
{
	// Clear the console screen.
	system("cls");

	// Display the winner of the game.
	if (gladiator.IsAlive())
	{
		std::cout << "The gladiator emerges victorious, the crowd erupting into a deafening ovation!\n";
	}
	else
	{
		std::cout << "The lion emerges victorious, the crowd falling silent in awe of the beast's ferocity!\n";
	}
}