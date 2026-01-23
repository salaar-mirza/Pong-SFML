#include "../../Header/UI/UIService.h"
#include <stdexcept>

namespace UI
{
	UIService::UIService()
	{
	}

	UIService::~UIService()
	{
	}

	void UIService::initialize()
	{
		loadFont();
		createLeftScoreText();
		createRightScoreText();
	}

	void UIService::loadFont()
	{
		if (!font.loadFromFile(font_path))
		{
			throw std::runtime_error("Failed to load font!");
		}
	}

	void UIService::createLeftScoreText()
	{
		left_score_text.setFont(font);
		left_score_text.setString(initial_string);
		left_score_text.setCharacterSize(font_size);
		left_score_text.setFillColor(font_color);
		left_score_text.setPosition(left_score_position);
	}

	void UIService::createRightScoreText()
	{
		right_score_text.setFont(font);
		right_score_text.setString(initial_string);
		right_score_text.setCharacterSize(font_size);
		right_score_text.setFillColor(font_color);
		right_score_text.setPosition(right_score_position);
	}

	void UIService::incrementPlayer1Score()
	{
		player1_score++;
	}

	void UIService::incrementPlayer2Score()
	{
		player2_score++;
	}

	std::string UIService::formatScore(int score)
	{
		return (score < 10 ? "0" : "") + std::to_string(score);
	}

	void UIService::update()
	{
		left_score_text.setString(formatScore(player1_score));
		right_score_text.setString(formatScore(player2_score));
	}

	void UIService::render(sf::RenderWindow* game_window)
	{
		game_window->draw(left_score_text);
		game_window->draw(right_score_text);
	}
}
