// Include the header for windows functions.
#include <Windows.h>
// Include the header for standard I/O functions.
#include <stdio.h>

// Include the functions for SFML's graphics and audio.
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

// Include the header for the game states.
#include "game_state.h"
#include "main_menu.h"
#include "main_game.h"

// Actually declare the current state.
game_state* current_state;

#ifndef _DEBUG
int main();
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	return main();
}
#endif

int main()
{
	sf::RenderWindow mainWindow;

	current_state = new main_menu(&mainWindow);

	mainWindow.create(sf::VideoMode(800, 600), "ACM FPS Game");
	mainWindow.setVerticalSyncEnabled(true);

	current_state->initialize();

	while(mainWindow.isOpen())
	{
		sf::Event windowPollEvent;
		while(mainWindow.pollEvent(windowPollEvent))
		{
			switch(windowPollEvent.type)
			{
			case sf::Event::Closed:
				mainWindow.close();
				return 0;
			case sf::Event::Resized:
				break;
			case sf::Event::GainedFocus:
				break;
			case sf::Event::LostFocus:
				break;
			}
		}

		current_state->updateLogic();
		current_state->updateGraphics();
		current_state->updateSound();

		mainWindow.display();
	}

	return 0;
}