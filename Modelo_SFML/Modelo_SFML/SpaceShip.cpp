#include "SpaceShip.h"
#include "DEFINITIONS.h"
#include <math.h>

SpaceShip::SpaceShip()
{
}


SpaceShip::~SpaceShip()
{
}

SpaceShip::SpaceShip(GameDataRef data, int player_id) : _data(data)
{
	InitShape();
	playerID = player_id;
}

void SpaceShip::Init()
{
}

void SpaceShip::HandleInput()
{
	if (playerID != PLAYER_ONE_ID)
		return;
	//Window bounds collision
	//In order to move the character...
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->shape.move(- this->MovementSpeed, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->shape.move(this->MovementSpeed, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->shape.move(0.f, -this->MovementSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->shape.move(0.f, this->MovementSpeed);
	}

	this->shape.rotate(1.0f);
	
}

void SpaceShip::Update(float dt)
{
	HandleInput();
}

void SpaceShip::Draw()
{
	_data->window.draw(this->shape);
}

void SpaceShip::InitShape()
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(100.f, 100.f));
	this->shape.setPosition(sf::Vector2f(this->_data->window.getSize().x / 2,
		this->_data->window.getSize().y / 2));
	this->shape.setOrigin(sf::Vector2f(50.f,50.f));
}