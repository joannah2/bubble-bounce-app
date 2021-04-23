#include <random>
#include "core/level_generator.h"

namespace bubblebounce {

  LevelGenerator::LevelGenerator(const glm::vec2& left_corner,
                                 const glm::vec2& right_corner) {
    left_corner_ = left_corner;
    right_corner_ = right_corner;
  }

  // return 2d vector of bubbles to be called in bubblebounce app to set in the container
  std::vector<std::vector<Bubble>> LevelGenerator::GetGameLevelBubbles() {
    std::vector<std::vector<Bubble>> level_bubble_defaults;
    std::vector<Bubble> bubbles;
    ci::Color color;
    Bubble::BubbleType type;
    Bubble::BubbleState state;
    int rand;
    size_t unpoppable_count = 0;
    size_t special_count = 0;
    
    std::random_device random_device;
    std::mt19937 random_engine(random_device());
    std::uniform_int_distribution<int> int_distribution(0, 3);
    
    for (size_t level = 0; level < kInitialBubbleCount.size(); ++level) {
      for (size_t i = 0; i < kInitialBubbleCount[level]; ++i) {
        rand = int_distribution(random_engine);
        if (rand == 0 && unpoppable_count < kInitialUnpoppableBubbles[level]) {
          color = "grey";
          type = Bubble::Unpoppable;
          state = Bubble::Strong;
          ++unpoppable_count;
        } else if (rand < 1 && special_count < kInitialSpecialBubbles[level]) {
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
      level_bubble_defaults.emplace_back(bubbles);
    }
    return level_bubble_defaults;
  }
  
  // Temporary bubble position generator for a simple level
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
  // When there are more levels:
  // Have each setter for the different levels return the bubbles (not void)
//  std::vector<Bubble> LevelGenerator::GenerateBubblePositionsForLevel(const size_t& level, std::vector<Bubble>& bubbles) {
//    // check the given bubbles match the size
//    
//    switch (level) {
//      case 1:
//        SetLevel1Bubbles(bubbles);
//        break;
//      case 2:
//        SetLevel2Bubbles(bubbles);
//        break;
//    }
//    
//    return bubbles_;
//  }
//
//  void LevelGenerator::SetLevel1Bubbles(std::vector<Bubble>& bubbles) {
//    size_t distance = (size_t) bubbles_.at(0).GetRadius() * 2;
//    size_t x_1 = (size_t) left_corner_.x + distance;
//    size_t y_1 = (size_t) left_corner_.y + distance;
//    size_t bubble_index = 0;
//
//    for (size_t y = y_1; y < right_corner_.y - distance; y += distance) {
//      if (bubble_index >= initial_bubble_count) break;
//      for (size_t x = x_1; x < right_corner_.x - distance; x += distance) {
//        glm::vec2 position = glm::vec2{x, y};
//        bubbles.at(bubble_index).SetPosition(position);
//        ++bubble_index;
//        if (bubble_index >= initial_bubble_count) break;
//      }
//    }
//  }
  
  void LevelGenerator::SetLevel2Bubbles(std::vector<Bubble> &bubbles) {

  }
  
  size_t LevelGenerator::GetLevelDefaultBubbleCount(const size_t& level) const {
    return kInitialBubbleCount[level];
  }
  
  size_t LevelGenerator::GetNumberOfLevels() {
    return kNumberOfLevels;
  }

  glm::vec2 LevelGenerator::GenerateBallStartingVelocity() const {
    std::random_device random_device;
    std::mt19937 random_engine(random_device());
    std::uniform_real_distribution<float> distribution(9.99f, 10.01f);
    glm::vec2 velocity{distribution(random_engine), -1 * distribution(random_engine)};
    return velocity;
  }

}  // namespace bubblebounce