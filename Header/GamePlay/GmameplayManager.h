#pragma once
#include"../../Header/GamePlay/Ball/Ball.h"
#include"../../Header/GamePlay/Paddle/Paddle.h"
#include"../../Header/GamePlay/Boundary/Boundary.h"
#include "../UI/UIService.h"
//#include"../../Header/Event/EventManager.h"

using namespace Events;
using namespace UI;

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


		EventManager* event_manager;
		UIService* ui_service;

		void initialize();
		


	public:
		GameplayManager(EventManager* manager);
		~GameplayManager();
		void UpdateScore();
		void resetPlayers();
		void update(float delta_time);
		void render(RenderWindow* game_window);


    };



}