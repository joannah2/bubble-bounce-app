#include "visualizer/container.h"

namespace bubblebounce {
  using glm::vec2;
  const glm::vec2 kPaddleTopLeft{350, 750};
  const glm::vec2 kPaddleBottomRight{550, 800};
  const ci::Color kBallColor("blue");
  static constexpr float kDefaultBallRadius = 25.0f;
  static constexpr double kBallMass = 10;
  
  Container::Container(const glm::vec2& top_left, const glm::vec2& bottom_right) 
                       : ball_(kBallColor, ball_position_, ball_velocity_, kDefaultBallRadius, kBallMass),
                         level_defaults_(top_left, bottom_right),
                         paddle_(kPaddleTopLeft, kPaddleBottomRight) {
    if (top_left.x >= bottom_right.x  || top_left.y >= bottom_right.y) {
      throw std::invalid_argument("Top left corner coordinates must be "
                                  "less than bottom right corner coordinates.");
      /**
       * glm::vec2{(bottom_right.x - top_left.x) / 2, bottom_right.y},
                               glm::vec2{(bottom_right.x - top_left.x) / 2 + 20, bottom_right.y}
       */
    }
    top_left_ = top_left;
    bottom_right_ = bottom_right;
    size_t bubble_count = level_defaults_.GetLevelDefaultBubbleCount(1);
    for (size_t i = 0; i < bubble_count; ++i) {
      Bubble bubble(ci::Color("blue"), glm::vec2(0, 0), 40.0f,
                    Bubble::NormalBubble, Bubble::Strong);
      bubbles_.emplace_back(bubble);
    }
    level_defaults_.GenerateBubblePositions(bubbles_, 1);
  }

  void Container::Display() const {
    /* Draw container */
    ci::gl::color(kContainerWallColor);
    ci::gl::drawStrokedRect(ci::Rectf(top_left_, bottom_right_));

    // draw bubbles, ball, paddle
    for (const Bubble& bubble : bubbles_) {
      bubble.Draw();
    }

    ball_.Draw();
    paddle_.Draw();
  }

  void Container::AdvanceOneFrame() {
    UpdateVelocitiesIfWallCollision();
    UpdateVelocitiesIfBubbleCollision();

//  for (Bubble& bubble : bubbles_) {
//    bubble.IncreasePositionByVelocity();
//  }
  }

  void Container::UpdateVelocitiesIfWallCollision() {
    if (HasHorizontalWallCollision()) {
      ball_.ReverseYVelocity();
    }
    if (HasVerticalWallCollision()) {
      ball_.ReverseXVelocity();
    }
  }

  void Container::UpdateVelocitiesIfBubbleCollision() {
    for (auto it = bubbles_.begin(); it != bubbles_.end(); ++it) {
      if (HasBubbleCollision(*it)) {
        bubbles_.erase(it);
      }
    }
  }

  bool Container::HasVerticalWallCollision() {
    return ((ball_.GetPosition().x - ball_.GetRadius()
             <= top_left_.x) && ball_.GetVelocity().x < 0)
           || ((ball_.GetPosition().x + ball_.GetRadius()
                >= bottom_right_.x) && ball_.GetVelocity().x > 0);
  }

  bool Container::HasHorizontalWallCollision() {
    return ((ball_.GetPosition().y - ball_.GetRadius() <= top_left_.y) && ball_.GetVelocity().y < 0)
           || ((ball_.GetPosition().y + ball_.GetRadius()
                >= bottom_right_.y) && ball_.GetVelocity().y > 0);
  }

  bool Container::HasBubbleCollision(const Bubble& bubble) {
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

    return (glm::distance(x_1, x_2) <= r_1 + r_2) && (glm::dot((v_1 - v_2), x_1 - x_2) < 0);
  }
  
  void Container::AddBubbleToContainer(const Bubble& bubble) {
    bubbles_.emplace_back(bubble);
  }

  void Container::ClearContainer() {
    bubbles_.clear();
  }

  std::vector<Bubble>& Container::GetContainerBubbles() {
    return bubbles_;
  }

  void Container::UpdatePaddlePosition(const glm::vec2& mouse_position) {
    double left = mouse_position.x - (paddle_.GetLength() / 2);
    double right = mouse_position.x + (paddle_.GetLength() / 2);
    glm::vec2 corner_x_values;
    if (left <= top_left_.x ) {
      corner_x_values = {top_left_.x, top_left_.x + paddle_.GetLength()};
      // set the left corner as container top left
    } else if (right >= bottom_right_.x) {
      // set the right corner as container bottom right
      corner_x_values = {bottom_right_.x - paddle_.GetLength(), bottom_right_.x};
    } else {
      corner_x_values = {left, right};
    }
    paddle_.SetXPosition(corner_x_values);
  }
  
}  // namespace bubblebounce