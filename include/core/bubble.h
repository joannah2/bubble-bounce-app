#pragma once

#include <cinder/Color.h>

#include "glm/glm.hpp"

namespace bubblebounce {

/**
 * Bubble object representing each bubble used in the simulation.
 */
  class Bubble {

  public:

    // represents starting type of the bubble
    // bubble type is unmodifiable
    enum BubbleType {
      NormalBubble,
      Unpoppable
    };

    // represents bubble's current state which is modified each time it is hit
    // allows for increased difficulty by requiring multiple hits to pop a bubble
    enum BubbleState {
      Strong,          
      Cracked,         
      Popped
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

    /**
     * Draws the bubble in the window.
     */
    void Draw() const;

    /**
     * Sets the bubble's state upon a hit from the ball.
     * @param state BubbleState to be changed to
     */
    void SetBubbleState(BubbleState& state);

    /**
     * Gets the type of the bubble
     * @return BubbleType of what kind of bubble it is
     */
    BubbleType GetBubbleType() const;
    
    /**
     * Gets the current state of the bubble.
     * @return BubbleState representing how strong the bubble is
     */
    BubbleState GetBubbleState() const;
    
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
  };

}  // namespace bubblebounce