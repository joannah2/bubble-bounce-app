#pragma once

#include "game_level.h"
#include "bubble.h"
#include <vector>

namespace bubblebounce {
// TODO:: to be implemented for week 2
/**
 * The class representing each level.
 */
  class GameLevel {
  public:
    GameLevel();
    GameLevel(const size_t& level_number, const size_t & player_lives, 
              const std::vector<Bubble>& bubbles);
    
    size_t GetLevel() const;
    size_t GetPlayerLives() const;
    void SetBubbles(const std::vector<Bubble>& bubbles);
    std::vector<Bubble> GetLevelBubbles() const;
    
  private:
    size_t level_number_{};
    size_t player_lives_{};
    std::vector<Bubble> bubbles_;

  };

}  // namespace bubblebounce