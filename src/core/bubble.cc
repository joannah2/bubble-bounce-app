#include "core/bubble.h"

#include <visualizer/bubble_bounce_app.h>

namespace bubblebounce {

  Bubble::Bubble(const ci::Color& color, const glm::vec2& position, const float& radius,
                 BubbleType type, BubbleState state) {
    if (radius <= 0.0f) {
      throw std::invalid_argument("Radius and mass must be greater than 0.");
    }
    color_ = color;
    position_ = position;
    radius_ = radius;
    bubble_state_ = state;
    bubble_type_ = type;
  }

  void Bubble::Draw() const {
    ci::gl::color(color_);
    ci::gl::drawSolidCircle(position_, radius_);
  }

  ci::Color Bubble::GetColor() const {
    return color_;
  }

  glm::vec2 Bubble::GetPosition() const {
    return position_;
  }

  float Bubble::GetRadius() const {
    return radius_;
  }

  void Bubble::SetPosition(const glm::vec2& position) {
    position_ = position;
  }

  void Bubble::SetBubbleState(Bubble::BubbleState& state) {
    bubble_state_ = state;
  }

  Bubble::BubbleType Bubble::GetBubbleType() const {
    return bubble_type_;
  }

  Bubble::BubbleState Bubble::GetBubbleState() const {
    return bubble_state_;
  }

}  // namespace bubblebounce