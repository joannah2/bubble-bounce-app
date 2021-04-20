#include "visualizer/bubble_bounce_app.h"

namespace bubblebounce {

  BubbleBounceApp::BubbleBounceApp() :
    container_(Container(glm::vec2{kLeftMargin, kLeftMargin},
                glm::vec2 {kWindowWidth - kRightMargin, kWindowHeight - kLeftMargin})), 
    level_defaults_(glm::vec2{kLeftMargin, kLeftMargin},
                glm::vec2 {kWindowWidth - kRightMargin, kWindowHeight - kLeftMargin}){

    ci::app::setWindowSize(kWindowWidth, kWindowHeight);
    is_new_game_ = true;
    level_bubble_defaults_ = level_defaults_.GetGameLevelBubbles();
    container_.SetGameBubbles(level_bubble_defaults_[1]);
  }

  void BubbleBounceApp::draw() {
    // Draw container with black background
    ci::gl::clear(kBlackBackgroundColor);
    container_.Display();

  }

  void BubbleBounceApp::update() {
    container_.AdvanceOneFrame();
    // if new game instance or level, set game bubbles
//    bool is_new_game = true;
    if (is_new_game_) {
      container_.SetGameBubbles(level_bubble_defaults_[1]);
//      container_.SetGameBubbles(level_defaults_, 1);
      is_new_game_ = false;
    }
    
    // if the game is over -> show game over screen
//    if (!container_.IsRoundOver()) {
//    }
  }

  void BubbleBounceApp::keyDown(ci::app::KeyEvent event) {
  }

  void BubbleBounceApp::mouseMove(ci::app::MouseEvent event) {
    if ((event.getX() >= kLeftMargin) && (event.getX() <= kWindowWidth - kRightMargin) &&
    (event.getY() <= kWindowHeight - kLeftMargin) && (event.getY() >= kLeftMargin)) {
      container_.UpdatePaddlePosition(event.getPos());
    }
  }

}  // namespace bubblebounce