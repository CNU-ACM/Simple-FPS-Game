#include "main_menu.h"
#include "main_game.h"

void main_menu::initializeGraphics()
{
	printf("main menu-initializeGraphics\n"); 
}
void main_menu::initializeLogic()
{
	printf("main menu-initializeLogic\n");
}
void main_menu::initializeSound()
{
	printf("main menu-initializeSound\n");
}

bool main_menu::updateGraphics()
{
	return true;
}
bool main_menu::updateSound()
{
	return true;
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