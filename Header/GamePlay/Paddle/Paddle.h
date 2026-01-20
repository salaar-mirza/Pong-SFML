#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
namespace Gameplay
{
	class Paddle
	{
	private:
		// Speed is now in pixels per second. A value of 0.5f is too small.
		// Let's set it to a more reasonable value like 400 pixels/second.
		const float paddleSpeed = 400.0f;

		RectangleShape paddle_sprite;

		const float paddle_width = 20.0f;
		const float paddle_hight = 140.0f;

		const float topBoundary = 20.0f;
		const float bottomBoundary = 700.0f;

		void movePaddle(float delta_time, bool move_up_key_pressed, bool move_down_key_pressed);
		
	public:
		Paddle(float position_x,float position_y);

		RectangleShape getPaddleSprite();
		void reset(float position_x, float position_y);

		void update(float delta_time, bool move_up_key_pressed,bool down_key_pressed);
		void render(RenderWindow* game_window);

	};



}