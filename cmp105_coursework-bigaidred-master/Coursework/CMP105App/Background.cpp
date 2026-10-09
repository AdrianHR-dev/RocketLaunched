#pragma once

#include "Background.h"

Background::Background()
{
	setSize(sf::Vector2f(700.0f, 700.0f));
	setPosition(sf::Vector2f(0.0f, 0.0f));

	menuTexture.loadFromFile("gfx/TitleScreen.png");	//Menu texture

	creditsTexture.loadFromFile("gfx/Credits.png");	//Credits texture

	//Background textures for gameplay
	backgroundTexture.loadFromFile("gfx/Background.png");
	spaceTexture.loadFromFile("gfx/SpaceBackground.png");

	//End screens
	winMain.loadFromFile("gfx/WinMain.png");
	winBaby1.loadFromFile("gfx/WinBaby1.png");
	winBaby2.loadFromFile("gfx/WinBaby2.png");
}

Background::~Background()
{

}

void Background::update(float dt, GameState* state, int x)
{
	//Switch statement determines which background to display based on gamestate
	switch (state->getCurrentState())
	{
	case(State::LEVEL):
	{
		//If player is on leve l6 or less, standard background displayed
		if (x <= 6)
		{
			setTexture(&backgroundTexture);
		}
		//Otherwise, space background displayed
		else
		{
			setTexture(&spaceTexture);
		}
	};	break;

	case(State::MENU):
	{
		setTexture(&menuTexture);
	};	break;

	case(State::CREDITS):
	{
		setTexture(&creditsTexture);
	};	break;

	case(State::TUTORIAL):
	{
		setTexture(&backgroundTexture);
	};	break;
	case(State::GOODEND):
	{
		setTexture(&winMain);
	};	break;

	case(State::BADEND):
	{
		//During the bad ending, background is updated multiple times based on the point in the dialogue
		if (x == 3)
		{
			setTexture(&winBaby1);
		}
		else if (x == 4)
		{
			setTexture(&winBaby2);
		}
		else
		{
			setTexture(&winMain);
		}

	};	break;
	}
}
