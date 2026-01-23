#include "../../Header/GamePlay/Paddle/Paddle.h"

namespace Gameplay
{
	Paddle::Paddle(float position_x, float position_y)
	{
		paddle_sprite.setPosition(sf::Vector2f(position_x, position_y));
	}

	Paddle::~Paddle()
	{
	}

	void Paddle::initialize()
	{
		paddle_sprite.setSize(sf::Vector2f(paddle_width, paddle_height));
	}

	void Paddle::update(float delta_time, bool move_up_key_pressed, bool move_down_key_pressed)
	{
		movePaddle(delta_time, move_up_key_pressed, move_down_key_pressed);
	}

	void Paddle::render(sf::RenderWindow* game_window)
	{
		game_window->draw(paddle_sprite);
	}

	void Paddle::reset(float position_x, float position_y)
	{
		paddle_sprite.setPosition(position_x, position_y);
	}

	sf::RectangleShape Paddle::getPaddleSprite()
	{
		return paddle_sprite;
	}

	void Paddle::movePaddle(float delta_time, bool move_up_key_pressed, bool move_down_key_pressed)
	{
		if (move_up_key_pressed && paddle_sprite.getPosition().y > topBoundary)
		{
			paddle_sprite.move(0, -paddleSpeed * delta_time);
		}
		if (move_down_key_pressed && paddle_sprite.getPosition().y + paddle_sprite.getSize().y < bottomBoundary)
		{
			paddle_sprite.move(0, paddleSpeed * delta_time);
		}
	}
}
