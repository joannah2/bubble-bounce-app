#include "visualizer/bubble_bounce_app.h"

namespace bubblebounce {

  BubbleBounceApp::BubbleBounceApp() :
    game_engine_(GameEngine(glm::vec2{kLeftMargin, kLeftMargin},
                            glm::vec2 {kWindowWidth - kRightMargin,
                                       kWindowHeight - kLeftMargin})) {

    ci::app::setWindowSize(kWindowWidth, kWindowHeight);
    is_paused_ = false;
  }

  void BubbleBounceApp::draw() {
    // Draw container with black background
    ci::gl::clear(kBlackBackgroundColor);
    game_engine_.Display();
  }

  void BubbleBounceApp::update() {
    if (is_paused_) return;
    game_engine_.AdvanceOneFrame();
  }

  void BubbleBounceApp::keyDown(ci::app::KeyEvent event) {
    switch (event.getCode()) {
      case ci::app::KeyEvent::KEY_SPACE: // pause/play
        is_paused_ = !(is_paused_);
        break;
      case ci::app::KeyEvent::KEY_r: // reset
        game_engine_.Reset();
        break;
      case ci::app::KeyEvent::KEY_BACKSPACE:
        // restart
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

}  // namespace bubblebounce