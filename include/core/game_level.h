#pragma once

#include "game_level.h"
#include "bubble.h"
#include "ball.h"

#include <vector>

namespace bubblebounce {
/**
 * The class representing each level of the game.
 * Has a level, initial lives count, and vector of the bubbles for that level.
 */
  class GameLevel {
  public:
    /**
     * Empty constructor to initialize a game level instance without a level 
     * generator.
     */
    GameLevel();
    
    /**
     * Initialize a game level with it's number, number of lives, the bubbles 
     * for the corresponding level.
     * @param level_number the game level
     * @param player_lives the number of starting lives
     * @param bubbles the bubbles for the level
     */
    GameLevel(const size_t& level_number, const size_t& player_lives, 
              const std::vector<Bubble>& bubbles);
//    /**
//     * Update ball's velocity accordingly if it collides with the container wall.
//     * Horizontal wall collisions reverse y velocity and vertical wall collisions
//     * reverse x velocity.
//     */
//    void UpdateIfWallCollision(Ball& ball);

    /**
     * Checks for a collision between the ball and the vector of bubbles.
     * If finds a collisions, reverses the ball's x and y velocities, then 
     * removes the bubble.
     */
    void UpdateIfBubbleCollision(Ball& ball);
//
//    /**
//     * Checks if the ball collides with the left or right walls.
//     * @return true if there was a collision, false otherwise
//     */
//    bool HasVerticalWallCollision(const Ball& ball);
//
//    /**
//     * Checks if the ball collides with the top wall.
//     * @return true if there was a collision, false otherwise
//     */
//    bool HasTopWallCollision(const Ball& ball);

    /**
     * Checks if the ball hits a bubble.
     * @param bubble the bubble to check for a collision
     * @return true if there was a collision, false otherwise
     */
    bool HasBubbleCollision(const Bubble& bubble, const Ball& ball);

    void UpdatePoints(const Bubble& bubble);






    // ------------------------------------------
    /**
     * Overrides if the level being compared to has the same number, lives, 
     * and bubbles.
     * @param other_level Ball to compare to
     * @return true if the Ball has the same attributes
     */
    bool operator==(const GameLevel& other_level) const;
    
    /**
     * Gets the level number.
     * @return leve number
     */
    size_t GetLevel() const;
    
    /**
     * Gets the player's starting lives.
     * @return number of lives for the game level
     */
    size_t GetPlayerLives() const;
    
    /**
    * Gets the bubbles of the level.
    * @return the bubbles of the level
    */
    std::vector<Bubble> GetLevelBubbles() const;
    
    /**
     * Sets the bubbles for the game level.
     * @param bubbles the bubbles for the level
     */
    void SetBubbles(const std::vector<Bubble>& bubbles);
    
  private:
    size_t level_number_;
    size_t player_lives_;
    size_t player_score_;
    std::vector<Bubble> bubbles_;
  };

}  // namespace bubblebounce