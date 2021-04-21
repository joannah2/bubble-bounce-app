#pragma once

#include <core/level_defaults.h>
#include "cinder/gl/gl.h"
#include "core/bubble.h"
#include "core/ball.h"
#include "core/game_level.h"

namespace bubblebounce {
/**
 * The container within where the game interactions occur. This class stores the
 * ball, paddle, and all bubbles and updates them on each frame of the simulation.
 */
  class Container {
  public:
    /**
     * Takes the container boundaries to create window in the display where the 
     * game runs.
     * @param top_left vec2 coordinates of the container's top left corner
     * @param bottom_right_corner_ vec2 coordinates of the container's bottom 
     * right corner
     * @throws illegal_argument if top left corner coordinates are greater than
     * or equal to bottom right corner coordinates
     */
    Container(const glm::vec2& top_left, const glm::vec2& bottom_right);

    /**
     * Displays the container walls and the current positions of the bubbles.
     */
    void Display() const;

    /**
     * Updates the positions and velocities of all bubbles.
     */
    void AdvanceOneFrame();

    std::vector<Bubble>& GetContainerBubbles();
    
    // determine the left and right corners with the center mouse_position
    void UpdatePaddlePosition(const glm::vec2& mouse_position);
    
    /**
     * Checks if the ball fell through the bottom or if there are no more turns 
     * left to the game.
     * @return true if the round is over, false otherwise
     */
    bool IsRoundOver();

    /**
     * Sets the current round's vector of bubbles.
     * @param bubbles bubbles with the level's corresponding positions
     */
    void SetGameBubbles(const std::vector<Bubble>& bubbles);

  private:
    // container attributes
    const ci::Color kContainerWallColor = "white";

    // container coordinates
    glm::vec2 top_left_;
    glm::vec2 bottom_right_;
    
    Ball ball_;
    Paddle paddle_;
    
    // current bubbles within the display
    std::vector<Bubble> bubbles_;
    
    /**
     * Update ball's velocity accordingly if it collides with the container wall.
     * Horizontal wall collisions reverse y velocity and vertical wall collisions
     * reverse x velocity.
     */
    void UpdateVelocitiesIfWallCollision();

    /**
     * Checks for a collision between the ball and the vector of bubbles.
     * If finds a collisions, reverses the ball's x and y velocities, then 
     * removes the bubble.
     */
    void UpdateVelocitiesIfBubbleCollision();
    
    /**
     * Checks if the ball collides with the left or right walls.
     * @return true if there was a collision, false otherwise
     */
    bool HasVerticalWallCollision();
    
    /**
     * Checks if the ball collides with the top wall.
     * @return true if there was a collision, false otherwise
     */
    bool HasTopWallCollision();
    
    /**
     * Checks if the ball hits a bubble.
     * @param bubble the bubble to check for a collision
     * @return true if there was a collision, false otherwise
     */
    bool HasBubbleCollision(const Bubble& bubble);
    
    /**
     * Checks if the ball hits the paddle.
     * @return true if there was a collision, false otherwise
     */
    bool HasHitPaddle();
  };

}  // namespace bubblebounce