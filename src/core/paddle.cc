#include "core/paddle.h"
#include <visualizer/bubble_bounce_app.h>

namespace bubblebounce {
  
  Paddle::Paddle(const glm::vec2& top_left, const glm::vec2& bottom_right,
                 const ci::Color& color) {
    top_left_ = top_left;
    bottom_right_ = bottom_right;
    color_ = color;
    length_ = (double) bottom_right.x - top_left.x;
    height_ = (double) bottom_right.y - top_left.y;
  }

  void Paddle::SetCornerXCoordinates(const glm::vec2& corner_x_values) {
    top_left_.x = corner_x_values.x;
    bottom_right_.x = corner_x_values.y;
  }

  glm::vec2 Paddle::GetTopLeftPosition() const {
    return top_left_;
  }

  glm::vec2 Paddle::GetBottomRightPosition() const {
    return bottom_right_;
  }

  void Paddle::Draw() const {
    ci::gl::color(color_);
    ci::gl::drawStrokedRect(ci::Rectf(top_left_, bottom_right_));
  }

  double Paddle::GetLength() const {
    return length_;
  }

  void Paddle::ResetAttributes(const glm::vec2 &top_left,
                               const glm::vec2 &bottom_right,
                               const cinder::Color &color) {
    top_left_ = top_left;
    bottom_right_ = bottom_right;
    color_ = color;
    length_ = (double) bottom_right.x - top_left.x;
    height_ = (double) bottom_right.y - top_left.y;
  }

}  // namespace bubblebounce