#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace Gameplay{
	class Paddle;
}

namespace Gameplay
{
	class Ball
	{
	public:
		Ball();
		~Ball();

		void initialize();
		void update(float delta_time, Paddle* player1, Paddle* player2);
		void render(sf::RenderWindow* game_window);
		void reset();

		bool isLeftCollisionOccurred();
		void updateLeftCollisionState(bool value);

		bool isRightCollisionOccurred();
		void updateRightCollisionState(bool value);

	private:
		const float ball_speed = 500.0f;
		sf::Vector2f velocity;

		sf::Texture pong_ball_texture;
		sf::Sprite pong_ball_sprite;

		const std::string texture_path = "Assets/Textures/Ball.png";

		const float scale_x = 0.06f;
		const float scale_y = 0.06f;

		const float position_x = 615.0f;
		const float position_y = 335.0f;

		const float top_boundary = 20.0f;
		const float bottom_boundary = 700.0f;

		const float left_boundary = 0.0f;
		const float right_boundary = 1280.0f;

		const float center_position_x = 615.0f;
		const float center_position_y = 325.0f;

		bool had_left_collison = false;
		bool had_right_collison = false;

		void loadTexture();
		void initializeVariables();
		void move(float delta_time);
		void handlePaddleCollision(Paddle* player1, Paddle* player2);
		void handleBoundaryCollision();
		void handleOutOfBoundCollision();
	};
}
