#pragma once

#include "Framework/GameObject.h"
#include "Framework/Input.h"
#include "Framework/Collision.h"
#include "Framework/Animation.h"
#include "Cursor.h"

//Enum class for button types
enum class Type {PLAY,HELP,CREDITS};

class Button : public GameObject
{
public: 
	Button();
	~Button();

	void update(float dt);

	void collisionResponse(GameObject* collider);

	Type getType();
	void setType(Type buttonType);


private:	//Private button variables created (Textures)
	sf::Texture startTexture;
	sf::Texture helpTexture;
	sf::Texture creditsTexture;

	Type type;

protected:

	//Two animations for button created, idle and selected
	Animation idle;
	Animation select;

};
