#include"../../Header/Core/GameWindowManager.h"

namespace Core {

	void GameWindowManager::initialize()
	{
		
		//Allocte memory for the render window object
		game_window = new RenderWindow();
		//Set up window with the configured properties
		createGameWindow();

	}


	void GameWindowManager::createGameWindow()
	{
		//Create the Window with specified dimensions and title
		game_window->create(VideoMode(game_window_width, game_window_hight), game_title);
	     // game_window->create(VideoMode::getDesktopMode(), game_title, Style::Fullscreen);
	}


	bool GameWindowManager::isGameRunning()
	{
		//Return true if window is open, false if closed
		return game_window->isOpen();

	}

	

	RenderWindow* GameWindowManager::getGameWindow() 
	{
		return game_window;
	}

	void GameWindowManager::clearGameWindow()
	{
		game_window->clear(Color(200, 50, 50, 255));

	}

	void GameWindowManager::displayGameWindow()
	{
		return game_window->display();
	}


}