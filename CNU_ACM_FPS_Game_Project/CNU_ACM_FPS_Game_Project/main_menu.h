#ifndef _MAIN_MENU_H_
#define _MAIN_MENU_H_

#include "game_state.h"

class main_menu : public game_state
{
public:
	main_menu();
	~main_menu();
	bool updateLogic();
	bool updateGraphics();
	bool updateSound();
private:
	sf::Font selectionFont;

	int selectedItem;

	sf::Text titleText;
	sf::Text playGameSelection;
	sf::Text exitGameSelection;

	void initializeLogic();
	void initializeGraphics();
	void initializeSound();
};

#endif