// Check if the header has been defined already.
#ifndef _GAME_STATE_H_
// If not, define it.
#define _GAME_STATE_H_

// Include the graphics header for window usage.
#include <SFML\Graphics.hpp>
#include <SFML\OpenGL.hpp>

/**
  * The base game state class.  Game states should extend this class
  * to help transition between menus, gameplay, etc.
  */
class game_state
{
public:
	/**
	  * A boolean indicating whether the current state is paused or not. 
	  */
	bool paused;
	/**
	  *  A pointer to the window object.
	  */
	sf::RenderWindow* mainWindow;
	/**
	  * The default constructor.
	  */
	game_state(sf::RenderWindow* mainWindow)
	{
		// Set the main window pointer.
		this->mainWindow = mainWindow;
	};
	/**
	  * The initialize method.  Calls the other initialize methods for logic, graphics
	  * and sound.
	  */
	virtual void initialize()
	{
		// Initializes the logic.
		this->initializeLogic();
		// Initializes the graphics.
		this->initializeGraphics();
		// Initializes the sound.
		this->initializeSound();
	};
	/**
	  * The logic update method.  Updates the game's logic.
	  * Needs to be overridden!
	  */
	virtual bool updateLogic()
	{
		// Return true on success.
		return true;
	};
	/**
	  * The graphics update method.  Updates the game's graphcs.
	  * Needs to be overridden!
	  */
	virtual bool updateGraphics()
	{
		// Return true on success.
		return true;
	}
	/**
	  * The sound update method.  Updates the game's sounds.
	  * Needs to be overridden!
	  */
	virtual bool updateSound()
	{
		// Return true on success.
		return true;
	}
	/**
	  * The default deconstructor for the class.
	  */
	virtual ~game_state()
	{
	};
protected:
	/**
	  * Initializes the logic for the game.  Needs to be
	  * overridden.
	  */
	virtual void initializeLogic()
	{
	};
	/**
	  * Initializes the graphics for the game.  Needs to be
	  * overridden.
	  */
	virtual void initializeGraphics()
	{
	};
	/**
	  * Initializes the sound for the game.  Needs to be
	  * overridden.
	  */
	virtual void initializeSound()
	{
	};
private:
	// No private sections for this class.
};

/**
 * The current game state.
 */
extern game_state* current_state;

// End the definition for the game state header.
#endif