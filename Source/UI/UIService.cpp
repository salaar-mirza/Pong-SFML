#include "../../Header/UI/UIService.h"


namespace UI
{
    UIService::UIService()
    {
        loadFontTexture();
        createLeftScoreText();
    }

    void UIService::loadFontTexture()
    {
        font.loadFromFile(texture_path);
    }

    void UIService::createLeftScoreText()
    {
        left_score_text.setFont(font);
        left_score_text.setString(initial_string);
        left_score_text.setCharacterSize(font_size);
        left_score_text.setFillColor(font_color);
        left_score_text.setPosition(left_score_postion_x, left_score_postion_y);
    }

    void UIService::render(RenderWindow* game_window)
    {
        game_window->draw(left_score_text);
    }
}
