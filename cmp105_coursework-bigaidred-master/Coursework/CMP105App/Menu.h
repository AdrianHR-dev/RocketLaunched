#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include "Background.h"
#include "Button.h"
#include "Cursor.h"
#include "Framework/Collision.h"

class Menu : public BaseLevel
{

public:
	Menu(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud);
	~Menu();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render();

private:
	//Initialising private variables

	//3 Button objects created
	Button startButton;
	Button helpButton;
	Button creditsButton;

	Background titleBackground;
	Cursor cursor;
};

