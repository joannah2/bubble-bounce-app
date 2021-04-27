#pragma once

#include "game_level.h"
#include "bubble.h"
#include "ball.h"

#include <vector>

namespace bubblebounce {
/**
 * The class representing each level of the game.
 * Has a level, initial lives count, and vector of the bubbles for that level.
 * Also keeps track of the initial bubbles for the level so it can be reset.
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

    /**
     * Checks for a collision between the ball and the vector of bubbles.
     * If finds a collisions, reverses the ball's x and y velocities, then 
     * removes the bubble.
     */
    void UpdateIfBubbleCollision(Ball& ball);

    /**
     * Determines if the level was won if the player popped all the bubbles and 
     * still have lives remaining.
     * @return true if the player won, false otherwise
     */
    bool IsLevelWon() const;
    
    /**
     * Determines if the level was lost if the player ran out of lives.
     * @return true if they lost the level, false otherwise
     */
    bool IsLevelLost() const;
    
    /**
     * Returns if the game is still in play.
     * @return true if the player won or lost, false otherwise
     */
    bool IsLevelOver() const;
    
    /**
     * Resets the bubbles to the starting bubbles for that round and reduces 
     * the number of player lives.
     */
    void ResetLevelForRound();
    
    /**
     * Draws the bubbles in the current game level to the screen.
     */
    void Draw() const;
    
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
     * Gets the player's current number of lives.
     * @return current number of lives
     */
    size_t GetPlayerLives() const;

    /**
     * Gets the player's current score.
     * @return current score
     */
    size_t GetPlayerScore() const;
    
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
    size_t kNormalBubbleValue = 1;
    size_t kSpecialBubbleValue = 3;
    
    size_t level_number_;
    size_t player_lives_;
    size_t player_score_;
    std::vector<Bubble> bubbles_;
    std::vector<Bubble> initial_level_bubbles_;

    /**
     * Checks if the ball hits a bubble.
     * @param bubble the bubble to check for a collision
     * @return true if there was a collision, false otherwise
     */
    bool HasBubbleCollision(const Bubble& bubble, const Ball& ball);

    /**
     * Updates the player's score based on the bubble type.
     * @param bubble bubble that is to be popped
     */
    void UpdatePoints(const Bubble& bubble);
    
    /**
     * Checks if all poppable bubbles are popped.
     * @return true if the poppable bubbles are popped, false otherwise
     */
    bool AreAllPoppableBubblesPopped() const;
  };

}  // namespace bubblebounce