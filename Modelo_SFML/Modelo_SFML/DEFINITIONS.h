#pragma once
#include <SFML/Graphics.hpp>

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1136

#define SPLASH_STATE_SHOW_TIME 3

#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/Splash Background.png"

#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/res/Main Menu Background.png"
#define GAME_BACKGROUND_FILEPATH "Resources/res/Main Menu Background.png"

#define MAIN_MENU_TITLE_PATH "Resources/res/Game Title.png"

#define MAIN_MENU_PLAY_BUTTON "Resources/res/Play Button.png"
#define MAIN_MENU_PLAY_BUTTON_OUTER "Resources/res/Play Button Outer.png"

#define PAUSE_BUTTON "Resources/res/Pause Button.png"

#define X_PIECE_FILEPATH "Resources/res/X.png"
#define O_PIECE_FILEPATH "Resources/res/O.png"
#define X_WINNING_PIECE_FILEPATH "Resources/res/X Win.png"
#define O_WINNING_PIECE_FILEPATH "Resources/res/O Win.png"

#define X_PIECE 8
#define O_piece 0
#define EMPTY_PIECE -1
#define PLAYER_PIECE X_PIECE
#define AI_PIECE O_PIECE

#define STATE_PLAYING 98
#define STATE_PAUSED 97
#define STATE_WON 96
#define STATE_LOSE 95
#define STATE_PLACING_PIECE 94
#define STATE_AI_PLAYING 93
#define STATE_DRAW 92

#define PLAYER_ONE_ID 0
#define PLAYER_ONE_SPAWN_X 0
#define PLAYER_ONE_SPAWN_Y 0

#define PLAYER_TWO_ID 1
#define PLAYER_TWO_SPAWN_X 0
#define PLAYER_TWO_SPAWN_Y 0

//buttons to set the connection type
#define MAIN_MENU_CLIENT_BUTTON "Resources/res/button_client.png"
#define MAIN_MENU_SERVER_BUTTON "Resources/res/button_server.png"

class DEFINITIONS
{
public:
	DEFINITIONS();
	~DEFINITIONS();

};

