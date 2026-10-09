#include "Menu.h"

Menu::Menu(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	cursor.setInput(input);

	startButton.setType(Type::PLAY);
	helpButton.setType(Type::HELP);
	creditsButton.setType(Type::CREDITS);

	//Title music loaded and played
	audio->addMusic("sfx/TitleTheme.ogg", "title");
	audio->playMusicbyName("title");
	audio->getMusic()->setLoop(true);	//Music for menu is looped

}

Menu::~Menu()
{


}

void Menu::update(float dt)
{
	//If the title music is not playing, it will begin to play again (eg. player returns here after getting and ending, loses, etc.)
	if (audio->getMusic()->getStatus() == sf::SoundSource::Stopped)
	{
		audio->playMusicbyName("title");
	}

	cursor.update(dt);
	startButton.update(dt);
	helpButton.update(dt);
	creditsButton.update(dt);

	titleBackground.update(dt, gameState, 0);
	
	if (Collision::checkBoundingBox(&startButton, cursor.getPosition()))	//Cursor collision with start button
	{
		startButton.collisionResponse(NULL);
		if (input->isLeftMouseDown())
		{
			audio->stopAllMusic();	//Title music stopped
			input->setLeftMouse(Input::MouseState::UP);	//Reset mouse state
			gameState->setCurrentState(State::LEVEL);	//Update game state
		}
	}

	else if (Collision::checkBoundingBox(&helpButton, cursor.getPosition()))	//Cursor collision with start button
	{
		helpButton.collisionResponse(NULL);
		if (input->isLeftMouseDown())
		{
			audio->stopAllMusic();	//Title music stopped
			input->setLeftMouse(Input::MouseState::UP);	//Reset mouse state
			gameState->setCurrentState(State::TUTORIAL);	//Update game state
		}
	}

	else if (Collision::checkBoundingBox(&creditsButton, cursor.getPosition()))	//Cursor collision with start button
	{
		creditsButton.collisionResponse(NULL);
		if (input->isLeftMouseDown())
		{
			audio->stopAllMusic();	//Title music stopped
			input->setLeftMouse(Input::MouseState::UP);	//Reset mouse state
			gameState->setCurrentState(State::CREDITS);	//Update game state
		}
	}
}

void Menu::handleInput(float dt)
{
	cursor.handleInput(dt);
}

//Render all objects on main menu
void Menu::render()
{
	beginDraw();

	window->draw(titleBackground);
	window->draw(startButton);
	window->draw(helpButton);
	window->draw(creditsButton);
	window->draw(cursor);

	endDraw();
}