#pragma once

#include <cinder/Color.h>

#include "glm/glm.hpp"
#include "paddle.h"


namespace bubblebounce {

/**
 * Ball object used to hit bubbles and bounce off paddle.
 */
  class Ball{
  public:
    /**
     * Constructor that initializes Ball attributes.
     * @param color string representing the Ball's color
     * @param position vec2 representing the Ball's position
     * @param velocity vec2 representing the Ball's velocity
     * @param radius float representing the Ball's radius
     * @throws invalid_argument if radius is less than or equal to 0
     */
    Ball(const ci::Color& color, const glm::vec2& position,
         const glm::vec2& velocity, const float& radius);

    /**
     * Draws the ball to the UI.
     */
    void Draw() const;
    
    /**
     * Update the position of the Ball by incrementing it by its velocity.
     */
    void IncreasePositionByVelocity();
    
    /**
     * Sets the ball's velocity according to the position determined by the user's
     * mouse click. Creates a magnitude of the velocity and multiplies by the 
     * velocity multiplier.
     * @param target_position vec2 of the position where the user clicks 
     */
    void SetVelocityByTarget(const glm::vec2& target_position);

    /**
     * Sets the velocity of the ball.
     * @param velocity vec2 of the ball's velocity
     */
    void SetVelocity(const glm::vec2& velocity);

    /**
     * Sets the color of the ball.
     * @param color ci::Color of the ball's color
     */
    void SetColor(const ci::Color& color);
    
    /**
     * Reverse the x velocity when the Ball bounces off a vertical wall.
     */
    void ReverseXVelocity();

    /**
     * Reverse the y velocity when the Ball bounces off a horizontal wall.
     */
    void ReverseYVelocity();

    /**
     * Get the color of the Ball.
     * @return ci::Color representing the Ball's color
     */
    ci::Color GetColor() const;

    /**
     * Get the 2D vector of the Ball's x and y position.
     * @return vec2 of the Ball's x and y position
     */
    glm::vec2 GetPosition() const;

    /**
     * Get the 2D vector of the Ball's x and y velocities.
     * @return vec2 of the Ball's x and y velocities
     */
    glm::vec2 GetVelocity() const;

    /**
     * Get the radius of the Ball.
     * @return float representing the Ball's radius
     */
    float GetRadius() const;

    /**
     * Sets the Ball's position.
     * @param position vec2 of the Ball's x and y coordinates
     */
    void SetPosition(const glm::vec2& position);

    /**
     * Resets the ball's attributes for reinitializing 
     * @param color ci::Color of the ball
     * @param position vec2 of the ball's position
     * @param velocity vec2 of the ball's velocity
     * @param radius float of the ball's radius
     */
    void ResetAttributes(const ci::Color& color, const glm::vec2& position,
                         const glm::vec2& velocity, const float& radius);
    
    /**
     * Sets the ball's velocity according to the bubble's position that it hits
     * @param bubble_position vec2 of the bubble's position
     */
    void SetVelocityByCollision(const glm::vec2& bubble_position);

  private:
    // multiplier for the calculated unit vector of the ball's new velocity 
    // after a hit
    static constexpr size_t kVelocityMultiplier = 9;
    
    float radius_;
    ci::Color color_;
    glm::vec2 position_;
    glm::vec2 velocity_;
  };
  
}  // namespace bubblebounce