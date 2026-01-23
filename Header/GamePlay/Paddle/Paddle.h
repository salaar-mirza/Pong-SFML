#pragma once
#include <SFML/Graphics.hpp>

namespace Gameplay
{
	class Paddle
	{
	public:
		Paddle(float position_x, float position_y);
		~Paddle();

		void initialize();
		void update(float delta_time, bool move_up_key_pressed, bool move_down_key_pressed);
		void render(sf::RenderWindow* game_window);
		void reset(float position_x, float position_y);
		sf::RectangleShape getPaddleSprite();

	private:
		const float paddleSpeed = 400.0f;
		const float paddle_width = 20.0f;
		const float paddle_height = 140.0f;
		const float topBoundary = 20.0f;
		const float bottomBoundary = 700.0f;

		sf::RectangleShape paddle_sprite;

		void movePaddle(float delta_time, bool move_up_key_pressed, bool move_down_key_pressed);
	};
}
