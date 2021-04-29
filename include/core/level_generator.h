#pragma once

#include "game_level.h"
#include "bubble.h"
#include <vector>

namespace bubblebounce {

/**
 * The class generating each level's starting state. 
 */
  class LevelGenerator {
    
  public:
    /**
     * Initializes all game levels with their respective level number, lives, 
     * and bubbles.
     * @param left_corner vec2 coordinates of the game's top left window
     * @param right_corner vec2 coordinates of the game's bottom right window
     */
    LevelGenerator(const glm::vec2& left_corner,
                   const glm::vec2& right_corner);
    
    /**
     * Returns the GameLevel object for a given level.
     * @param level the level of the desired GameLevel
     * @return generated GameLevel object for the level 
     */
    GameLevel GetGeneratedGameLevel(const size_t& level) const;
    
    /**
     * Returns the default bubble count for the given level.
     * @param level level number 
     * @return level size for a given level
     */
    size_t GetLevelDefaultBubbleCount(const size_t& level) const;
    
    /**
     * Gets the number of levels.
     * @return number of levels
     */
    static size_t GetNumberOfLevels();
    
  private:
    // level "0" considered a level
    static constexpr size_t kNumberOfLevels = 2;
    
    /**
     * Vector index is the level to which the value corresponds to
     * position 0 corresponds to an empty level.
     * (ie simplifies indexing a vector_of_bubbles[level] instead of 
     * vector_of_bubbles[level - 1])
     */
    const std::vector<size_t> kInitialBubbleCount{0, 35};
    const std::vector<size_t> kMaxUnpoppableBubbles{0, 4};
    const std::vector<size_t> kMaxSpecialBubbles{0, 7};
    const std::vector<size_t> kInitialStartingLives{0, 3};

    // constants for creating random generation of types of bubbles
    static constexpr size_t kMinRandomDistribution = 0;
    static constexpr size_t kMaxRandomDistribution = 3;
    static constexpr size_t kUnpoppableBubbleValue = 0;
    static constexpr size_t kSpecialBubbleValue = 1;
    
    static constexpr float kBubbleRadius = 40.0f;
    
    const ci::Color kUnpoppableColor = ci::Color("silver");
    const ci::Color kNormalColor = ci::Color("skyblue");
    const ci::Color kSpecialColor = ci::Color("lightpink");
    const ci::Color kSpecialMediumColor = ci::Color("pink");
    const ci::Color kSpecialWeakColor = ci::Color("mistyrose");
    const ci::Color kNormalMediumColor = ci::Color("paleturquoise");
    const ci::Color kNormalWeakColor = ci::Color("lightcyan");

    glm::vec2 left_corner_;
    glm::vec2 right_corner_;
    std::vector<GameLevel> levels_;
    
    void SetBubbleStateColorsForAllTypes(Bubble& bubble);
    
    /**
     * Initializes game levels with respective randomized bubbles.
     */
    void GenerateGameLevels();

    /**
    * Creates the preset positions for the bubbles for a given level.
    * @param bubbles bubbles to generate positions for
    * @param level the corresponding level
    */
    void GenerateBubblePositions(std::vector<Bubble>& bubbles,
                                 const size_t& level);
  };

}  // namespace bubblebounce