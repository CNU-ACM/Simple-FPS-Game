#ifndef _MAIN_GAME_H_
#define _MAIN_GAME_H_

#include "game_state.h"

class main_game : public game_state
{
public:
	main_game(sf::RenderWindow* mainWindow) : game_state(mainWindow)
	{
	}
	bool updateLogic();
	bool updateGraphics();
	bool updateSound();
protected:
	void initializeLogic();
	void initializeGraphics();
	void initializeSound();
};

#endif