#include "core/game_level.h"

namespace bubblebounce {


  GameLevel::GameLevel(const size_t& level_number, const std::vector<Bubble>& bubbles) {
    level_number_ = level_number;
    bubbles_ = bubbles;
  }

  size_t GameLevel::GetLevel() const {
    return level_number_;
  }

  std::vector<Bubble> GameLevel::GetLevelBubbles() const {
    return bubbles_;
  }

}  // namespace bubblebounce