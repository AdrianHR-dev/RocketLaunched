#include "Trophy.h"

Trophy::Trophy()
{
	//Trophy variables initialised
	setPosition(sf::Vector2f(50, 150));
	trophyTexture.loadFromFile("gfx/Trophy.png");
	setTexture(&trophyTexture);
	setSize(sf::Vector2f(32,32));
	setCollisionBox(0, 0, 32, 32);
	velocity = (sf::Vector2f(0.0f, 0.05f));
}

Trophy::~Trophy()
{

}

void Trophy::update(float dt)
{
	move(velocity);
	if (getPosition().y < 140 || getPosition().y > 160)
	{
		velocity = -velocity;
	}
}