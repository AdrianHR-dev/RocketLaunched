#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Background.h"


class Win : BaseLevel {
public:
	//Win screen constructor and destructor
	Win(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud);
	~Win();

	//Win screen game loop
	void handleInput(float dt) override;
	void update(float dt);
	void render();

private:
	//Background object created
	Background winBackground;

	//Int used to determine which stage the audio track is on in order to update background at the correct time
	int audioStage;

};