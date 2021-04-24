#include "visualizer/bubble_bounce_app.h"

namespace bubblebounce {

  BubbleBounceApp::BubbleBounceApp() :
    game_engine_(GameEngine(glm::vec2{kLeftMargin, kLeftMargin},
                            glm::vec2 {kWindowWidth - kRightMargin,
                                       kWindowHeight - kLeftMargin})) {

    ci::app::setWindowSize(kWindowWidth, kWindowHeight);
    is_paused_ = false;
    is_new_round_ = true;
  }

  void BubbleBounceApp::draw() {
    // Draw container with black background
    ci::gl::clear(kBlackBackgroundColor);
    game_engine_.Display();
  }

  void BubbleBounceApp::update() {
    if (is_paused_) return;
    game_engine_.AdvanceOneFrame();
    if (game_engine_.IsRoundOver()) {
      is_new_round_ = true;
    }
  }

  void BubbleBounceApp::keyDown(ci::app::KeyEvent event) {
    switch (event.getCode()) {
      case ci::app::KeyEvent::KEY_p: // pause/play
        is_paused_ = !(is_paused_);
        break;
      case ci::app::KeyEvent::KEY_r: // fully reset the game
        game_engine_.NewGame();
        is_new_round_ = true;
        break;
    }
  }

  void BubbleBounceApp::mouseMove(ci::app::MouseEvent event) {
    if (is_paused_) return;
    
    if ((event.getX() >= kLeftMargin) 
        && (event.getX() <= kWindowWidth - kRightMargin)
        && (event.getY() <= kWindowHeight - kLeftMargin) 
        && (event.getY() >= kLeftMargin)) {
      game_engine_.UpdatePaddlePosition(event.getPos());
    }
  }

  void BubbleBounceApp::mouseDown(ci::app::MouseEvent event) {
    if (is_paused_ || !(is_new_round_)) return;
    game_engine_.StartGame(event.getPos());
    is_new_round_ = false;
  }

}  // namespace bubblebounce