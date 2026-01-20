#include "../../Header/Core/GameLoop.h"

namespace Core {

	void GameLoop::initialize()
	{
		game_window_manager = new GameWindowManager();
		event_manager = new EventManager();
		gameplay_manager = new GameplayManager(event_manager);
		time_service = new TimeService();

		game_window_manager->initialize();
		time_service->initialize();

	}

	bool GameLoop::isGameRunning()
	{
		return game_window_manager->isGameRunning();

	}

	void GameLoop::pollEvent()
	{
		event_manager->pollEvents(game_window_manager->getGameWindow());

	}

	void GameLoop::update()
	{
		time_service->update();
		float delta_time = time_service->getDeltaTime();
		gameplay_manager->update(delta_time);
	}

	void GameLoop::render()
	{
		game_window_manager->clearGameWindow();
		//render ball & Paddles 
		gameplay_manager->render(game_window_manager->getGameWindow());
		game_window_manager->displayGameWindow();
	}

}