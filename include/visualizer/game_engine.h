#pragma once

#include <core/level_generator.h>
#include "cinder/gl/gl.h"
#include "core/bubble.h"
#include "core/ball.h"
#include "core/game_level.h"

namespace bubblebounce {
/**
 * The container within where the game interactions occur. This class stores the
 * ball, paddle, and all bubbles and updates them on each frame of the simulation.
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
    
    // determine the left and right corners with the center mouse_position
    void UpdatePaddlePosition(const glm::vec2& mouse_position);
    
    void StartGame(const glm::vec2& target_position);
    
    // Resets the entire game (including points and current level to initial state)
    void NewGame();
    
    // Resets the round (ball, paddle, and bubbles) but maintains game state (points, level, and lives)
    void ResetRound();
    
    /**
     * Checks if the ball fell through the bottom or if there are no more turns 
     * left to the game.
     * @return true if the round is over, false otherwise
     */
    bool IsRoundOver();
    
    bool IsGameOver();
    
    bool IsNewRound();

  private:
    // game window attributes
    const ci::Color kGameEngineWallColor = "white";
    glm::vec2 top_left_;
    glm::vec2 bottom_right_;
    
    Ball ball_;
    Paddle paddle_;
    LevelGenerator level_generator_;
    GameLevel current_level_;
    
    size_t player_lives_;
    size_t player_points_;
    
    // current bubbles within the display
    std::vector<Bubble> bubbles_;
    
    void UpdateForGameOver();
    void UpdateForRoundOver();
    
    
    /**
     * Update ball's velocity accordingly if it collides with the container wall.
     * Horizontal wall collisions reverse y velocity and vertical wall collisions
     * reverse x velocity.
     */
    void UpdateIfWallCollision();

    /**
     * Checks for a collision between the ball and the vector of bubbles.
     * If finds a collisions, reverses the ball's x and y velocities, then 
     * removes the bubble.
     */
    void UpdateIfBubbleCollision();
    
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
    
    void UpdatePoints(const Bubble& bubble);
  };
}  // namespace bubblebounce