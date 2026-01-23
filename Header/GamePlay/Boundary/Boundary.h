#pragma once
#include <SFML/Graphics.hpp>

namespace Gameplay
{
    class Boundary
    {
    public:
        Boundary();
        ~Boundary();

        void initialize();
        void render(sf::RenderWindow* game_window);

    private:
        sf::RectangleShape top_boundary;
        sf::RectangleShape bottom_boundary;
        sf::RectangleShape left_boundary;
        sf::RectangleShape right_boundary;
        sf::RectangleShape center_line;

        const sf::Vector2f horizontal_boundary_size = sf::Vector2f(1280.0f, 20.0f);
        const sf::Vector2f vertical_boundary_size = sf::Vector2f(20.0f, 720.0f);

        const sf::Vector2f top_position = sf::Vector2f(0.0f, 0.0f);
        const sf::Vector2f bottom_position = sf::Vector2f(0.0f, 700.0f);
        const sf::Vector2f left_position = sf::Vector2f(0.0f, 0.0f);
        const sf::Vector2f right_position = sf::Vector2f(1260.0f, 0.0f);

        const sf::Vector2f center_line_size = sf::Vector2f(10.0f, 680.0f);
        const sf::Vector2f center_line_position = sf::Vector2f(640.0f, 20.0f);

        const sf::Color boundary_color = sf::Color(211, 211, 211, 255);
        const sf::Color center_line_color = sf::Color::White;

        void createTopBoundary();
        void createBottomBoundary();
        void createLeftBoundary();
        void createRightBoundary();
        void createCenterLine();
    };
}
