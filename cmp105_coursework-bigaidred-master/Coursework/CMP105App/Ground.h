#pragma once

#include "Framework/GameObject.h"
#include "Framework/Collision.h"

class Ground : public GameObject
{
public:
	//Public ground functions and variables (Constructor, destructor, etc)
	Ground();
	~Ground();

	void update(float dt);

private:
	//Private functions and variables (Textures, etc.)

	sf::Texture groundTexture;

};