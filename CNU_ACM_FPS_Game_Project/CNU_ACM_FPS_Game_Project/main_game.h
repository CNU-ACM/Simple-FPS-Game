#ifndef _MAIN_GAME_H_
#define _MAIN_GAME_H_

#include "game_state.h"

class main_game : public game_state
{
public:
	main_game();
	~main_game();
	bool updateLogic();
	bool updateGraphics();
	bool updateSound();
private:
	sf::Texture basic_character_tex;
	sf::Texture overlay_tex;
	sf::Sprite basic_character;
	sf::Sprite overlay;

	void initializeLogic();
	void initializeGraphics();
	void initializeSound();
};

#endif