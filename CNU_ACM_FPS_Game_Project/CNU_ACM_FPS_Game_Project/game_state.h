#ifndef _GAME_STATE_H_
#define _GAME_STATE_H_

#include <SFML\Graphics.hpp>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

typedef enum
{
	logic = 1,
	graphics = 2,
	sound = 3
}finished_threads;

class game_state
{
public:
	bool paused;
	game_state()
	{
	};
	virtual void initialize()
	{
		this->initializeLogic();
		this->initializeGraphics();
		this->initializeSound();
	};
	virtual bool updateLogic()
	{
		return true;
	};
	virtual bool updateGraphics()
	{
		return true;
	}
	virtual bool updateSound()
	{
		return true;
	}
	virtual ~game_state()
	{
	};
protected:
	unsigned char threadsFinished;

	virtual void initializeLogic()
	{
	}
	virtual void initializeGraphics()
	{
	}
	virtual void initializeSound()
	{
	}
private:
};

extern game_state* current_state;
extern 	sf::RenderWindow mainWindow;

#endif