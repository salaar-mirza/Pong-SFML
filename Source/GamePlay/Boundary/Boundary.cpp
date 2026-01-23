#include "../../Header/GamePlay/Boundary/Boundary.h"

namespace Gameplay
{
	Boundary::Boundary()
	{
	}

	Boundary::~Boundary()
	{
	}

	void Boundary::initialize()
	{
		createTopBoundary();
		createBottomBoundary();
		createLeftBoundary();
		createRightBoundary();
		createCenterLine();
	}

	void Boundary::createTopBoundary()
	{
		top_boundary.setSize(horizontal_boundary_size);
		top_boundary.setPosition(top_position);
		top_boundary.setFillColor(boundary_color);
	}

	void Boundary::createBottomBoundary()
	{
		bottom_boundary.setSize(horizontal_boundary_size);
		bottom_boundary.setPosition(bottom_position);
		bottom_boundary.setFillColor(boundary_color);
	}

	void Boundary::createLeftBoundary()
	{
		left_boundary.setSize(vertical_boundary_size);
		left_boundary.setPosition(left_position);
		left_boundary.setFillColor(boundary_color);
	}

	void Boundary::createRightBoundary()
	{
		right_boundary.setSize(vertical_boundary_size);
		right_boundary.setPosition(right_position);
		right_boundary.setFillColor(boundary_color);
	}

	void Boundary::createCenterLine()
	{
		center_line.setSize(center_line_size);
		center_line.setPosition(center_line_position);
		center_line.setFillColor(center_line_color);
	}

	void Boundary::render(sf::RenderWindow* game_window)
	{
		game_window->draw(top_boundary);
		game_window->draw(bottom_boundary);
		game_window->draw(left_boundary);
		game_window->draw(right_boundary);
		game_window->draw(center_line);
	}
}
