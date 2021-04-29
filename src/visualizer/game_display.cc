#include <visualizer/bubble_bounce_app.h>
//#include <visualizer/game_display.h>

namespace bubblebounce {
  
  GameDisplay::GameDisplay(const glm::vec2& window,
                           const glm::vec2& game_window_top_left,
                           const glm::vec2& panel_bottom_right) {

    if (game_window_top_left.x > window.x || game_window_top_left.y < 0.0f
        || panel_bottom_right.y > window.y|| panel_bottom_right.x > window.x) {
      throw std::invalid_argument("Window dimensions don't match");
    }

    window_dimensions = window;
    game_window_top_left_ = game_window_top_left;
    panel_bottom_right_ = panel_bottom_right;

    high_score_ = 0;
    score_ = 0;
    lives_ = 1;
    is_game_won_ = false;
    is_game_over_ = false;
  }
  
  void GameDisplay::DisplayGameInstructions() const {
    DrawBackground();
    DrawPopupBackground();
    
    float message_center = window_dimensions.x / 2;
    float message_left_align = window_dimensions.x / kMessageAlignmentDivider;
    
    glm::vec2 line_1 = glm::vec2{message_center,150};
    glm::vec2 line_2 = glm::vec2{message_left_align,350};
    glm::vec2 line_3 = glm::vec2{message_left_align,400};
    glm::vec2 line_4= glm::vec2{message_left_align,450};
    glm::vec2 line_5 = glm::vec2{message_center,550};
    glm::vec2 line_6 = glm::vec2{message_center,650};

    ci::gl::drawStringCentered("Bubble Bounce", line_1, kTeal,
                               kLargeFont);

    ci::gl::drawString("- Click to launch the ball at start of round",
                       line_2, kBlack,kSmallFont);

    ci::gl::drawString("- Use mouse to guide the paddle left/right",
                       line_3, kBlack,kSmallFont);

    ci::gl::drawString("- Keep the ball alive to clear all poppable "
                       "bubbles!", line_4,kBlack,kSmallFont);

    ci::gl::drawStringCentered( "Press [p] to Play/Pause Game", line_5,
                                kBlack,kSmallFont);

    ci::gl::drawStringCentered("Press [r] to Reset the Game", line_6, 
                               kBlack,kSmallFont);
  }

  void GameDisplay::DrawBackground() const {
    ci::gl::color(kBackgroundColor);
    ci::gl::Texture2dRef image = ci::gl::Texture::create(
      ci::loadImage(ci::app::loadAsset(
        kBackgroundAsset)));
    ci::gl::draw(image, ci::Rectf(glm::vec2{0, 0},
                                  window_dimensions));
  }

  void GameDisplay::DrawPopupBackground() const {
    ci::gl::color(kBackgroundColor);
    ci::gl::Texture2dRef popup_background = ci::gl::Texture::create(
      ci::loadImage(ci::app::loadAsset(kWoodAsset)));
    ci::gl::draw(popup_background, ci::Rectf(game_window_top_left_,
                                             panel_bottom_right_));
  }
  
  void GameDisplay::Display() const {
    DrawBackground();
    
    if (is_game_won_) {
      DrawGameSummary(kGameWinningMessage);
      return;
    }
    
    if (is_game_over_) {
      DrawGameSummary(kGameOverMessage);
      return;
    }

    DrawHighscore();
    DrawLives();
    DrawScore();
  }
  
  void GameDisplay::DrawGameSummary(const std::string& game_message) const {
    DrawPopupBackground();
    
    float message_center = window_dimensions.x / 2;
    
    glm::vec2 line_1 = glm::vec2{message_center,250};
    glm::vec2 line_2 = glm::vec2{message_center,450};
    glm::vec2 line_3 = glm::vec2{message_center,550};

    // Draw message
    ci::gl::drawStringCentered(game_message, line_1, kBlue,
                               kLargeFont);

    // Draw high score
    ci::gl::drawStringCentered(kHighScore + std::to_string(high_score_),
                               line_2, kWhite, kMediumFont);

    // Draw lives
    ci::gl::drawStringCentered(kLivesLeft + std::to_string(lives_),
                               line_3, kWhite, kMediumFont);
  }

  void GameDisplay::UpdateDisplay(const GameLevel& level) {
    size_t score = level.GetPlayerScore();
    size_t lives = level.GetPlayerLives();
    
    if (high_score_ < score) high_score_ = score;
    if (lives_ != lives) lives_ = lives;
    if (score_ != score) score_ = score;
    
    // opposite of IsLevelWon is not the same as IsLevelLost
    if (level.IsLevelWon()) is_game_won_ = true;
    if (level.IsLevelLost()) is_game_over_ = true;
  }

  void GameDisplay::DrawHighscore() const {
    ci::gl::drawStringCentered(kPanelLabelHighScore ,
                               glm::vec2(kHighScorePosition.x,
                               kHighScorePosition.y - kPanelLabelDistance),
                               kBlack, kPanelFont);

    ci::gl::drawStringCentered(std::to_string(high_score_),
                               kHighScorePosition,
                               kBlue, kPanelValuesFont);
  }

  void GameDisplay::DrawLives() const {
    ci::gl::drawStringCentered(kPanelLabelLives , glm::vec2(kLivesPosition.x,
                              kLivesPosition.y - kPanelLabelDistance),
                               kBlack, kPanelFont);
    
    ci::gl::drawStringCentered(std::to_string(lives_), kLivesPosition,
                               kBlue, kPanelValuesFont);
  }

  void GameDisplay::DrawScore() const {
    ci::gl::drawStringCentered(kPanelLabelScore,glm::vec2(kScorePosition.x,
                                kScorePosition.y - kPanelLabelDistance),
                               kBlack,kPanelFont);
    
    ci::gl::drawStringCentered(std::to_string(score_), kScorePosition,
                               kBlue, kPanelValuesFont);
  }
  
}  // namespace bubblebounce