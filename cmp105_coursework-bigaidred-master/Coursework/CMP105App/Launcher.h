#pragma once

#include "Framework/GameObject.h"
#include "Framework/Input.h"
#include "Framework/Animation.h"

class Launcher : public GameObject
{

public:
	//Public launcher functions
	Launcher();
	~Launcher();

	void update(float dt);
	void followPlayer(GameObject* player, Input* input);

private:
	//Private launcher variables and functions

	sf::Texture launcherTexture;	//Create variable for launcher texture
	Animation idleLauncher;

};
