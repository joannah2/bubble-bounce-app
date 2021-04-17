#include "core/game_level.h"

namespace bubblebounce {


  GameLevel::GameLevel(const glm::vec2& left_corner, const glm::vec2& right_corner) {
    level_number_ = 1;
    left_corner_ = left_corner;
    right_corner_ = right_corner;
    initial_bubble_count = level_number_ * kBubbleMultiplier;
  }

  size_t GameLevel::GetLevel() const {
    return level_number_;
  }

  void GameLevel::GenerateBubblePositions(std::vector<Bubble>& bubbles) {
    size_t distance = (size_t) bubbles.at(0).GetRadius() * 2;
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

  size_t GameLevel::GetInitialBubbleCount() const {
    return initial_bubble_count;
  }


}  // namespace bubblebounce