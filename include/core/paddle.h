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
     * @param color ci::Color representing paddle color
     */
    Paddle(const glm::vec2& top_left, const glm::vec2& bottom_right,
           const ci::Color& color);
    
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
    
    /**
     * Get paddle length.
     * @return double representing paddle length
     */
    double GetLength() const;
    
    /**
     * Get paddle color.
     * @return ci::Color representing paddle color
     */
    ci::Color GetColor() const;
    
    /**
     * Draws the paddle to UI.
     */
    void Draw() const;
    
    /**
     * Resets all paddle attributes to new given values.
     * @param top_left vec2 representing top left corner
     * @param bottom_right vec2 representing bottom right corner
     * @param color ci::Color representing the paddle color
     */
    void ResetAttributes(const glm::vec2& top_left, const glm::vec2& bottom_right,
                         const ci::Color& color);

  private:
    const std::string kPaddleAsset = "paddle.jpg";
    
    glm::vec2 top_left_;
    glm::vec2 bottom_right_;
    double length_;
    ci::Color color_;
  };
  
} // namespace bubblebounce
