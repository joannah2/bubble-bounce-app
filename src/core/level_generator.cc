#include <random>
#include "core/level_generator.h"

namespace bubblebounce {

  LevelGenerator::LevelGenerator(const glm::vec2& left_corner,
                                 const glm::vec2& right_corner) {
    // check initial values match
    if (kNumberOfLevels != kInitialBubbleCount.size() 
        || kNumberOfLevels != kMaxUnpoppableBubbles.size()
           || kNumberOfLevels != kMaxSpecialBubbles.size()
              || kNumberOfLevels != kInitialStartingLives.size()) {
      throw std::invalid_argument("Initial values don't match number"
                                  "of levels");
    }
    
    // check corner coordinates
    if (left_corner.x >= right_corner.x  || left_corner.y >= right_corner.y) {
      throw std::invalid_argument("Top left corner coordinates must be "
                                  "less than bottom right corner coordinates.");
    }
    
    left_corner_ = left_corner;
    right_corner_ = right_corner;
    GenerateGameLevels();
  }
  
  void LevelGenerator::GenerateGameLevels() {
    std::vector<Bubble> bubbles;
    
    ci::Color color;
    Bubble::BubbleType type;
    Bubble::BubbleState state;
    size_t unpoppable_count = 0;
    size_t special_count = 0;
    
    int random_int;
    std::random_device random_device;
    std::mt19937 random_engine(random_device());
    std::uniform_int_distribution<int> int_distribution(kMinRandomDistribution, 
                                                        kMaxRandomDistribution);

    for (size_t level = 0; level < kInitialBubbleCount.size(); ++level) {
      for (size_t i = 0; i < kInitialBubbleCount[level]; ++i) {
        random_int = int_distribution(random_engine);
        
        if (random_int == kUnpoppableBubbleValue 
            && unpoppable_count < kMaxUnpoppableBubbles[level]) {
          color = "grey";
          type = Bubble::Unpoppable;
          state = Bubble::Strong;
          ++unpoppable_count;
        } else if (random_int <= kSpecialBubbleValue 
                    && special_count < kMaxSpecialBubbles[level]) {
          color = "pink";
          type = Bubble::SpecialBubble;
          state = Bubble::Strong;
          ++special_count;
        } else {
          color = "teal";
          type = Bubble::NormalBubble;
          state = Bubble::Strong;
        }
        
        Bubble bubble(color, glm::vec2(0, 0), kBubbleRadius, type,
                      state);
        bubbles.emplace_back(bubble);
      }
      GenerateBubblePositions(bubbles, level);
      levels_.emplace_back(GameLevel(level,
                           kInitialStartingLives[level], bubbles));
    }
  }
  
  void LevelGenerator::GenerateBubblePositions(std::vector<Bubble>& bubbles,
                                               const size_t& level) {
    size_t distance = (size_t) kBubbleRadius * 2;
    size_t x_1 = (size_t) left_corner_.x + distance;
    size_t y_1 = (size_t) left_corner_.y + distance;
    size_t bubble_index = 0;

    for (size_t y = y_1; y < right_corner_.y - distance; y += distance) {
      if (bubble_index >= kInitialBubbleCount.at(level)) break;
      for (size_t x = x_1; x < right_corner_.x - distance; x += distance) {
        glm::vec2 position = glm::vec2{x, y};
        bubbles.at(bubble_index).SetPosition(position);
        ++bubble_index;
        if (bubble_index >= kInitialBubbleCount.at(level)) break;
      }
    }
  }
  
  GameLevel LevelGenerator::GetGeneratedGameLevel(const size_t& level) const {
    if (level >= kNumberOfLevels) {
      throw std::invalid_argument("Requested level does not exist");
    }
    return levels_[level];
  }
  
  size_t LevelGenerator::GetLevelDefaultBubbleCount(const size_t& level) const {
    if (level >= kNumberOfLevels) {
      throw std::invalid_argument("Requested level does not exist");
    }
    return kInitialBubbleCount[level];
  }

  size_t LevelGenerator::GetNumberOfLevels() {
    return kNumberOfLevels;
  }
  
}  // namespace bubblebounce