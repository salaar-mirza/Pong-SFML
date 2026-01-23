#include "../../Header/Core/GameWindowManager.h"

namespace Core
{
	GameWindowManager::GameWindowManager()
	{
		game_window = nullptr;
	}

	GameWindowManager::~GameWindowManager()
	{
		delete game_window;
	}

	void GameWindowManager::initialize()
	{
		game_window = new sf::RenderWindow();
		createGameWindow();
	}

	void GameWindowManager::createGameWindow()
	{
		game_window->create(sf::VideoMode(game_window_width, game_window_height), game_title);
	}

	bool GameWindowManager::isGameRunning()
	{
		return game_window->isOpen();
	}

	sf::RenderWindow* GameWindowManager::getGameWindow()
	{
		return game_window;
	}

	void GameWindowManager::clearGameWindow()
	{
		game_window->clear(sf::Color(200, 50, 50, 255));
	}

	void GameWindowManager::displayGameWindow()
	{
		game_window->display();
	}
}
