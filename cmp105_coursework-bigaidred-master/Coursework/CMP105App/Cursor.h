#pragma once

#include "Framework/GameObject.h"
#include "Framework/Input.h"
#include "Framework/Collision.h"
#include "Framework/Animation.h"
#include "Framework/AudioManager.h"

class Cursor : public GameObject
{
public: 
	//Public cursor constructor and destructor
	Cursor();
	~Cursor();

	//Public input and update functions

	void handleInput(float dt);
	void update(float dt);

	void collisionResponse(GameObject* collider, AudioManager* audio);	//Cursor collision response to a surface

	//GETTERS & SETTERS
	float getTime();	//Getter for time status

	float getX();	//Getter for explosion x coord

	float getY();	//Getter for explosion y coord

private:
	//Private texture variable for retina
	sf::Texture cursorTexture;

	bool explosion = false;	//Explosion boolean variable

	//Variable to calculate time to reset explosion status
	float time;

	//Used to store explosion coords
	float x;
	float y;

protected:

	//Creates animation objects for the cursor
	Animation aim;
	Animation explode;

};