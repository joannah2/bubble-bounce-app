#pragma once

#include <cinder/Color.h>

#include "glm/glm.hpp"

namespace bubblebounce {

/**
 * Bubble object representing each bubble used in the game.
 */
  class Bubble {

  public:
    /** 
     * Represents starting type of the bubble (bubble type is unmodifiable)
     */
    enum BubbleType {
      NormalBubble,
      SpecialBubble,
      Unpoppable
    };
    
    /** 
     * Represents bubble's current state which is modified each time it is hit
     * allows for increased difficulty by requiring multiple hits to pop a bubble
     */
    enum BubbleState {
      Strong,          
      Medium,         
      Weak,
      Popped
    };

    /**
     * Constructor that initializes bubble attributes.
     * @param color string representing the bubble's color
     * @param position vec2 representing the bubble's position
     * @param velocity vec2 representing the bubble's velocity
     * @param radius float representing the bubble's radius
     * @throws invalid_argument if radius is less than or equal to 0
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
    void SetBubbleState(BubbleState state);
    
    /**
     * Lowers the BubbleState by one level.
     * (Strong becomes Medium, Medium becomes Weak, Weak becomes Popped,
     * Popped remains popped)
     */
    void LowerBubbleState();
    
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
    ci::Color color_;
    glm::vec2 position_;
    BubbleType bubble_type_;
    BubbleState bubble_state_;
    
    /**
     * Checks the state to set the bubble doesn't contradict bubble type
     * @param state state to set the bubble's state to
     */
    void ValidateBubbleState(const BubbleState& state);
  };

}  // namespace bubblebounce