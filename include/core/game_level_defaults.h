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

    /**
     * Creates the preset positions for the bubbles for a given level.
     * @param bubbles bubbles to generate positions for
     * @param level 
     */
    void GenerateBubblePositions(std::vector<Bubble>& bubbles, const size_t& level);

    std::vector<std::vector<Bubble>> GetGameLevelBubbles();
    
    std::vector<Bubble> GenerateBubblePositionsForLevel(const size_t& level, std::vector<Bubble>& bubbles);
    size_t GetLevelDefaultBubbleCount(const size_t& level) const;
    static size_t GetNumberOfLevels();
    
  private:
    std::vector<Bubble> bubbles_;
    size_t level_number_;
    size_t initial_bubble_count;
    glm::vec2 left_corner_;
    glm::vec2 right_corner_;
    static constexpr size_t kNumberOfLevels = 3;
    const std::vector<size_t> initial_bubble_counts{0, 20, 25};
    
    static constexpr int kBubbleMultiplier = 20;
    static constexpr float kBubbleRadius = 40.0f;
    
    void SetLevel1Bubbles(std::vector<Bubble>& bubbles);
    void SetLevel2Bubbles(std::vector<Bubble>& bubbles);
  };

}  // namespace bubblebounce