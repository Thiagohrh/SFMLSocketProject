#include "MainMenuState.h"
#include <sstream>
#include "DEFINITIONS.h"
#include <iostream>


MainMenuState::MainMenuState(GameDataRef data)
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

}
