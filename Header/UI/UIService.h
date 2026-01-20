#pragma once

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using  namespace sf;

namespace UI
{
    class UIService
    {
    private:
        sf::Font font;
        sf::Text left_score_text;
        sf::Text right_score_text;


        std::string texture_path = R"(D:\MyOutscal\Pong-SFML\Assets\Fonts\Aloevera-OVoWO.ttf)";


        int font_size = 40;
        sf::Color font_color = sf::Color::White;
        std::string initial_string = "00";

        float left_score_postion_x = 570.0f;
        float left_score_postion_y = 30.0f;
    
        float right_score_position_x = 670.0f;
        float right_score_position_y = 30.0f;
    
        int player1_score = 0;
        int player2_score = 0;
    

        void loadFontTexture();
        void createLeftScoreText();
        void createRightScoreText();
     
    public:
        UIService();
        std::string formatScore(int score);
        void incrementPlayer1Score();
        void incrementPlayer2Score();
        void update();
      
        void render(sf::RenderWindow* game_window);
       
    
    };

    
}
