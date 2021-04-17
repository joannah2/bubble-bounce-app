#include "visualizer/bubble_bounce_app.h"

namespace bubblebounce {

  BubbleBounceApp::BubbleBounceApp() :
    container_(
      Container(glm::vec2{kLeftMargin, kLeftMargin},
                glm::vec2 {kWindowWidth - kRightMargin, kWindowHeight - kLeftMargin})) {

    ci::app::setWindowSize(kWindowWidth, kWindowHeight);
  }

  void BubbleBounceApp::draw() {
    /* Draw container with black background */
    ci::gl::clear(kBlackBackgroundColor);
    container_.Display();

  }

  void BubbleBounceApp::update() {
    container_.AdvanceOneFrame();

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