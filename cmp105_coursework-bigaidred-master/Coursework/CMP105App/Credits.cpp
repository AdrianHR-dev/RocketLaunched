#include "Credits.h"

Credits::Credits(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	//INITIALISING OBJECTS 

	//Hides cursor for new cursor texture to show
	window->setMouseCursorVisible(false);

}

Credits::~Credits()
{

}

// handle user input
void Credits::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		input->setKeyUp(sf::Keyboard::Space);
		gameState->setCurrentState(State::MENU);
	}
}

// Update win screen objects
void Credits::update(float dt)
{
	creditsBackground.update(dt, gameState, 0);
}



// Render win screen scene
void Credits::render()
{
	beginDraw();

	window->draw(creditsBackground);

	endDraw();
}

