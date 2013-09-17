#include "main_menu.h"
#include "main_game.h"

main_menu::main_menu()
{
	this->initialize();
}

main_menu::~main_menu()
{
}

void main_menu::initializeLogic()
{
	this->selectedItem = 0;
}
void main_menu::initializeGraphics()
{
	this->selectionFont.loadFromFile("Arial.ttf");

	this->titleText.setFont(this->selectionFont);
	this->titleText.setCharacterSize(128);
	this->titleText.setString("ACM FPS Game");
	this->titleText.setColor(sf::Color::White);
	this->titleText.setStyle(sf::Text::Bold);
	this->titleText.setPosition(WINDOW_WIDTH / 8, 0);

	this->playGameSelection.setFont(this->selectionFont);
	this->playGameSelection.setCharacterSize(32);
	this->playGameSelection.setString("Play");
	this->playGameSelection.setColor(sf::Color::White);
	this->playGameSelection.setStyle(sf::Text::Bold);
	this->playGameSelection.setPosition(mainWindow.getView().getSize().x / 2, mainWindow.getView().getSize().y / 2);

	this->exitGameSelection.setFont(this->selectionFont);
	this->exitGameSelection.setCharacterSize(32);
	this->exitGameSelection.setString("Exit");
	this->exitGameSelection.setColor(sf::Color::White);
	this->exitGameSelection.setStyle(sf::Text::Bold);
	this->exitGameSelection.setPosition(mainWindow.getView().getSize().x / 2, mainWindow.getView().getSize().y / 2 + 64);
}
void main_menu::initializeSound()
{
}

bool main_menu::updateLogic()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		while(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down));
		this->selectedItem += 1;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		while(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up));
		this->selectedItem -= 1;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		switch(this->selectedItem)
		{
		case 0:
			((main_menu*)current_state)->~main_menu();
			current_state = new main_game();
			break;
		case 1:
			mainWindow.close();
			return false;
		}
	}
	if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		float x = sf::Mouse::getPosition(mainWindow).x * mainWindow.getView().getSize().x / mainWindow.getSize().x;
		float y = sf::Mouse::getPosition(mainWindow).y * mainWindow.getView().getSize().y / mainWindow.getSize().y;
		if(this->playGameSelection.getGlobalBounds().contains(x, y))
		{
			((main_menu*)current_state)->~main_menu();
			current_state = new main_game();
			this->selectedItem = 0;
		}
		if(this->exitGameSelection.getGlobalBounds().contains(x, y))
		{
			mainWindow.close();
			this->selectedItem = 1;
			return false;
		}
	}

	this->selectedItem &= 1;

	return true;
}
bool main_menu::updateGraphics()
{
	mainWindow.clear(sf::Color::Black);

	switch(this->selectedItem)
	{
	case 0:
		this->playGameSelection.setColor(sf::Color::Red);
		this->exitGameSelection.setColor(sf::Color::White);
		break;
	case 1:
		this->playGameSelection.setColor(sf::Color::White);
		this->exitGameSelection.setColor(sf::Color::Red);
		break;
	}

	mainWindow.draw(this->titleText);
	mainWindow.draw(this->playGameSelection);
	mainWindow.draw(this->exitGameSelection);

	return true;
}
bool main_menu::updateSound()
{
	return true;
}

