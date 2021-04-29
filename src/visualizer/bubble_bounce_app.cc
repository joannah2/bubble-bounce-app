#include "visualizer/bubble_bounce_app.h"

namespace bubblebounce {

  BubbleBounceApp::BubbleBounceApp() :
    game_engine_(kGameWindowTopLeft, kGameWindowBottomRight),
    game_display_(glm::vec2{kWindowWidth, kWindowHeight},
                  kGameWindowTopLeft, kPanelBottomRight) {
    ci::app::setWindowSize(kWindowWidth, kWindowHeight);
    is_paused_ = true;
    is_new_round_ = true;
    is_game_over_ = false;
    game_display_.DisplayGameInstructions();
  }

  void BubbleBounceApp::draw() {
    if (is_paused_) {
      game_display_.DisplayGameInstructions();
      return;
    }
    
    game_display_.Display();
    
    if (!is_game_over_) {
      game_engine_.Display();
    }
  }

  void BubbleBounceApp::update() {
    if (is_paused_) return;
    
    game_display_.UpdateDisplay(game_engine_.GetCurrentLevel());
    
    if (game_engine_.GetCurrentLevel().IsLevelOver()) {
      is_game_over_ = true;
      return;
    }
    
    if (game_engine_.IsBallOut()) {
      is_new_round_ = true;
    }
    
    game_engine_.AdvanceOneFrame();
  }

  void BubbleBounceApp::keyDown(ci::app::KeyEvent event) {
    switch (event.getCode()) {
      case ci::app::KeyEvent::KEY_p: // pause/play
        is_paused_ = !(is_paused_);
        break;
      case ci::app::KeyEvent::KEY_r: // reset the game
        game_engine_.NewGame();
        is_new_round_ = true;
        break;
    }
  }

  void BubbleBounceApp::mouseMove(ci::app::MouseEvent event) {
    if (is_paused_ || is_game_over_) return;
    
    if (((float) event.getX() >= kGameWindowTopLeft.x) 
        && ((float) event.getX() <= kGameWindowBottomRight.x)
        && ((float) event.getY() <= kGameWindowBottomRight.y) 
        && ((float) event.getY() >= kGameWindowTopLeft.y)) {
      game_engine_.UpdatePaddlePosition(event.getPos());
    }
  }

  void BubbleBounceApp::mouseDown(ci::app::MouseEvent event) {
    if (is_paused_ || !(is_new_round_) || is_game_over_) return;
    game_engine_.StartGame(event.getPos());
    is_new_round_ = false;
  }

}  // namespace bubblebounce