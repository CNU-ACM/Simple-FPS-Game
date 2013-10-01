#include "main_game.h"

void main_game::initializeGraphics()
{
	printf("main game-initializeGraphics\n"); 
}
void main_game::initializeLogic()
{
	printf("main game-initializeLogic\n");
}
void main_game::initializeSound()
{
	printf("main game-initializeSound\n");
}

bool main_game::updateGraphics()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	{
		glRotatef(45.0f, 1.0f, 1.0f, 0.0f);
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_TRIANGLE_STRIP);
		{
			glVertex3f(-1.0f, -1.0f, 0.0f);
			glVertex3f(-1.0f, 1.0f, 0.0f);
			glVertex3f(1.0f, -1.0f, 0.0f);
			glVertex3f(1.0f, 1.0f, 0.0f);
		}
		glEnd();
	}
	glPopMatrix();
	return true;
}
bool main_game::updateSound()
{
	return true;
}

bool main_game::updateLogic()
{
	return true;
}