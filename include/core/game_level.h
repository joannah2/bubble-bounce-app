#pragma once

#include "game_level.h"
#include "bubble.h"
#include <vector>

namespace bubblebounce {

/**
 * The class representing each level's starting state.
 */
  class GameLevel {
  public:
    GameLevel(const glm::vec2& left_corner, const glm::vec2& right_corner);
    
    //generate the positions for the bubbles at the game level 
    void GenerateBubblePositions(std::vector<Bubble>& bubbles);

    size_t GetLevel() const;
    size_t GetInitialBubbleCount() const;
  private:
    size_t level_number_;
    size_t initial_bubble_count;
    glm::vec2 left_corner_;
    glm::vec2 right_corner_;
    static constexpr int kBubbleMultiplier = 20;
    static constexpr size_t kNumberOfRows = 3;
  };

}  // namespace bubblebounce