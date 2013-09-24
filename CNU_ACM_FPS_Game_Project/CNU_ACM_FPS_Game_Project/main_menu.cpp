#include "main_menu.h"
#include "main_game.h"

void main_menu::initializeGraphics()
{
	printf("main menu");
}

bool main_menu::updateLogic()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		current_state->~game_state();
		current_state = new main_game(this->mainWindow);
		current_state->initialize();
	}
	return true;
}