#include "../../Header/Core/GameLoop.h"
#include "../../Header/Core/GameWindowManager.h"
#include "../../Header/Event/EventManager.h"
#include "../../Header/GamePlay/GameplayManager.h"
#include "../../Header/Utility/TimeService.h"
#include "../../Header/Sounds/SoundManager.h"

namespace Core
{
	GameLoop::GameLoop()
	{
		game_window_manager = nullptr;
		event_manager = nullptr;
		gameplay_manager = nullptr;
		time_service = nullptr;
		sound_manager = nullptr;
	}

	GameLoop::~GameLoop()
	{
		delete game_window_manager;
		delete event_manager;
		delete gameplay_manager;
		delete time_service;
		delete sound_manager;
	}

	void GameLoop::initialize()
	{
		game_window_manager = new GameWindowManager();
		game_window_manager->initialize();

		event_manager = new Events::EventManager();

		gameplay_manager = new Gameplay::GameplayManager(event_manager);
		gameplay_manager->initialize();

		time_service = new Utility::TimeService();
		time_service->initialize();

		sound_manager = new Sounds::SoundManager();
		sound_manager->initialize();
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
		gameplay_manager->render(game_window_manager->getGameWindow());
		game_window_manager->displayGameWindow();
	}

	bool GameLoop::isGameRunning()
	{
		return game_window_manager->isGameRunning();
	}
}
