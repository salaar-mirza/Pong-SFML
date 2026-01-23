#pragma once

namespace sf {
	class RenderWindow;
}

namespace Events{
	class EventManager;
}

namespace UI{
	class UIService;
}



namespace Gameplay
{
	// Forward-declare types within the Gameplay namespace
	class Ball;
	class Paddle;
	class Boundary;
	
	class GameplayManager
	{
	public:
		GameplayManager(Events::EventManager* event_manager);
		~GameplayManager();

		void initialize();
		void update(float delta_time);
		void render(sf::RenderWindow* game_window);
		void resetPlayers();
		void updateScore();

	private:
		const float player1_position_x = 40.0f;
		const float player1_position_y = 300.0f;

		const float player2_position_x = 1210.0f;
		const float player2_position_y = 300.0f;

		Ball* ball;
		Paddle* player1;
		Paddle* player2;
		Boundary* boundary;

		Events::EventManager* event_manager;
		UI::UIService* ui_service;
	};
}
