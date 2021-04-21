#include "core/level_defaults.h"

namespace bubblebounce {

  GameLevelDefaults::GameLevelDefaults(const glm::vec2& left_corner, const glm::vec2& right_corner) {
    left_corner_ = left_corner;
    right_corner_ = right_corner;
  }

  // Temporary bubble position generator for a simple level
  void GameLevelDefaults::GenerateBubblePositions(std::vector<Bubble>& bubbles, const size_t& level) {
    size_t distance = (size_t) kBubbleRadius * 2;
    size_t x_1 = (size_t) left_corner_.x + distance;
    size_t y_1 = (size_t) left_corner_.y + distance;
    size_t bubble_index = 0;

    for (size_t y = y_1; y < right_corner_.y - distance; y += distance) {
      if (bubble_index >= initial_bubble_counts.at(level)) break;
      for (size_t x = x_1; x < right_corner_.x - distance; x += distance) {
        glm::vec2 position = glm::vec2{x, y};
        bubbles.at(bubble_index).SetPosition(position);
        ++bubble_index;
        if (bubble_index >= initial_bubble_counts.at(level)) break;
      }
    }
  }

  // return 2d vector of bubbles to be called in bubblebounce app to set in the container
  std::vector<std::vector<Bubble>> GameLevelDefaults::GetGameLevelBubbles() {
    std::vector<std::vector<Bubble>> level_bubble_defaults;
    std::vector<Bubble> bubbles;
    for (size_t level = 0; level < initial_bubble_counts.size(); ++level) {
      for (size_t i = 0; i < initial_bubble_counts[level]; ++i) {
        Bubble bubble(ci::Color("blue"), glm::vec2(0, 0), 40.0f,
                      Bubble::NormalBubble, Bubble::Strong);
        bubbles.emplace_back(bubble);
      }
      GenerateBubblePositions(bubbles, level);
      level_bubble_defaults.emplace_back(bubbles);
    }
    return level_bubble_defaults;
  }
  
  // When there are more levels:
  // Have each setter for the different levels return the bubbles (not void)
//  std::vector<Bubble> GameLevelDefaults::GenerateBubblePositionsForLevel(const size_t& level, std::vector<Bubble>& bubbles) {
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

  void GameLevelDefaults::SetLevel1Bubbles(std::vector<Bubble>& bubbles) {
    size_t distance = (size_t) bubbles_.at(0).GetRadius() * 2;
    size_t x_1 = (size_t) left_corner_.x + distance;
    size_t y_1 = (size_t) left_corner_.y + distance;
    size_t bubble_index = 0;

    for (size_t y = y_1; y < right_corner_.y - distance; y += distance) {
      if (bubble_index >= initial_bubble_count) break;
      for (size_t x = x_1; x < right_corner_.x - distance; x += distance) {
        glm::vec2 position = glm::vec2{x, y};
        bubbles.at(bubble_index).SetPosition(position);
        ++bubble_index;
        if (bubble_index >= initial_bubble_count) break;
      }
    }
    
  }
  
  void GameLevelDefaults::SetLevel2Bubbles(std::vector<Bubble> &bubbles) {

  }
  
  size_t GameLevelDefaults::GetLevelDefaultBubbleCount(const size_t& level) const {
    return initial_bubble_counts[level];
  }
  
  size_t GameLevelDefaults::GetNumberOfLevels() {
    return kNumberOfLevels;
  }

}  // namespace bubblebounce