#include "core/game_level.h"

namespace bubblebounce {
  
  GameLevel::GameLevel() {
    level_number_ = 0;
    player_lives_ = 0;
  }

  GameLevel::GameLevel(const size_t& level_number, const size_t& player_lives,
                       const std::vector<Bubble>& bubbles) {
    level_number_ = level_number;
    player_lives_ = player_lives;
    bubbles_ = bubbles;
  }

  void GameLevel::SetBubbles(const std::vector<Bubble>& bubbles) {
    bubbles_ = bubbles;
  }
  
  size_t GameLevel::GetLevel() const {
    return level_number_;
  }

  size_t GameLevel::GetPlayerLives() const {
    return player_lives_;
  }

  std::vector<Bubble> GameLevel::GetLevelBubbles() const {
    return bubbles_;
  }
}  // namespace bubblebounce