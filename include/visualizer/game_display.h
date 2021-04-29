#pragma once

#include <cinder/Color.h>

#include "glm/glm.hpp"

namespace bubblebounce {

/**
 * Game GUI display for the background graphics, panel information, and 
 * popup messages.
 */
  class GameDisplay{
  public:
    GameDisplay(const glm::vec2& window, 
                const glm::vec2& game_window_top_left,
                const glm::vec2& panel_bottom_right);
    /**
     * Draws the panel (level number, lives, score).
     * If the game is won or lost, draws the corresponding popup message.
     */
    void Display() const;
    
    /**
     * Updates the display information according to the current game state.
     * @param level current level representing the state of the game
     */
    void UpdateDisplay(const GameLevel& level);
    
    /**
     * Displays the game instructions. To be used for start screen and when game
     * is paused.
     */
    void DisplayGameInstructions() const;
    
  private:
    const std::string kGameWinningMessage = "Game Won!";
    const std::string kGameOverMessage = "Game Over";

    const ci::Font kLargeFont = ci::Font("Impact", 150.0f);
    const ci::Font kMediumFont = ci::Font("Ariel", 100.0f);
    const ci::Font kSmallFont = ci::Font("Ariel", 50.0f);
    
    const ci::Font kPanelFont = ci::Font("Impact", 75.0f);
    const ci::Font kPanelValuesFont = ci::Font("Impact", 150.0f);
    
    glm::vec2 window_dimensions;
    glm::vec2 game_window_top_left_;
    glm::vec2 panel_bottom_right_;
    
    size_t level_number_;
    size_t score_;
    size_t lives_;
    
    bool is_game_won_;
    bool is_game_over_;
    
    /**
     * Draws the first background layer of the entire game application.
     */
    void DrawBackground() const;

    /**
     * Draws the popup background for the popup message.
     */
    void DrawPopupBackground() const;
    
    /**
     * Draws the level number and label.
     */
    void DrawLevelNumber() const;
    
    /**
     * Draws the score and label.
     */
    void DrawScore() const;
    
    /**
     * Draws the lives left and label.
     */
    void DrawLives() const;
    
    /**
     * Draws the game summary popup message when the game is won or lost.
     * @param game_message message corresponding to if the player won or lost
     */
    void DrawGameSummary(const std::string& game_message) const;
  };

}  // namespace bubblebounce