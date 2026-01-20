#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Core/GameWindowManager.h"
#include "../../Header/Event/EventManager.h"
#include "../../Header/GamePlay/GmameplayManager.h"
#include "../../Header/Utility/TimeService.h"


using namespace sf;
using namespace Core;
using namespace Events;
using namespace Gameplay;
using namespace Utility;
using namespace std;

namespace Core
{
	class GameLoop
	{
	private:
		GameWindowManager* game_window_manager;
		EventManager* event_manager;
		GameplayManager* gameplay_manager;
		TimeService* time_service;
		
		
	public:
		void initialize();

		bool isGameRunning();
		void pollEvent();
		void update();
		void render();
	};
}