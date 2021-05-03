#pragma once

#include <core/level_generator.h>
#include "cinder/gl/gl.h"
#include "core/bubble.h"
#include "core/ball.h"
#include "core/game_level.h"

namespace bubblebounce {
/**
 * The container within where the game interactions occur. This class stores the
 * ball, paddle, and the game level which contains the bubbles. It updates them
 * correspondingly on each frame of the simulation. Game Engine handles what 
 * the player has control over: the paddle and the ball which they manipulate
 * using the paddle. 
 */
  class GameEngine {
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
    GameEngine(const glm::vec2& top_left, const glm::vec2& bottom_right);

    /**
     * Displays the container walls and the current positions of the bubbles.
     */
    void Display() const;

    /**
     * Updates the positions and velocities of all bubbles.
     */
    void AdvanceOneFrame();
    
    /**
     * Determines the left and right corners for the paddle with the center 
     * of the mouse's location.
     * @param mouse_position vec2 of the mouse position
     */
    void UpdatePaddlePosition(const glm::vec2& mouse_position);
    
    /**
     * Sets the ball's velocity to the given target position.
     * @param target_position vec2 of the position of the mouse on the click
     */
    void StartGame(const glm::vec2& target_position);
    
    /**
     * Resets the entire game; resets ball, paddle, bubbles, points, and lives.
     */
    void NewGame();
    
    /**
     * Resets the round (ball, paddle, and bubbles) but maintains game state 
     * (points, level, and lives)
     */
    void ResetRound();
    
    /**
     * Checks if the ball fell through the bottom
     * @return true if the ball is out, false otherwise
     */
    bool IsBallOut();
    
    /**
     * Retrieves the current level instance.
     * @return GameLevel of the current level
     */
    GameLevel GetCurrentLevel() const;

  private:
    glm::vec2 top_left_;
    glm::vec2 bottom_right_;
    
    Ball ball_;
    Paddle paddle_;
    LevelGenerator level_generator_;
    GameLevel current_level_;   
    
    /**
     * Update ball's velocity accordingly if it collides with the container wall.
     * Horizontal wall collisions reverse y velocity and vertical wall collisions
     * reverse x velocity.
     */
    void UpdateIfWallCollision();
    
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
     * Checks if the ball hits the paddle.
     * @return true if there was a collision, false otherwise
     */
    bool HasHitPaddle();
  };
  
}  // namespace bubblebounce