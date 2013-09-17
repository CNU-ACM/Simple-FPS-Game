#include "main_game.h"
#include "main_menu.h"

main_game::main_game()
{
	this->initialize();
}

main_game::~main_game()
{
}

void main_game::initializeLogic()
{
}
void main_game::initializeGraphics()
{
}
void main_game::initializeSound()
{
}

bool main_game::updateLogic()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		((main_game*)current_state)->~main_game();
		current_state = new main_menu();
	}
	return true;
}
bool main_game::updateGraphics()
{
	mainWindow.clear(sf::Color::White);
	return true;
}
bool main_game::updateSound()
{
	return true;
}
