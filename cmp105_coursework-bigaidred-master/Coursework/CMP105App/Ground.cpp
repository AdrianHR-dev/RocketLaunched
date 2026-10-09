#include "Ground.h"

Ground::Ground()
{
	setPosition(sf::Vector2f(0.0f, 600.0f));
	setSize(sf::Vector2f(700.0f, 100.0f));
	setCollisionBox(0,0, 700, 100);

	groundTexture.loadFromFile("gfx/Ground.png");
	setTexture(&groundTexture);
}

Ground::~Ground()
{

}

void Ground::update(float dt)
{

}