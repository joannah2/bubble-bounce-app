#pragma once

#include "game_level.h"
#include "bubble.h"
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
    std::vector<Bubble> bubbles_;
  };

}  // namespace bubblebounce