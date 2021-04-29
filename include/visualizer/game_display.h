#pragma once

#include <cinder/Color.h>

#include "glm/glm.hpp"


namespace bubblebounce {

/**
 * Game GUI display for the background graphics.
 */
  class GameDisplay{
  public:
    GameDisplay(const glm::vec2& window, 
                const glm::vec2& game_window_top_left,
                const glm::vec2& panel_bottom_right);
    
    void Display() const;
    
    void UpdateDisplay(const GameLevel& level);
    
  private:
    const std::string kGameWinningMessage = "Game Won!";
    const std::string kGameOverMessage = "Game Over";

    glm::vec2 window_dimensions;
    glm::vec2 game_window_top_left_;
    glm::vec2 panel_bottom_right_;
    
    size_t level_number_;
    size_t score_;
    size_t lives_;
    
    bool is_game_won_;
    bool is_game_over_;
    
    void DrawLevelNumber() const;
    void DrawScore() const;
    void DrawLives() const;
    void DrawGameSummary(const std::string& game_message) const;
  };

}  // namespace bubblebounce