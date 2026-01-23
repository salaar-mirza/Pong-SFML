#include <SFML/Graphics.hpp>
#include <filesystem>
#include "../../Header/Core/GameLoop.h"

using namespace Core;

int main()
{     
    // Step 1: Create the GameLoop object
    
    GameLoop* game_loop_manager = nullptr;
    
    game_loop_manager = new GameLoop();


    // Step 2: Initialize the game environment
    game_loop_manager->initialize();

    // Step 3: Run the game loop
    while (game_loop_manager->isGameRunning())
    {
        game_loop_manager->pollEvent();
        game_loop_manager->update();
        game_loop_manager->render();
    }
     // Clean up the GameLoop object and all the resources it manages.
     delete game_loop_manager;
    
    return 0;
}