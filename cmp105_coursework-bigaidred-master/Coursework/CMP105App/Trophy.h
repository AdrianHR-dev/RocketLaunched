#pragma once

#include "Framework/GameObject.h"

class Trophy : public GameObject
{
public:

	Trophy();
	~Trophy();

	void update(float dt);

private:

	sf::Texture trophyTexture;
};