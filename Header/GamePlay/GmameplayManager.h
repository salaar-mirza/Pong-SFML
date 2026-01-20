#pragma once
#include"../../Header/GamePlay/Ball/Ball.h"
#include"../../Header/GamePlay/Paddle/Paddle.h"
#include"../../Header/GamePlay/Boundary/Boundary.h"
//#include"../../Header/Event/EventManager.h"

using namespace Events;

namespace Gameplay
{
	class GameplayManager 
	
	{
	private:
		float player1_position_x = 40.0f;
		float player1_position_y = 300.0f;

		float player2_position_x = 1210.0f;
		float player2_position_y = 300.0f;

		Ball* ball;
		Paddle* player1;
		Paddle* player2;
		Boundary* boundary;


		void initialize();

		EventManager* event_manager;


	public:
		GameplayManager(EventManager* manager);
		void update(float delta_time);
		void render(RenderWindow* game_window);


    };



}