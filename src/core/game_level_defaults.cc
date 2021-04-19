#include "core/game_level_defaults.h"

namespace bubblebounce {

  GameLevelDefaults::GameLevelDefaults(const glm::vec2& left_corner, const glm::vec2& right_corner) {
    left_corner_ = left_corner;
    right_corner_ = right_corner;
    initial_bubble_count = level_number_ * kBubbleMultiplier;
  }

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

  std::vector<Bubble> GameLevelDefaults::GenerateBubblePositionsForLevel(const size_t& level, std::vector<Bubble>& bubbles) {
    switch (level) {
      case 1:
        SetLevel1Bubbles(bubbles);
        break;
      case 2:
        SetLevel2Bubbles(bubbles);
        break;
    }
    
    
    
    return bubbles_;
  }

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

  size_t GameLevelDefaults::GetLevelDefaultBubbleCount(const size_t& level) const {
    switch (level) {
      case 1:
        return kLevel1BubbleCount;
      case 2:
        return kLevel2BubbleCount;
      default:
        return 0;
    }
  }

  void GameLevelDefaults::SetLevel2Bubbles(std::vector<Bubble> &bubbles) {

  }

}  // namespace bubblebounce