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
    // message fonts
    const ci::Font kLargeFont = ci::Font("Impact", 150.0f);
    const ci::Font kMediumFont = ci::Font("Ariel", 100.0f);
    const ci::Font kSmallFont = ci::Font("Ariel", 50.0f);
    
    // panel fonts
    const ci::Font kPanelFont = ci::Font("Impact", 75.0f);
    const ci::Font kPanelValuesFont = ci::Font("Impact", 150.0f);
    
    // text colors
    const ci::Color kBlack = ci::Color("black");
    const ci::Color kTeal = ci::Color("teal");
    const ci::Color kBlue = ci::Color("lightskyblue");
    const ci::Color kWhite = ci::Color("white");
    const ci::Color kBackgroundColor = ci::Color8u(255, 255, 255);
    
    // message left align by display dimensions
    static constexpr size_t kMessageAlignmentDivider = 6;
    
    // position of panel values: level, lives, score  
    const glm::vec2 kHighScorePosition = glm::vec2(950, 150);
    const glm::vec2 kLivesPosition = glm::vec2(950,400);
    const glm::vec2 kScorePosition = glm::vec2(950,650);
    
    // distance between panel values and value label
    const float kPanelLabelDistance = 50.0f;
    
    // panel text
    const std::string kPanelLabelHighScore = "High Score";
    const std::string kPanelLabelLives = "Lives";
    const std::string kPanelLabelScore = "Score";
    
    // game summary text
    const std::string kHighScore = "High Score: ";
    const std::string kLivesLeft = "Lives Left: ";
    const std::string kGameWinningMessage = "Game Won!";
    const std::string kGameOverMessage = "Game Over";

    // image assets
    const std::string kBackgroundAsset = "background.png";
    const std::string kWoodAsset = "wood.jpg";
    
    glm::vec2 window_dimensions;
    glm::vec2 game_window_top_left_;
    glm::vec2 panel_bottom_right_;
    
    size_t high_score_;
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
     * Draws the high score and label.
     */
    void DrawHighscore() const;
    
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