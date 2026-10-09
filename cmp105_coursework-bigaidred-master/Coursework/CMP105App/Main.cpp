// Main
// Entry point of the application.
// Handles window creation and window events.
// Contains the game loop, updates input class and contains the level objects.
// @author Paul Robertson

#include <iostream>
#include "Tutorial.h"
#include "Level.h"
#include "Menu.h"
#include "Win.h"
#include "Credits.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"

void windowProcess(sf::RenderWindow* window, Input* in)
{
	// Handle window events.
	sf::Event event;
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::Resized:
			window->setView(sf::View(sf::FloatRect(0.f, 0.f, (float)event.size.width, (float)event.size.height)));
			break;
		case sf::Event::KeyPressed:
			// update input class
			in->setKeyDown(event.key.code);
			break;
		case sf::Event::KeyReleased:
			//update input class
			in->setKeyUp(event.key.code);
			break;
		case sf::Event::MouseMoved:
			//update input class
			in->setMousePosition(event.mouseMove.x, event.mouseMove.y);
			break;
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				//update input class
				in->setLeftMouse(Input::MouseState::PRESSED);
			}
			else if (event.mouseButton.button == sf::Mouse::Right)
			{
				in->setRightMouse(Input::MouseState::PRESSED);
			}
			break;
		case sf::Event::MouseButtonReleased:
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				//update input class
				in->setLeftMouse(Input::MouseState::UP);
			}
			else if (event.mouseButton.button == sf::Mouse::Right)
			{
				in->setRightMouse(Input::MouseState::UP);
			}
			break;
		default:
			// don't handle other events
			break;
		}
	}
}

int main()
{
	//Create the window
	sf::RenderWindow window(sf::VideoMode(700, 700), "CMP105_Coursework");

	// Initialise input, level objects, audio manager and menu objects
	AudioManager audioManager;
	Input input;
	GameState gameState;
	Tutorial tutorial(&window, &input, &gameState, &audioManager);
	Level level(&window, &input, &gameState, &audioManager);
	Menu menu(&window, &input, &gameState, &audioManager);
	Win winScreen(&window, &input, &gameState, &audioManager);
	Credits credits(&window, &input, &gameState, &audioManager);
	
	//Gamestate set to menu for game start
	gameState.setCurrentState(State::MENU);


	// Initialise objects for delta time
	sf::Clock clock;
	float deltaTime;

	// Game Loop
	while (window.isOpen())
	{
		//Process window events
		windowProcess(&window, &input);

		// Calculate delta time. How much time has passed 
		// since it was last calculated (in seconds) and restart the clock.
		deltaTime = clock.restart().asSeconds();

		switch (gameState.getCurrentState())
		{
			//Menu game state
		case(State::MENU):
		{
			//Call game loop functions for menu
			menu.handleInput(deltaTime);
			menu.update(deltaTime);
			menu.render();

		}; break;

		//Level game stateS
		case(State::LEVEL):
		{
			//Call game loop functions (handleInput, update and render) when game is in LEVEL state
			level.handleInput(deltaTime);
			level.update(deltaTime);
			level.render();
		}; break;
		//Credits game state
		case(State::CREDITS):
		{
			credits.handleInput(deltaTime);
			credits.update(deltaTime);
			credits.render();
		}; break;

		//Pause game state
		case(State::PAUSE):
		{
			level.handleInput(deltaTime);
			level.render();

		}; break;
		case(State::GAMEOVER):	//Game over status
		{
			level.update(deltaTime);
			level.render();
		}; break;
		case(State::BADEND):
		{
			winScreen.update(deltaTime);
			winScreen.render();
		};	break;
		case(State::GOODEND):
		{
			winScreen.update(deltaTime);
			winScreen.render();
		};	break;
		case(State::TUTORIAL):
		{
			tutorial.handleInput(deltaTime);
			tutorial.update(deltaTime);
			tutorial.render();
		};	break;
		}
		
		// Update input class, handle pressed keys
		// Must be done last.
		input.update();
	}

}
