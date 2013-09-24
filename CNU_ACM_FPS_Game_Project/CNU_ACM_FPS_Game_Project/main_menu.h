#ifndef _MAIN_MENU_H_
#define _MAIN_MENU_H_

#include "game_state.h"

class main_menu : public game_state
{
public:
	main_menu(sf::RenderWindow* mainWindow) : game_state(mainWindow)
	{
	}
	bool updateLogic();
protected:
	void initializeGraphics();
};

#endif