#include <core/ball.h>
#include "core/game_level.h"

namespace bubblebounce {
  
  GameLevel::GameLevel() {
    level_number_ = 0;
    player_lives_ = 0;
    player_score_ = 0;
  }

  GameLevel::GameLevel(const size_t& level_number, const size_t& player_lives,
                       const std::vector<Bubble>& bubbles) {
    player_score_ = 0;
    level_number_ = level_number;
    player_lives_ = player_lives;
    initial_level_bubbles_ = bubbles;
    bubbles_ = bubbles;
  }

  void GameLevel::UpdateIfBubbleCollision(Ball& ball) {
    for (size_t i = 0; i < bubbles_.size(); ++i) {
      if (HasBubbleCollision(bubbles_[i], ball)) {
        glm::vec2 ball_velocity = ball.GetVelocity();

        // adjust new bubble state
        if (bubbles_[i].GetBubbleType() != Bubble::Unpoppable) {
          bubbles_[i].LowerBubbleState();
        }

        // adjust new ball velocity
        ball.ReverseYVelocity();

        // handle popping a bubble
        if (bubbles_[i].GetBubbleState() == Bubble::Popped) {
          UpdatePoints(bubbles_[i]);
          bubbles_.erase(bubbles_.begin() + i);
        }
        break;
      }
    }
  }

  void GameLevel::UpdatePoints(const Bubble& bubble) {
    switch (bubble.GetBubbleType()) {
      case Bubble::NormalBubble:
        player_score_ += kNormalBubbleValue;
        break;
      case Bubble::SpecialBubble:
        player_score_ += kSpecialBubbleValue;
        break;
    }
  }
  
  bool GameLevel::HasBubbleCollision(const Bubble& bubble, const Ball& ball) {
    /*
     * Variable names follow common arithmetic variable convention
     * v = velocity, r = radius, x = position
     */
    glm::vec2 v_1 = ball.GetVelocity();
    glm::vec2 v_2 = glm::vec2{0, 0};
    double r_1 = ball.GetRadius();
    double r_2 = ball.GetRadius();
    glm::vec2 x_1 = ball.GetPosition();
    glm::vec2 x_2 = bubble.GetPosition();

    return (glm::distance(x_1, x_2) <= r_1 + r_2) && (glm::dot((v_1 - v_2),
                                                               x_1 - x_2) < 0);
  }

  bool GameLevel::IsLevelWon() const {
    return AreAllPoppableBubblesPopped() && player_lives_ > 0;
  }
  
  bool GameLevel::AreAllPoppableBubblesPopped() const {
    for (const Bubble& bubble: bubbles_) {
      if (bubble.GetBubbleType() != Bubble::Unpoppable) {
        if (bubble.GetBubbleState() != Bubble::Popped) {
          return false;
        }
      }
    }
    return true;
  }
  
  bool GameLevel::IsLevelLost() const {
    return player_lives_ == 0;
  }

  bool GameLevel::IsLevelOver() const {
    return IsLevelWon() || IsLevelLost();
  }
  
  void GameLevel::Draw() const {
    for (const Bubble& bubble : bubbles_) {
      bubble.Draw();
    }
  }

  void GameLevel::ResetLevelForRound() {
    bubbles_ = initial_level_bubbles_;
    --player_lives_;
    player_score_ = 0;
  }
  
  size_t GameLevel::GetPlayerScore() const {
    return player_score_;
  }
  
  bool GameLevel::operator==(const GameLevel& other_level) const {
    return (level_number_ == other_level.GetLevel()
            && player_lives_ == other_level.GetPlayerLives()
            && bubbles_ == other_level.GetLevelBubbles());
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