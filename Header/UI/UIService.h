#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace UI
{
    class UIService
    {
    public:
        UIService();
        ~UIService();

        void initialize();
        void update();
        void render(sf::RenderWindow* game_window);
        void incrementPlayer1Score();
        void incrementPlayer2Score();

    private:
        sf::Font font;
        sf::Text left_score_text;
        sf::Text right_score_text;

        const std::string font_path = "Assets/Fonts/Aloevera-OVoWO.ttf";
        const int font_size = 40;
        const sf::Color font_color = sf::Color::White;
        const std::string initial_string = "00";

        const sf::Vector2f left_score_position = sf::Vector2f(570.0f, 30.0f);
        const sf::Vector2f right_score_position = sf::Vector2f(670.0f, 30.0f);

        int player1_score = 0;
        int player2_score = 0;

        void loadFont();
        void createLeftScoreText();
        void createRightScoreText();
        std::string formatScore(int score);
    };
}
