#include "core/ball.h"

#include <visualizer/bubble_bounce_app.h>

namespace bubblebounce {

  Ball::Ball(const cinder::Color& color, const glm::vec2& position,
             const glm::vec2& velocity, const float& radius) {
    if (radius <= 0.0f) {
      throw std::invalid_argument("Radius must be greater than 0.");
    }
    color_ = color;
    position_ = position;
    velocity_ = velocity;
    radius_ = radius;
  }

  void Ball::Draw() const {
    ci::gl::color(color_);
    ci::gl::drawSolidCircle(position_, radius_);
    
//    ci::gl::Texture2dRef ball = ci::gl::Texture::create(ci::loadImage(
//      ci::app::loadAsset("Ball.png")));
//    ci::gl::draw(ball, ci::Rectf(glm::vec2{position_.x - ballRadius_, position_.y - ballRadius_},
//                                 glm::vec2{position_.x + ballRadius_, position_.y + ballRadius_}));
  }

  void Ball::SetVelocityByTarget(const glm::vec2& target_position) {
    float x_velocity = target_position.x - position_.x;
    float y_velocity = target_position.y - position_.y;
    float magnitude = sqrt((x_velocity * x_velocity) + (y_velocity * y_velocity));
    velocity_.x = (x_velocity / magnitude) * kVelocityMultiplier;
    velocity_.y = (y_velocity / magnitude) * kVelocityMultiplier;
  }
  
  void Ball::ResetAttributes(const ci::Color& color, const glm::vec2& position,
                             const glm::vec2& velocity, const float& radius) {
    if (radius <= 0.0f) {
      throw std::invalid_argument("Radius must be greater than 0.");
    }
    color_ = color;
    position_ = position;
    velocity_ = velocity;
    radius_ = radius;
  }

  void Ball::SetVelocityByCollision(const glm::vec2& bubble_position) {
    if (position_.x < bubble_position.x) {
      velocity_.x *= -.99f;
    } else if (position_.x > bubble_position.x) {
      velocity_.x *= -1.01f;
    } else {
      velocity_.x *= -1.0f;
    }
    velocity_.y *= -1.0f;
  }
  
  void Ball::IncreasePositionByVelocity() {
    position_ += velocity_;
  }

  void Ball::ReverseXVelocity() {
    velocity_.x *= -1;
  }

  void Ball::ReverseYVelocity() {
    velocity_.y *= -1;
  }

  void Ball::SetVelocity(const glm::vec2& velocity) {
    velocity_ = velocity;
  }

  void Ball::SetPosition(const glm::vec2& position) {
    position_ = position;
  }

  void Ball::SetColor(const cinder::Color &color) {
    color_ = color;
  }
  
  ci::Color Ball::GetColor() const {
    return color_;
  }

  glm::vec2 Ball::GetPosition() const {
    return position_;
  }

  glm::vec2 Ball::GetVelocity() const {
    return velocity_;
  }
  
  float Ball::GetRadius() const {
    return radius_;
  }
}  // namespace bubblebounce