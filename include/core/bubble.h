#pragma once

#include <cinder/Color.h>

#include "glm/glm.hpp"

namespace bubblebounce {

/**
 * Bubble object representing each bubble used in the simulation.
 */
  class Bubble {

  public:

    enum BubbleType {
      NormalBubble,
      CrackedBubble,
      SplitBubble,
    };

    enum BubbleState {
      nUnbreakable,   // Steel Chestnut
      Strong,   // Solid  Chestnut
      Medium,        // Normal  Chestnut
      Thin,          // Cracked Chestnut
      nOpen           // split Chestnut
    };

    /**
     * Constructor that initializes bubble attributes.
     * @param color string representing the bubble's color
     * @param position vec2 representing the bubble's position
     * @param velocity vec2 representing the bubble's velocity
     * @param radius float representing the bubble's radius
     * @param mass double representing the bubble's mass
     * @throws invalid_argument if radius or mass are less than or equal to 0
     */
    Bubble(const ci::Color& color, const glm::vec2& position, const float& radius,
           BubbleType type, BubbleState state);

    void Draw() const;
    
    void SetBubbleType(BubbleType& type);

    void SetBubbleState(BubbleState& state);

    enum BubbleType GetBubbleType() const;
    enum BubbleState GetBubbleState() const;

    /**
     * Overrides if the bubble being compared to has the same color, position,
     * velocity, radius, and mass.
     * @param compared_bubble bubble to compare to
     * @return true if the bubble has the same attributes
     */
    bool operator==(const Bubble& compared_bubble) const;

    /**
     * Get the color of the bubble.
     * @return ci::Color representing the bubble's color
     */
    ci::Color GetColor() const;

    /**
     * Get the 2D vector of the bubble's x and y position.
     * @return vec2 of the bubble's x and y position
     */
    glm::vec2 GetPosition() const;


//  /**
//   * Get the speed of the bubble.
//   * @return double representing the bubble's speed
//   */
//  double GetSpeed() const;

    /**
     * Get the radius of the bubble.
     * @return float representing the bubble's radius
     */
    float GetRadius() const;

    /**
     * Sets the bubble's position.
     * @param position vec2 of the bubble's x and y coordinates
     */
    void SetPosition(const glm::vec2& position);


  private:
    float radius_;
//  double mass_;
    ci::Color color_;
    glm::vec2 position_;
//  glm::vec2 velocity_;

    BubbleType bubble_type_;
    BubbleState bubble_state_;
//  
//    friend class Gamelevel;
//    friend class Ball;
  };

}  // namespace bubblebounce