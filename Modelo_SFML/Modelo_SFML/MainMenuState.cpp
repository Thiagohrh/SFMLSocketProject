#include "MainMenuState.h"
#include <sstream>
#include "DEFINITIONS.h"
#include <iostream>
#include "GameState.h"


MainMenuState::MainMenuState(GameDataRef data) : _data(data)
{
}


MainMenuState::~MainMenuState()
{
}

void MainMenuState::Init()
{
	this->_data->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
	this->_data->assets.LoadTexture("Play Button", MAIN_MENU_PLAY_BUTTON);
	this->_data->assets.LoadTexture("Play Button Outer", MAIN_MENU_PLAY_BUTTON_OUTER);
	this->_data->assets.LoadTexture("Game Title", MAIN_MENU_TITLE_PATH);

	this->_background.setTexture(this->_data->assets.GetTexture("Background"));
	this->_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
	this->_playButtonOuter.setTexture(this->_data->assets.GetTexture("Play Button Outer"));
	this->_title.setTexture(this->_data->assets.GetTexture("Game Title"));

	this->_playButton.setPosition((SCREEN_WIDTH / 2) - this->_playButton.getGlobalBounds().width / 2, 
		((SCREEN_HEIGHT / 2) - this->_playButton.getGlobalBounds().height / 2));

	this->_playButtonOuter.setPosition((SCREEN_WIDTH / 2) - this->_playButtonOuter.getGlobalBounds().width / 2,
		((SCREEN_HEIGHT / 2) - this->_playButtonOuter.getGlobalBounds().height / 2));

	this->_title.setPosition((SCREEN_WIDTH / 2) - this->_title.getGlobalBounds().width / 2,
		this->_title.getGlobalBounds().height * 0.1);
	//Setting up the buttons to handle the type of connection...
	this->_data->assets.LoadTexture("Server Button", MAIN_MENU_SERVER_BUTTON);
	this->_data->assets.LoadTexture("Client Button", MAIN_MENU_CLIENT_BUTTON);

	this->_server.setTexture(this->_data->assets.GetTexture("Server Button"));
	this->_client.setTexture(this->_data->assets.GetTexture("Client Button"));

	this->_server.setPosition((SCREEN_WIDTH / 3) - this->_server.getGlobalBounds().width / 2,
		((SCREEN_HEIGHT / 1.5) - this->_server.getGlobalBounds().height / 2));
	this->_client.setPosition((SCREEN_WIDTH / 1.5) - this->_client.getGlobalBounds().width / 2,
		((SCREEN_HEIGHT / 1.5) - this->_server.getGlobalBounds().height / 2));
}

void MainMenuState::HandleInput()
{
	sf::Event event;
	while(this->_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type) 
		{
			this->_data->window.close();
		}
		if (this->_data->input.IsSpriteClicked(this->_playButton,
			sf::Mouse::Left, this->_data->window))
		{
			this->_data->machine.AddState(StateRef(new GameState(_data)), true);
		}

		//Setting the inner workings of teh server and client buttons...
		if (this->_data->input.IsSpriteClicked(this->_server,
			sf::Mouse::Left, this->_data->window))
		{
			this->_data->network.SetIfServer(true);
			this->_data->machine.AddState(StateRef(new GameState(_data)), true);
		}
		if (this->_data->input.IsSpriteClicked(this->_client,
			sf::Mouse::Left, this->_data->window))
		{
			this->_data->network.SetIfServer(false);
			this->_data->machine.AddState(StateRef(new GameState(_data)), true);
		}
	}
}

void MainMenuState::Update(float dt)
{
	
}

void MainMenuState::Draw(float dt)
{
	this->_data->window.clear();
	this->_data->window.draw(this->_background);
	this->_data->window.draw(this->_playButton);
	this->_data->window.draw(this->_playButtonOuter);
	this->_data->window.draw(this->_title);
	this->_data->window.draw(this->_client);
	this->_data->window.draw(this->_server);

	this->_data->window.display();
}
