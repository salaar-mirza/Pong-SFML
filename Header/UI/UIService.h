#pragma once

#include <string>
#include <SFML/Graphics.hpp>


using  namespace  sf;
using namespace std;

namespace UI
{
    class UIService
    {
    private:
        Font font;
        Text left_score_text;

        string texture_path = R"(D:\MyOutscal\Pong-SFML\Assets\Fonts\Aloevera-OVoWO.ttf)";


        int font_size = 40;
        Color font_color = Color::White;
        string initial_string = "00";

        float left_score_postion_x = 570.0f;
        float left_score_postion_y = 30.0f;
    
        float right_score_position_x = 670.0f;
        float right_score_position_y = 30.0f;
    
        int player1_score = 0;

        void loadFontTexture();
        void createLeftScoreText();
     
    public:
        UIService();
        void render(RenderWindow* game_window);
       
    
    };

    
}
