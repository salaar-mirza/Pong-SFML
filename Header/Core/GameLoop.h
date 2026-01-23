#pragma once

// Forward declarations instead of includes
// This reduces compile times and unnecessary dependencies.
namespace Core { class GameWindowManager; }
namespace Events { class EventManager; }
namespace Gameplay { class GameplayManager; }
namespace Utility { class TimeService; }
namespace Sounds { class SoundManager; }

namespace Core
{
	class GameLoop
	{
	public:
		GameLoop();
		~GameLoop();

		void initialize();
		void pollEvent();
		void update();
		void render();
		bool isGameRunning();

	private:
		// The compiler knows the size of a pointer, so this is fine.
		GameWindowManager* game_window_manager;
		Events::EventManager* event_manager;
		Gameplay::GameplayManager* gameplay_manager;
		Utility::TimeService* time_service;
		Sounds::SoundManager* sound_manager;
	};
}
