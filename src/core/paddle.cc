#include "core/paddle.h"
#include <visualizer/bubble_bounce_app.h>

namespace bubblebounce {
  
  Paddle::Paddle(const glm::vec2& top_left, const glm::vec2& bottom_right,
                 const ci::Color& color) {
    if (top_left.x >= bottom_right.x || top_left.y >= bottom_right.y) {
      throw std::invalid_argument("Top left corner coordinates must be "
                                  "less than bottom right corner coordinates.");
    }
    top_left_ = top_left;
    bottom_right_ = bottom_right;
    color_ = color;
    length_ = (double) bottom_right.x - top_left.x;
  }

  void Paddle::SetCornerXCoordinates(const glm::vec2& corner_x_values) {
    if (corner_x_values.x >= corner_x_values.y) {
      throw std::invalid_argument("Top left corner x coordinate must be "
                                  "less than bottom right corner coordinates.");
    }
    top_left_.x = corner_x_values.x;
    bottom_right_.x = corner_x_values.y;
  }

  void Paddle::ResetAttributes(const glm::vec2& top_left,
                               const glm::vec2& bottom_right,
                               const cinder::Color& color) {
    if (top_left.x >= bottom_right.x || top_left.y >= bottom_right.y) {
      throw std::invalid_argument("Top left corner coordinates must be "
                                  "less than bottom right corner coordinates.");
    }
    top_left_ = top_left;
    bottom_right_ = bottom_right;
    color_ = color;
    length_ = (double) bottom_right.x - top_left.x;
  }
  
  void Paddle::Draw() const {
    ci::gl::color(color_);
    ci::gl::Texture2dRef paddle = ci::gl::Texture::create(
ci::loadImage(ci::app::loadAsset(kPaddleAsset)));
    ci::gl::draw(paddle, ci::Rectf(top_left_, bottom_right_));
  }
  
  glm::vec2 Paddle::GetTopLeftPosition() const {
    return top_left_;
  }

  glm::vec2 Paddle::GetBottomRightPosition() const {
    return bottom_right_;
  }

  double Paddle::GetLength() const {
    return length_;
  }
  
  ci::Color Paddle::GetColor() const {
    return color_;
  }
}  // namespace bubblebounce