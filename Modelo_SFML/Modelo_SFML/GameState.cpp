#include <sstream>
#include "GameState.h"
#include "DEFINITIONS.h"
#include <iostream>

GameState::GameState()
{
}


GameState::~GameState()
{
}

GameState::GameState(GameDataRef data) : _data(data)
{
}

void GameState::Init()
{
	gameState = STATE_PLAYING;
	turn = PLAYER_PIECE;
	this->_data->assets.LoadTexture("Pause Button", PAUSE_BUTTON);
	_background.setTexture(this->_data->assets.GetTexture("Background"));
	_pauseButton.setTexture(this->_data->assets.GetTexture("Pause Button"));

	_pauseButton.setPosition(this->_data->window.getSize().x - _pauseButton.getLocalBounds().width,
		_pauseButton.getPosition().x);

	//Also starts the SpaceShip(Player) of the game
	Player1 = new SpaceShip(_data, PLAYER_ONE_ID);
	Player2 = new SpaceShip(_data, PLAYER_TWO_ID);

	//setting this for easier usability.
	socket = _data->network.GetSocket();
}

void GameState::HandleInput()
{
	sf::Event event;
	while (this->_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->_data->window.close();
		}
		if (this->_data->input.IsSpriteClicked(this->_pauseButton,
			sf::Mouse::Left, this->_data->window))
		{
			std::cout << "Pause game!";
		}
		if (event.type == sf::Event::GainedFocus)
			gameFocused = true;
		if (event.type == sf::Event::LostFocus)
			gameFocused = false;
	}
}

void GameState::Update(float dt)
{
	if (gameFocused)
	{
		this->Player1->Update(dt);
		this->Player2->Update(dt);
	}
	//for the connection!
	sf::Packet packet;

	sf::Vector2f playerPosition;
	playerPosition = Player1->GetPosition();

	packet << playerPosition.x <<
		playerPosition.y;
	this->socket->send(packet);
	//In order to recieve the info from whatever connected here...
	this->socket->receive(packet);
	sf::Vector2f opponentPosition;

	if (packet >> opponentPosition.x >> opponentPosition.y)
	{
		Player2->SetPosition(opponentPosition);
	}
}

void GameState::Draw(float dt)
{
	this->_data->window.clear();

	this->_data->window.draw(this->_background);
	this->_data->window.draw(this->_pauseButton);
	this->Player1->Draw();
	this->Player2->Draw();

	this->_data->window.display();
}
