#include <Windows.h>
#include <stdio.h>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

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

	mainWindow.create(sf::VideoMode(800, 600), "ACM FPS Game");
	mainWindow.setVerticalSyncEnabled(true);

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

		mainWindow.display();
	}

	return 0;
}