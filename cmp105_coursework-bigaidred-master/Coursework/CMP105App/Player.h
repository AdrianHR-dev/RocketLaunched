#pragma once

//Appropriate libraries included: Animation, GameObject, Input, Collision, Launcher
#include "Framework/GameObject.h"
#include "Framework/Input.h"
#include "Framework/Animation.h"
#include "Framework/Collision.h"
#include "Framework/VectorHelper.h"
#include "Framework/GameState.h"
#include "Framework/AudioManager.h"
#include "UI.h"
#include "Launcher.h"

class Player : public GameObject
{
public:
	//Public constructor and destructor for player

	Player();	//dt included to actiavte idle animation immediately
	~Player();

	//Public player functions, accessible from level.cpp
	void update(float dt, AudioManager* audio, GameState* state, UI* ui);
	void handleInput(float dt);

	//Collision response for explosion collision
	void collisionResponseExplosion(GameObject* collider, float dt, float x, float y);	

	//Collision response for the ground
	void collisionResponse(GameObject* collider, AudioManager* audio);

	//Getter and setter for whether or not player is falling
	bool getIsFalling();
	void setIsFalling(bool setFall);

	//Getter and setter for 'baby mode'

	bool getBaby();
	void setBaby(bool babyMode);

	Launcher* getLauncher()
	{
		return &launcher;
	};

protected:

	Animation idle;	//Creates an idle animation
	Animation walk;	//Creates a walk animation
	Animation fall;	//Creates a fall animation

private:
	//Private player variables (Textures, etc)

	sf::Texture playerTexture;	//Create a texture variable for the player
	Launcher launcher;	//Launcher object to follow player

	//Falling calculation variables
	bool isFalling = false;
	float scale;
	sf::Vector2f gravity;


	//Variables used to calculate player's velocity after explosion contact
	sf::Vector2f target;
	sf::Vector2f direction;
	sf::Vector2f launchVelocity;
	float launchSpeed;

	//Bool for 'baby' mode
	bool isBaby;
};
