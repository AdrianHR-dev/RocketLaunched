#include "Win.h"
#include <iostream>

Win::Win(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	//INITIALISING OBJECTS 

	//Hides cursor for new cursor texture to show
	window->setMouseCursorVisible(false);

	//Dialogue audio for end screen added
	audio->addSound("sfx/Winner.ogg", "goodEnding");
	audio->addSound("sfx/BabyWin1.ogg", "badEnding1");
	audio->addSound("sfx/BabyWin2.ogg", "badEnding2");
	audio->addSound("sfx/BabyWin3.ogg", "badEnding3");

	//Audio stage value initialised
	audioStage = 1;

}

Win::~Win()
{

}

// handle user input
void Win::handleInput(float dt)
{
	
}

// Update win screen objects
void Win::update(float dt)
{
	winBackground.update(dt, gameState, audioStage);	//Background updated
	
	//First switch statement determines which ending player has reached
	switch (gameState->getCurrentState())
	{
	//Good ending plays out
	case(State::GOODEND):
	{
		//If audio not already playing, it will begin to play
		if (audio->getSound("goodEnding")->getStatus() == sf::SoundSource::Stopped && audioStage == 1)
		{
			audio->playSoundbyName("goodEnding");	//Dialogue begins to play
		}

		//Once sound begins, audiostage value updated to allow dialogue to progress smoothly
		else
		{
			audioStage = 2;
		}

		//If audio has finished, player returns to main menu
		if (audio->getSound("goodEnding")->getStatus() == sf::SoundSource::Stopped)
		{
			audioStage = 1;	//Audio stage value reset
			gameState->setCurrentState(State::MENU);
		};
	};	break;
	//Bad ending plays out
	case(State::BADEND):
	{
		switch (audioStage)
		{
		case(1):
		{
			audio->playSoundbyName("badEnding1");	//Dialogue begins to play
			audioStage = 2;	//Audio stage value updated to allow audio files to transition
		};	break;
		case(2):
		{
			if (audio->getSound("badEnding1")->getStatus() == sf::SoundSource::Stopped)
			{
				audio->playSoundbyName("badEnding2");	//Second bit of dialogue begins to play
				audioStage = 3;
			};
		};	break;
		case(3):
		{
			if (audio->getSound("badEnding2")->getStatus() == sf::SoundSource::Stopped)
			{
				audio->playSoundbyName("badEnding3");	//Second bit of dialogue begins to play
				audioStage = 4;
			};
		};	break;
		case(4):
		{
			if (audio->getSound("badEnding3")->getStatus() == sf::SoundSource::Stopped)
			{
				audioStage = 1;	//Audio stage value reset
				gameState->setCurrentState(State::MENU);
			};
		};	break;
		}
	}
	}
}



// Render win screen scene
void Win::render()
{
	beginDraw();

	window->draw(winBackground);

	endDraw();
}

