#include "visualizer/game_engine.h"

namespace bubblebounce {
  using glm::vec2;
  const glm::vec2 kPaddleTopLeft{350, 750};
  const glm::vec2 kPaddleBottomRight{550, 800};
  const ci::Color kPaddleColor("white");
  const ci::Color kBallColor("white");
  static constexpr float kDefaultBallRadius = 25.0f;
  const glm::vec2 kDefaultBallPosition{450, 725};
  const glm::vec2 kDefaultBallVelocity{0, 0};
  
  GameEngine::GameEngine(const glm::vec2& top_left, const glm::vec2& bottom_right) 
     : ball_(kBallColor, kDefaultBallPosition, kDefaultBallVelocity,
             kDefaultBallRadius),
       level_generator_(top_left, bottom_right),
       paddle_(kPaddleTopLeft, kPaddleBottomRight, kPaddleColor) {
    if (top_left.x >= bottom_right.x  || top_left.y >= bottom_right.y) {
      throw std::invalid_argument("Top left corner coordinates must be "
                                  "less than bottom right corner coordinates.");
    }
    top_left_ = top_left;
    bottom_right_ = bottom_right;
    current_level_ = level_generator_.GetGeneratedGameLevel(1);
    bubbles_ = current_level_.GetLevelBubbles();
  }

  void GameEngine::Display() const {
    // draw container
    ci::gl::color(kContainerWallColor);
    ci::gl::drawStrokedRect(ci::Rectf(top_left_, bottom_right_));
    
    // draw bubbles, ball, paddle
    for (const Bubble& bubble : bubbles_) {
      bubble.Draw();
    }
    ball_.Draw();
    paddle_.Draw();
  }

  void GameEngine::AdvanceOneFrame() { 
    if (IsRoundOver()) {
      // display winning or losing screen
      return;
    }
   
    UpdateIfWallCollision();
    UpdateIfBubbleCollision();
    
    if (HasHitPaddle()) {
      ball_.ReverseYVelocity();
    }
    ball_.IncreasePositionByVelocity();
  }
  
  void GameEngine::UpdateIfWallCollision() {
    if (HasTopWallCollision()) {
      ball_.ReverseYVelocity();
    }
    if (HasVerticalWallCollision()) {
      ball_.ReverseXVelocity();
    }
  }

  void GameEngine::UpdateIfBubbleCollision() {
    for (size_t i = 0; i < bubbles_.size(); ++i) {
      if (HasBubbleCollision(bubbles_[i])) {
        glm::vec2 ball_velocity = ball_.GetVelocity();
        
        // adjust new bubble state
        if (bubbles_[i].GetBubbleType() != Bubble::Unpoppable) {
          bubbles_[i].LowerBubbleState();
        }
        
        // adjust new ball velocity
        ball_.SetVelocityByCollision(bubbles_[i].GetPosition());
        
        // handle popping a bubble
        if (bubbles_[i].GetBubbleState() == Bubble::Popped) {
          // if special bubble add extra points
          // else for normal bubbles, add 1 pt 
          ball_.SetColor(bubbles_[i].GetColor());
          bubbles_.erase(bubbles_.begin() + i);
        }
        break;
      }
    }
  }

  bool GameEngine::HasVerticalWallCollision() {
    return ((ball_.GetPosition().x - ball_.GetRadius() <= top_left_.x) 
            && ball_.GetVelocity().x < 0)
           || ((ball_.GetPosition().x + ball_.GetRadius() >= bottom_right_.x) 
           && ball_.GetVelocity().x > 0);
  }

  bool GameEngine::HasTopWallCollision() {
    return (ball_.GetPosition().y - ball_.GetRadius() <= top_left_.y) 
            && ball_.GetVelocity().y < 0;
  }
  
  bool GameEngine::IsRoundOver() {
    // if the ball fell through the bottom or NO MORE TURNS
    return (ball_.GetPosition().y + ball_.GetRadius() >= bottom_right_.y)
            && ball_.GetVelocity().y > 0;
  }
  
  bool GameEngine::HasBubbleCollision(const Bubble& bubble) {
    /*
     * Variable names follow common arithmetic variable convention
     * v = velocity, r = radius, x = position
     */
    glm::vec2 v_1 = ball_.GetVelocity();
    glm::vec2 v_2 = glm::vec2{0, 0};
    double r_1 = ball_.GetRadius();
    double r_2 = ball_.GetRadius();
    glm::vec2 x_1 = ball_.GetPosition();
    glm::vec2 x_2 = bubble.GetPosition();

    return (glm::distance(x_1, x_2) <= r_1 + r_2) && (glm::dot((v_1 - v_2),
                                                               x_1 - x_2) < 0);
  }

  void GameEngine::UpdatePaddlePosition(const glm::vec2& mouse_position) {
    double left = mouse_position.x - (paddle_.GetLength() / 2);
    double right = mouse_position.x + (paddle_.GetLength() / 2);
    glm::vec2 corner_x_values;
    
    if (left <= top_left_.x ) {
      corner_x_values = {top_left_.x, top_left_.x + paddle_.GetLength()};
    } else if (right >= bottom_right_.x) {
      corner_x_values = {bottom_right_.x - paddle_.GetLength(),
                         bottom_right_.x};
    } else {
      corner_x_values = {left, right};
    }
    
    paddle_.SetCornerXCoordinates(corner_x_values);
  }

  bool GameEngine::HasHitPaddle() {
    return (ball_.GetVelocity().y > 0) 
        && (ball_.GetPosition().x >= paddle_.GetTopLeftPosition().x) 
        && (ball_.GetPosition().x <= paddle_.GetBottomRightPosition().x) 
        && (ball_.GetPosition().y + ball_.GetRadius() >= 
        paddle_.GetTopLeftPosition().y);
  }

  void GameEngine::StartGame(const glm::vec2& target_position) {
    ball_.SetVelocityByTarget(target_position);
  }
  
  void GameEngine::Reset() {
    // reset ball, paddle, bubbles, points, lives
    ball_.ResetAttributes(kBallColor, kDefaultBallPosition, kDefaultBallVelocity,
                          kDefaultBallRadius);
    paddle_.ResetAttributes(kPaddleTopLeft, kPaddleBottomRight, kPaddleColor);
    bubbles_ = current_level_.GetLevelBubbles();
  }
}  // namespace bubblebounce