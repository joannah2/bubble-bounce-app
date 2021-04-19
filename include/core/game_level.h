#pragma once

#include "game_level.h"
#include "bubble.h"
#include <vector>

namespace bubblebounce {

/**
 * The class representing each level.
 */
  class GameLevel {
  public:
    GameLevel(const size_t& level_number, const std::vector<Bubble>& bubbles);
    
    size_t GetLevel() const;
    std::vector<Bubble> GetLevelBubbles() const;
  private:
    size_t level_number_;
    size_t player_lives_;
    std::vector<Bubble> bubbles_;

  };

}  // namespace bubblebounce