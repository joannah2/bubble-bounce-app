#pragma once
#include <vector>
#include <cinder/Color.h>

namespace bubblebounce {
  
  class Paddle {
  public:

    Paddle(const glm::vec2& position);
    Paddle(const glm::vec2& top_left, const glm::vec2& bottom_right);
    
    void SetXPosition(const glm::vec2& corner_x_values);
    
    glm::vec2 GetTopLeftPosition() const;
    glm::vec2 GetBottomRightPosition() const;
    glm::vec2 GetPosition() const;
    double GetLength() const;
    void Draw() const;

  private:
    glm::vec2 top_left_;
    glm::vec2 bottom_right_;
    glm::vec2 center_;
    double length_;
    double height_;
    static constexpr size_t kHeight = 10;
//    friend class Ball;
  };
  
} // namespace bubblebounce
