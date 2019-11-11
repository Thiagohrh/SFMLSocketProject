#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"


class MainMenuState : public State
{
public:
	MainMenuState(GameDataRef data);
	~MainMenuState();

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
private:
	GameDataRef _data;
	sf::Sprite _background;
	sf::Sprite _playButton;
	sf::Sprite _playButtonOuter;
	sf::Sprite _title;

	//In order to set the connection type...
	sf::Sprite _server;
	sf::Sprite _client;
};

