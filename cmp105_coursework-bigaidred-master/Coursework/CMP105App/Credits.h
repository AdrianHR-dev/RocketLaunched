#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Background.h"

class Credits : BaseLevel {
public:
	Credits(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud);
	~Credits();

	void handleInput(float dt) override;
	void update(float dt);
	void render();

private:

	Background creditsBackground;

};