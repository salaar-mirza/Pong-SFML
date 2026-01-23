#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace Core 
{
	class GameWindowManager 
	{
	public:
		GameWindowManager();
		~GameWindowManager();

		void initialize();
		sf::RenderWindow* getGameWindow();
		bool isGameRunning();
		void clearGameWindow();
		void displayGameWindow();

	private:
		const int game_window_width = 1280;
		const int game_window_height = 720;
		const std::string game_title = "SFML-Pong!";

		sf::RenderWindow* game_window;

		void createGameWindow();
	};
}
