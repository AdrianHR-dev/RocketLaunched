#pragma once

#include "Framework/GameObject.h"
#include "Framework/GameState.h"
#include "Framework/AudioManager.h"

//Class to update background scenery based on game state
class Background : public GameObject
{
public:

	Background();
	~Background();

	void update(float dt, GameState* state, int scene);

private:

	sf::Texture menuTexture;	//Object for menu texture

	sf::Texture creditsTexture; //Texture to display credits screen

	//Objects for level backgrounds
	sf::Texture backgroundTexture;
	sf::Texture spaceTexture;

	//Objects for end screens

	sf::Texture winMain;
	sf::Texture winBaby1;
	sf::Texture winBaby2;
};