#include "../../Header/Event/EventManager.h"

#include "../../Header/GamePlay/GmameplayManager.h"

using namespace sf;


namespace Gameplay 
{
	GameplayManager::GameplayManager(Events::EventManager* manager)
	{
		GameplayManager::initialize();

	}


	void GameplayManager::initialize()
	{
		    boundary = new Boundary();
			ball = new Ball();
			player1 = new Paddle(player1_position_x, player1_position_y);
			player2 = new Paddle(player2_position_x, player2_position_y);
		    ui_service = new UIService();

	}


	
	void GameplayManager::update(float delta_time)
	{
		ball->update(delta_time,player1,player2);

		player1->update(delta_time, event_manager->isKeyPressed(Keyboard::W),
			event_manager->isKeyPressed(Keyboard::S));
		player2->update(delta_time, event_manager->isKeyPressed(Keyboard::Up),
			event_manager->isKeyPressed(Keyboard::Down));

		UpdateScore();
		ui_service->update();

	}

	void GameplayManager::UpdateScore() {
		// Left side out - Player 2 scores!
		if (ball->isLeftCollisionOccurred()) {
			ui_service->incrementPlayer2Score();
			ball->updateLeftCollisionState(false);
			resetPlayers(); 
		}

		// Right side out - Player 1 scores!
		if (ball->isRightCollisionOccurred()) {
			ui_service->incrementPlayer1Score();
			ball->updateRightCollisionState(false);
			resetPlayers();  
		}
	}

	void GameplayManager::resetPlayers() {
		player1->reset(player1_position_x, player1_position_y);
		player2->reset(player2_position_x, player2_position_y);
	}


	void GameplayManager::render(RenderWindow* game_window)
	{
		boundary->render(game_window);
		ball->render(game_window);
		player1->render(game_window);
		player2->render(game_window);
		ui_service->render(game_window);

	}



}
