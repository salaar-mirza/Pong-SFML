#include "../../Header/GamePlay/GameplayManager.h"
#include "../../Header/GamePlay/Ball/Ball.h"
#include "../../Header/GamePlay/Paddle/Paddle.h"
#include "../../Header/GamePlay/Boundary/Boundary.h"
#include "../../Header/UI/UIService.h"
#include "../../Header/Event/EventManager.h"

namespace Gameplay
{
	GameplayManager::GameplayManager(Events::EventManager* manager)
	{
		event_manager = manager;
		ball = nullptr;
		player1 = nullptr;
		player2 = nullptr;
		boundary = nullptr;
		ui_service = nullptr;
	}

	GameplayManager::~GameplayManager()
	{
		delete ball;
		delete player1;
		delete player2;
		delete boundary;
		delete ui_service;
	}

	void GameplayManager::initialize()
	{
		boundary = new Boundary();
		boundary->initialize();

		ball = new Ball();
		ball->initialize();

		player1 = new Paddle(player1_position_x, player1_position_y);
		player1->initialize();

		player2 = new Paddle(player2_position_x, player2_position_y);
		player2->initialize();

		ui_service = new UI::UIService();
		ui_service->initialize();
	}

	void GameplayManager::update(float delta_time)
	{
		ball->update(delta_time, player1, player2);

		player1->update(delta_time, event_manager->isKeyPressed(sf::Keyboard::W),
			event_manager->isKeyPressed(sf::Keyboard::S));
		player2->update(delta_time, event_manager->isKeyPressed(sf::Keyboard::Up),
			event_manager->isKeyPressed(sf::Keyboard::Down));

		updateScore();
		ui_service->update();
	}

	void GameplayManager::updateScore()
	{
		if (ball->isLeftCollisionOccurred())
		{
			ui_service->incrementPlayer2Score();
			ball->updateLeftCollisionState(false);
			resetPlayers();
		}

		if (ball->isRightCollisionOccurred())
		{
			ui_service->incrementPlayer1Score();
			ball->updateRightCollisionState(false);
			resetPlayers();
		}
	}

	void GameplayManager::resetPlayers()
	{
		player1->reset(player1_position_x, player1_position_y);
		player2->reset(player2_position_x, player2_position_y);
		ball->reset();
	}

	void GameplayManager::render(sf::RenderWindow* game_window)
	{
		boundary->render(game_window);
		ball->render(game_window);
		player1->render(game_window);
		player2->render(game_window);
		ui_service->render(game_window);
	}
}
