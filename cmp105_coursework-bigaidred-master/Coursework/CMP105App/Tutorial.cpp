#include "Tutorial.h"

Tutorial::Tutorial(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	//INITIALISING OBJECTS 

	//Player input and window set
	tutorialPlayer.setInput(input);
	tutorialPlayer.setWindow(window);

	tutorialPlayer.setPosition(sf::Vector2f(100, 536));	//Player position

	//NPC's input and stance set
	tutorialNPC.setInput(input);

	//Cursor input and window set
	tutorialCursor.setInput(input);
	tutorialCursor.setWindow(window);

	//Hides cursor for new cursor texture to show
	window->setMouseCursorVisible(false);

}

Tutorial::~Tutorial()
{

}

// handle user input
void Tutorial::handleInput(float dt)
{
	tutorialPlayer.handleInput(dt);
	tutorialCursor.handleInput(dt);
}

// Update win screen objects
void Tutorial::update(float dt)
{
	tutorialUI.setScene(0);	//UI scene number resets if tutorial incase tutorial is reentered later in the game

	//Objects updated
	tutorialUI.update(dt);
	tutorialPlayer.update(dt, audio, gameState, &tutorialUI);
	tutorialCursor.update(dt);
	tutorialBackground.update(dt, gameState, 0);
	tutorialNPC.update(dt, 0);

	//COLLISION CHECKS
	
	//TILE MAP COLLISIONS
	for (GameObject tile : *tutMap.getLevel())
	{
		if (tile.isCollider())
		{
			if (Collision::checkBoundingBox(&tile, &tutorialPlayer) && tile.isCollider())
			{
				tutorialPlayer.collisionResponse(&tile, audio);
			}

			if (Collision::checkBoundingBox(&tile, tutorialCursor.getPosition()))
			{
				tutorialCursor.collisionResponse(NULL, audio);
			}
		}
	}

	//PLAYER - CURSOR EXPLOSION COLLISION
	if (Collision::checkBoundingBox(&tutorialPlayer, &tutorialCursor) && tutorialCursor.getTime() < dt * 2)	//Checks for cursor - player collision, only possible when explosion occurs
	{
		tutorialPlayer.setIsFalling(true);
		tutorialPlayer.collisionResponseExplosion(NULL, dt, tutorialCursor.getX(), tutorialCursor.getY());

	}

	//PLAYER - NPC COLLISION
	if (Collision::checkBoundingBox(&tutorialPlayer, &tutorialNPC))
	{
		tutorialNPC.collisionResponse(NULL, 0, gameState);
	}

}



// Render win screen scene
void Tutorial::render()
{
	beginDraw();

	window->draw(tutorialBackground);
	tutMap.render(window);
	window->draw(tutorialNPC);
	window->draw(tutorialPlayer);
	window->draw(*tutorialPlayer.getLauncher());
	window->draw(tutorialCursor);
	window->draw(*tutorialUI.getLocationText());
	for (int counter = 0; counter < 8; counter++)
	{
		window->draw(*tutorialUI.getTutorialText(counter));
	}

	endDraw();
}

