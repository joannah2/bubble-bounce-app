#pragma once
#include <vector>
#include <cinder/Color.h>

namespace bubblebounce {
  /**
   * Class representing the rectangular paddle used by the player for the ball 
   * to bounce off of. Paddle only moves left and right along the bottom of the 
   * window and is directed by the user's mouse.
   */
  class Paddle {
  public:
    /**
     * Initializes a paddle object with its top left corner and bottom right 
     * corner.
     * @param top_left vec2 coordinates of the paddle's top left corner
     * @param bottom_right vec2 coordinates of the paddle's bottom right corner
     */
    Paddle(const glm::vec2& top_left, const glm::vec2& bottom_right);
    
    /**
     * Sets the x coordinates for the top left corner and the bottom right 
     * corner of the paddle.
     * (y coordinates remain constant because paddle can only move left or right)
     * @param corner_x_values vec2 coordinates with the first value representing 
     * the left corner's x value and the second value representing the right 
     * corner's x value
     */
    void SetCornerXCoordinates(const glm::vec2& corner_x_values);
    
    /**
     * Gets the top left corner position.
     * @return vec2 of the top left corner
     */
    glm::vec2 GetTopLeftPosition() const;
    
    /**
     * Gets the bottom right corner position.
     * @return vec2 of the bottom right corner
     */
    glm::vec2 GetBottomRightPosition() const;
    
    double GetLength() const;
    void Draw() const;

  private:
    glm::vec2 top_left_;
    glm::vec2 bottom_right_;
    double length_;
    double height_;
    static constexpr size_t kHeight = 10;
    const ci::Color kPaddleColor = "brown";
  };
  
} // namespace bubblebounce
