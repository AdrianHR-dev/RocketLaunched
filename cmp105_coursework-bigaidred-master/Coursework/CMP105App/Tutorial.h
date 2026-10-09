#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "UI.h"
#include "Background.h"
#include "TutMap.h"
#include "Cursor.h"
#include "Player.h"
#include "NPC.h"

class Tutorial : BaseLevel {
public:
	Tutorial(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud);
	~Tutorial();

	void handleInput(float dt) override;
	void update(float dt);
	void render();

private:

	Player tutorialPlayer;
	Background tutorialBackground;
	Cursor tutorialCursor;
	TutMap tutMap;
	UI tutorialUI;
	NPC tutorialNPC;

};