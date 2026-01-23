#include "../../Header/GamePlay/Ball/Ball.h"
#include "../../Header/GamePlay/Paddle/Paddle.h"
#include "../../Header/Sounds/SoundManager.h"
#include <stdexcept>

namespace Gameplay
{
	Ball::Ball()
	{
		velocity = sf::Vector2f(ball_speed, ball_speed);
	}

	Ball::~Ball()
	{
	}

	void Ball::initialize()
	{
		loadTexture();
		initializeVariables();
	}

	void Ball::loadTexture()
	{
		if (!pong_ball_texture.loadFromFile(texture_path))
		{
			throw std::runtime_error("Failed to load ball texture!");
		}
	}

	void Ball::initializeVariables()
	{
		pong_ball_sprite.setTexture(pong_ball_texture);
		pong_ball_sprite.setScale(scale_x, scale_y);
		pong_ball_sprite.setPosition(position_x, position_y);
	}

	void Ball::update(float delta_time, Paddle* player1, Paddle* player2)
	{
		pong_ball_sprite.move(velocity.x * delta_time, velocity.y * delta_time);
		handleBoundaryCollision();
		handlePaddleCollision(player1, player2);
		handleOutOfBoundCollision();
	}

	void Ball::render(sf::RenderWindow* game_window)
	{
		game_window->draw(pong_ball_sprite);
	}

	void Ball::handlePaddleCollision(Paddle* player1, Paddle* player2)
	{
		const sf::RectangleShape& player1Paddle = player1->getPaddleSprite();
		const sf::RectangleShape& player2Paddle = player2->getPaddleSprite();

		sf::FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();
		sf::FloatRect player1_bounds = player1Paddle.getGlobalBounds();
		sf::FloatRect player2_bounds = player2Paddle.getGlobalBounds();

		if (ball_bounds.intersects(player1_bounds) && velocity.x < 0)
		{
			velocity.x = -velocity.x;
			Sounds::SoundManager::playSoundEffect(Sounds::SoundType::BALL_BOUNCE);
		}
		if (ball_bounds.intersects(player2_bounds) && velocity.x > 0)
		{
			velocity.x = -velocity.x;
			Sounds::SoundManager::playSoundEffect(Sounds::SoundType::BALL_BOUNCE);
		}
	}

	void Ball::handleBoundaryCollision()
	{
		sf::FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();

		if ((ball_bounds.top <= top_boundary && velocity.y < 0) ||
			(ball_bounds.top + ball_bounds.height >= bottom_boundary && velocity.y > 0))
		{
			velocity.y = -velocity.y;
			Sounds::SoundManager::playSoundEffect(Sounds::SoundType::BALL_BOUNCE);
		}
	}

	void Ball::handleOutOfBoundCollision()
	{
		sf::FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();

		if (ball_bounds.left <= left_boundary)
		{
			updateLeftCollisionState(true);
		}
		else if (ball_bounds.left + ball_bounds.width >= right_boundary)
		{
			updateRightCollisionState(true);
		}
	}

	void Ball::reset()
	{
		pong_ball_sprite.setPosition(center_position_x, center_position_y);
		velocity = sf::Vector2f(ball_speed, ball_speed);
	}

	bool Ball::isLeftCollisionOccurred()
	{
		return had_left_collison;
	}

	void Ball::updateLeftCollisionState(bool value)
	{
		had_left_collison = value;
	}

	bool Ball::isRightCollisionOccurred()
	{
		return had_right_collison;
	}

	void Ball::updateRightCollisionState(bool value)
	{
		had_right_collison = value;
	}
}
