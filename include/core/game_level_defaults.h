#pragma once

#include "game_level.h"
#include "bubble.h"
#include <vector>

namespace bubblebounce {

/**
 * The class representing each level's starting state.
 */
  class GameLevelDefaults {
  public:
    GameLevelDefaults(const glm::vec2& left_corner, const glm::vec2& right_corner);

    //generate the positions for the bubbles at the game level 
    void GenerateBubblePositions(std::vector<Bubble>& bubbles, const size_t& level);
    std::vector<Bubble> GenerateBubblePositionsForLevel(const size_t& level, std::vector<Bubble>& bubbles);
    size_t GetLevelDefaultBubbleCount(const size_t& level) const;
  
  private:
    std::vector<Bubble> bubbles_;
    size_t level_number_;
    size_t initial_bubble_count;
    glm::vec2 left_corner_;
    glm::vec2 right_corner_;
    static constexpr int kBubbleMultiplier = 20;
    static constexpr size_t kNumberOfRows = 3;
    static constexpr size_t kLevel1BubbleCount = 20;
    static constexpr size_t kLevel2BubbleCount = 40;
    static constexpr float kBubbleRadius = 40.0f;
    const std::vector<size_t> initial_bubble_counts{0, 20, 40};
    
    void SetLevel1Bubbles(std::vector<Bubble>& bubbles);
    void SetLevel2Bubbles(std::vector<Bubble>& bubbles);
  };

}  // namespace bubblebounce