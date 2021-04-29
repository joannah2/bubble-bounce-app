#include "core/bubble.h"

#include <visualizer/bubble_bounce_app.h>

namespace bubblebounce {

  Bubble::Bubble(const ci::Color& color, const glm::vec2& position,
                 const float& radius, BubbleType type, BubbleState state) {
    if (radius <= 0.0f) {
      throw std::invalid_argument("Radius must be greater than 0.");
    }
    color_ = color;
    position_ = position;
    radius_ = radius;
    bubble_type_ = type;
    ValidateBubbleState(state);
    bubble_state_ = state;
    
    // default all bubble state colors to strong bubble
    normal_medium_color_ = color;
    normal_weak_color_ = color;
    special_medium_color_ = color;
    special_weak_color_ = color;
  }

  void Bubble::ValidateBubbleState(const BubbleState& state) {
    if (state == Popped && bubble_type_ == Unpoppable) {
      throw std::invalid_argument("Unpoppable bubble cannot be popped");
    }
  }

  void Bubble::LowerBubbleState() {
    if (bubble_type_ == Unpoppable) return;
    
    switch (bubble_state_) {
      case Strong:
        bubble_state_ = Medium;
        color_ = (bubble_type_ == NormalBubble) ? normal_medium_color_ :
          special_medium_color_;
        break;
      case Medium:
        bubble_state_ = Weak;
        color_ = (bubble_type_ == NormalBubble) ? normal_weak_color_ :
                 special_weak_color_;
        break;
      case Weak:
        bubble_state_ = Popped;
        break;
    }
  }
  
  void Bubble::SetPosition(const glm::vec2& position) {
    position_ = position;
  }

  void Bubble::SetBubbleState(Bubble::BubbleState state) {
    ValidateBubbleState(state);
    bubble_state_ = state;
  }
  
  void Bubble::Draw() const {
    ci::gl::color(color_);
    ci::gl::drawSolidCircle(position_, radius_);
  }

  bool Bubble::operator==(const Bubble& other_bubble) const {
    return (color_ == other_bubble.GetColor()
            && position_ == other_bubble.GetPosition()
            && radius_ == other_bubble.GetRadius()
            && bubble_type_ == other_bubble.GetBubbleType()
            && bubble_state_ == other_bubble.GetBubbleState());
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

  Bubble::BubbleType Bubble::GetBubbleType() const {
    return bubble_type_;
  }

  Bubble::BubbleState Bubble::GetBubbleState() const {
    return bubble_state_;
  }

  void Bubble::SetNormalMediumBubbleColor(const ci::Color& color) {
    normal_medium_color_ = color;
  }

  void Bubble::SetNormalWeakBubbleColor(const ci::Color& color) {
    normal_weak_color_ = color;
  }

  void Bubble::SetSpecialMediumBubbleColor(const ci::Color& color) {
    special_medium_color_ = color;
  }

  void Bubble::SetSpecialWeakBubbleColor(const ci::Color& color) {
    special_weak_color_ = color;
  }

  ci::Color Bubble::GetNormalMediumColor() const {
    return normal_medium_color_;
  }

  ci::Color Bubble::GetNormalWeakColor() const {
    return normal_weak_color_;
  }

  ci::Color Bubble::GetSpecialMediumColor() const {
    return special_medium_color_;
  }

  ci::Color Bubble::GetSpecialWeakColor() const {
    return special_weak_color_;
  }
  
}  // namespace bubblebounce