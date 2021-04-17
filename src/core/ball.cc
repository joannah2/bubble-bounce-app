#include "core/ball.h"

#include <visualizer/bubble_bounce_app.h>

namespace bubblebounce {

  Ball::Ball(const cinder::Color& color, const glm::vec2& position,
             const glm::vec2& velocity, const float& radius, const double& mass) {
    if (radius <= 0.0f || mass <= 0.0) {
      throw std::invalid_argument("Radius and mass must be greater than 0.");
    }
    color_ = color;
    position_ = position;
    velocity_ = velocity;
    radius_ = radius;

    // no need for mass
    mass_ = mass;
  }

  void Ball::Draw() const {
    ci::gl::color(color_);
    ci::gl::drawSolidCircle(position_, radius_);
    
//    ci::gl::Texture2dRef ball = ci::gl::Texture::create(ci::loadImage(
//      ci::app::loadAsset("Ball.png")));
//    ci::gl::draw(ball, ci::Rectf(glm::vec2{position_.x - ballRadius_, position_.y - ballRadius_},
//                                 glm::vec2{position_.x + ballRadius_, position_.y + ballRadius_}));
  }
  
  void Ball::IncreasePositionByVelocity() {
    position_ += velocity_;
  }

  void Ball::SetVelocity(const glm::vec2& velocity) {
    velocity_ = velocity;
  }

  void Ball::ReverseXVelocity() {
    velocity_.x *= -1;
  }

  void Ball::ReverseYVelocity() {
    velocity_.y *= -1;
  }

  bool Ball::operator==(const Ball& compared_Ball) const {
    return (color_ == compared_Ball.GetColor()
            && position_ == compared_Ball.GetPosition()
            && velocity_ == compared_Ball.GetVelocity()
            && radius_ == compared_Ball.GetRadius()
            && mass_ == compared_Ball.GetMass());
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

  double Ball::GetSpeed() const {
    return glm::length(velocity_);
  }

  float Ball::GetRadius() const {
    return radius_;
  }

  double Ball::GetMass() const {
    return mass_;
  }

  void Ball::SetPosition(glm::vec2& position) {
    position_ = position;
  }

  void Ball::SetVelocity(glm::vec2& velocity) {
    velocity_ = velocity;
  }

}  // namespace bubblebounce