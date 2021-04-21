#pragma once

#include "game_level.h"
#include "bubble.h"
#include <vector>

namespace bubblebounce {
// TODO:: to be implemented for week 2
/**
 * The class representing each level's starting state. 
 */
  class GameLevelDefaults {
  public:
    GameLevelDefaults(const glm::vec2& left_corner,
                      const glm::vec2& right_corner);

    /**
     * Creates the preset positions for the bubbles for a given level.
     * @param bubbles bubbles to generate positions for
     * @param level the corresponding level
     */
    void GenerateBubblePositions(std::vector<Bubble>& bubbles,
                                 const size_t& level);

    /**
     * Create vector of bubbles for each level to be called by bubble_bounce_app
     * when initializing the 
     * @return 
     */
    std::vector<std::vector<Bubble>> GetGameLevelBubbles();
    
    // TODO:: remove 2d vector getter & storing a copy of all bubbles vectors for each level
    // bubble_bounce_app will call GetGameLevelBubbles(const size_t& level) to get the bubbles for that particular level
    std::vector<Bubble> GetGameLevelBubbles(const size_t& level);
    
    std::vector<Bubble> GenerateBubblePositionsForLevel(const size_t& level,
                                                  std::vector<Bubble>& bubbles);
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
    
    // setters to generate bubble positions for each level
    void SetLevel1Bubbles(std::vector<Bubble>& bubbles);
    void SetLevel2Bubbles(std::vector<Bubble>& bubbles);
  };

}  // namespace bubblebounce