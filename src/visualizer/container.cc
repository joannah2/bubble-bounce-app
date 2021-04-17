#include "visualizer/container.h"

namespace bubblebounce {

  using glm::vec2;

  Container::Container(const glm::vec2& top_left, const glm::vec2& bottom_right) 
                       : ball_(ci::Color("blue"), glm::vec2{450, 725},
                               glm::vec2{0,0}, 25.0f, 10),
                       level_(top_left, bottom_right),
                       paddle_(kPaddleTopLeft, kPaddleBottomRight){
    if (top_left.x >= bottom_right.x
        || top_left.y >= bottom_right.y) {
      throw std::invalid_argument("Top left corner coordinates must be "
                                  "less than bottom right corner coordinates.");
      /**
       * glm::vec2{(bottom_right.x - top_left.x) / 2, bottom_right.y},
                               glm::vec2{(bottom_right.x - top_left.x) / 2 + 20, bottom_right.y}
       */
    }
    top_left_ = top_left;
    bottom_right_ = bottom_right;
    
    for (size_t i = 0; i < level_.GetInitialBubbleCount(); ++i) {
      Bubble bubble(ci::Color("blue"), glm::vec2(0, 0), 40.0f,
                    Bubble::NormalBubble, Bubble::Strong);
      bubbles_.emplace_back(bubble);
    }
    level_.GenerateBubblePositions(bubbles_);
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
//    Bubble bubble(ci::Color("blue"), glm::vec2(0, 0), 25.0f,
//                  Bubble::NormalBubble, Bubble::Strong);
//    bubbles_.emplace_back(bubble);
//    UpdateVelocitiesIfWallCollision();
//    UpdateVelocitiesIfBubbleCollision();

//  for (Bubble& bubble : bubbles_) {
//    bubble.IncreasePositionByVelocity();
//  }
  }

//void Container::UpdateVelocitiesIfWallCollision() {
//  bool has_vertical_wall_collision = collision_manager_.HasWallCollision(
//      ball_, kXDirection, top_left_, bottom_right_);
//  bool has_horizontal_wall_collision =
//      collision_manager_.HasWallCollision(ball_, kYDirection,
//                                                     top_left_,
//                                                     bottom_right_);
//    if (has_horizontal_wall_collision) {
//      ball_.ReverseYVelocity();
//    }
//    if (has_vertical_wall_collision) {
//      ball_.ReverseXVelocity();
//    }
//  }
//}

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
      // set the right corner as container bottomr right
      corner_x_values = {bottom_right_.x - paddle_.GetLength(), bottom_right_.x};
    } else {
      corner_x_values = {left, right};
    }
    // determine the left and right corners with the center mouse_position
    paddle_.SetXPosition(corner_x_values);
  }

}  // namespace bubblebounce