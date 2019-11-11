#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"

class SpaceShip
{
public:
	SpaceShip();
	~SpaceShip();
	SpaceShip(GameDataRef data, int player_id);

	//Basic functions for initializing, rendering and input parsing.
	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw();

	void InitShape();
	//functions to work online.
	void SetPosition(sf::Vector2f position);
	sf::Vector2f GetPosition();
	sf::Texture GetSprite() 
	{
		return shape.getTexture();
	};

private:
	GameDataRef _data;
	int playerID;
	//Kindda like an area that holds a sprite, collision, and movement system.
	sf::RectangleShape shape;
	float MovementSpeed = 10.f; 
};

