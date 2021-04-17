#pragma once

#include <cinder/Color.h>

#include "glm/glm.hpp"
#include "paddle.h"


namespace bubblebounce {

/**
 * Ball object used to hit bubbles
 */
  class Ball{
  public:
    /**
     * Constructor that initializes Ball attributes.
     * @param color string representing the Ball's color
     * @param position vec2 representing the Ball's position
     * @param velocity vec2 representing the Ball's velocity
     * @param radius float representing the Ball's radius
     * @param mass double representing the Ball's mass
     * @throws invalid_argument if radius or mass are less than or equal to 0
     */
    Ball(const ci::Color& color, const glm::vec2& position,
         const glm::vec2& velocity, const float& radius, const double& mass);

    void Draw() const;
    
    /**
     * Update the position of the Ball by incrementing it by its velocity.
     */
    void IncreasePositionByVelocity();

    /**
     * Update the velocity with a newly calculated velocity after Ball
     * collision.
     * @param velocity
     */
    void SetVelocity(const glm::vec2& velocity);

    /**
     * Reverse the x velocity when the Ball bounces off a vertical wall.
     */
    void ReverseXVelocity();

    /**
     * Reverse the y velocity when the Ball bounces off a horizontal wall.
     */
    void ReverseYVelocity();

    /**
     * Overrides if the Ball being compared to has the same color, position,
     * velocity, radius, and mass.
     * @param compared_Ball Ball to compare to
     * @return true if the Ball has the same attributes
     */
    bool operator==(const Ball& compared_Ball) const;

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
     * Get the speed of the Ball.
     * @return double representing the Ball's speed
     */
    double GetSpeed() const;

    /**
     * Get the radius of the Ball.
     * @return float representing the Ball's radius
     */
    float GetRadius() const;

    /**
     * Get the mass of the Ball.
     * @return double representing the Ball's mass
     */
    double GetMass() const;

    /**
     * Sets the Ball's position.
     * @param position vec2 of the Ball's x and y coordinates
     */
    void SetPosition(glm::vec2& position);

    /**
     * Sets the Ball's velocity.
     * @param position vec2 of the Ball's x and y velocities
     */
    void SetVelocity(glm::vec2& velocity);

  private:
    float radius_;
    double mass_;
    ci::Color color_;
    glm::vec2 position_;
    glm::vec2 velocity_;

  };
  

}  // namespace bubblebounce