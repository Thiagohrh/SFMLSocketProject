#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "SpaceShip.h"
#include "NetworkManager.h"
#include <SFML/Network.hpp>
class GameState :public State
{
public:
	GameState();
	~GameState();
	GameState(GameDataRef data);

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataRef _data;
	sf::Sprite _background;
	sf::Sprite _pauseButton;

	int turn;
	int gameState;

	SpaceShip *Player1, *Player2;

	//main used socket.
	sf::TcpSocket *socket;
	bool gameFocused = true;
};

