#include <visualizer/bubble_bounce_app.h>


namespace bubblebounce {

  GameDisplay::GameDisplay(const glm::vec2& window,
                           const glm::vec2& game_window_top_left,
                           const glm::vec2& panel_bottom_right) {
    window_dimensions = window;
    game_window_top_left_ = game_window_top_left;
    panel_bottom_right_ = panel_bottom_right;

    level_number_ = 0;
    score_ = 0;
    lives_ = 1;
    is_game_won_ = false;
    is_game_over_ = false;
  }

  void GameDisplay::Display() const {
    ci::gl::color(ci::Color8u(255, 255, 255));
    ci::gl::Texture2dRef image = ci::gl::Texture::create(
      ci::loadImage(ci::app::loadAsset("c_1.png")));
    ci::gl::draw(image, ci::Rectf(glm::vec2{0, 0}, window_dimensions));

    DrawLevelNumber();
    DrawLives();
    DrawScore();
    
    if (is_game_won_) {
      DrawGameSummary(kGameWinningMessage);
      return;
    }
    
    if (is_game_over_) {
      DrawGameSummary(kGameOverMessage);
      return;
    }
  }

  void GameDisplay::UpdateDisplay(const GameLevel& level) {
    size_t level_number = level.GetLevel();
    size_t score = level.GetPlayerScore();
    size_t lives = level.GetPlayerLives();
    
    if (level_number_ != level_number) level_number_ = level_number;
    if (lives_ != lives) lives_ = lives;
    if (score_ != score) score_ = score;
    
    // opposite of IsLevelWon is not the same as IsLevelLost
    if (level.IsLevelWon()) is_game_won_ = true;
    if (level.IsLevelLost()) is_game_over_ = true;
  }
  
  void GameDisplay::DrawLevelNumber() const {
    ci::gl::drawStringCentered("Level" ,glm::vec2(950,100),
                               ci::Color("black"),
                               ci::Font("Impact", 75.0f));
    
    ci::gl::drawStringCentered(
      std::to_string(level_number_),glm::vec2(950,150),
      ci::Color("Teal"),
      ci::Font("Impact", 150.0f));
  }

  void GameDisplay::DrawLives() const {
    ci::gl::drawStringCentered("Lives" , glm::vec2(950,350),
      ci::Color("black"),
      ci::Font("Impact", 75.0f));
    
    ci::gl::drawStringCentered(
      std::to_string(lives_), glm::vec2(950,400),
      ci::Color("Teal"),
      ci::Font("Impact", 150.0f));
  }

  void GameDisplay::DrawScore() const {
    ci::gl::drawStringCentered("Score",glm::vec2(950,600),
                               ci::Color("black"),
                               ci::Font("Impact", 75.0f));
    
    ci::gl::drawStringCentered(
      std::to_string(score_),glm::vec2(950,650),
      ci::Color("Teal"),
      ci::Font("Impact", 150.0f));
  }

  void GameDisplay::DrawGameSummary(const std::string& game_message) const {
    // Draw background for pop up
    ci::gl::color(ci::Color8u(255, 255, 255));
    ci::gl::Texture2dRef popup_background = ci::gl::Texture::create(
  ci::loadImage(ci::app::loadAsset("wood.jpg")));
    ci::gl::draw(popup_background, ci::Rectf(game_window_top_left_,
                                             panel_bottom_right_));

    glm::vec2 line_1 = glm::vec2{window_dimensions.x / 2,250};
    glm::vec2 line_2 = glm::vec2{window_dimensions.x / 2,450};
    glm::vec2 line_3 = glm::vec2{window_dimensions.x / 2,550};

    // Draw message
    ci::gl::drawStringCentered(game_message, line_1,
                               ci::Color("teal"),
                                ci::Font("Impact", 150.0f));

    // Draw level number
    ci::gl::drawStringCentered( "Level: " + std::to_string(level_number_), 
                                line_2,ci::Color("white"),
                                ci::Font("Impact", 100.0f));

    // Draw score
    ci::gl::drawStringCentered("Your Score: " + std::to_string(score_),
                               line_3, ci::Color("white"), 
                               ci::Font("Impact", 100.0f));
  }
  
}  // namespace bubblebounce