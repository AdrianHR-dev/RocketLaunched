#pragma once

#include "Framework/GameObject.h"
#include "Framework/GameState.h"
#include "Framework/Collision.h"
#include "Framework/Animation.h"

enum class Stance {IDLE, TALKING};

class NPC : public GameObject
{
public:

	NPC();
	~NPC();

	void update(float dt, int scene);
	void collisionResponse(GameObject* collider, int scene, GameState* state);

	//Text getter
	sf::Text* getSpeech()
	{
		return &speech;
	};

	//Stance setter
	void setStance(Stance stance);

	//Talktime getter
	float getTalkTime();

private:

	sf::Font npcFont;
	sf::Text speech;

	sf::Texture npcTexture;

	Stance npcStance;

	float talkTime;	//Variable to keep track of NPC's speech length

protected:
	Animation idle;
	Animation talk;

};
