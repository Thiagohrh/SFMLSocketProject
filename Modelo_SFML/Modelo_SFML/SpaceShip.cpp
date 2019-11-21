#include "SpaceShip.h"
#include "DEFINITIONS.h"
#include <sstream>
#include <math.h>

SpaceShip::SpaceShip()
{
}


SpaceShip::~SpaceShip()
{
}

SpaceShip::SpaceShip(GameDataRef data, int player_id) : _data(data)
{
	playerID = player_id;
	InitShape();
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
		//spike.setPosition(shape.getPosition);
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
	if (playerID == PLAYER_ONE_ID)
	{
		this->shape.setFillColor(sf::Color::Blue);
	}
	else
	{
		this->shape.setFillColor(sf::Color::Red);
	}
	this->shape.setSize(sf::Vector2f(100.f, 100.f));
	this->shape.setPosition(sf::Vector2f(this->_data->window.getSize().x / 2,
		this->_data->window.getSize().y / 2));
	this->shape.setOrigin(sf::Vector2f(50.f,50.f));
	//this->shape.setTexture(&_data->assets.GetTexture("Spaceship"));
}

void SpaceShip::SetPosition(sf::Vector2f position)
{
	if (playerID != PLAYER_TWO_ID)
		return;
	this->shape.setPosition(position);
}

sf::Vector2f SpaceShip::GetPosition()
{
	sf::Vector2f position;
	position.x = shape.getPosition().x;
	position.y = shape.getPosition().y;
	return position;
}
