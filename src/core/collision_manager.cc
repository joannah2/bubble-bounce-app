#include "core/collision_manager.h"

namespace bubblebounce {

  CollisionManager::CollisionManager() {
  }

  bool CollisionManager::HasWallCollision(const Ball& ball,
                                             char wall_direction,
                                             glm::vec2& top_left_corner,
                                             glm::vec2& bottom_right_corner) {
    if (wall_direction == kXDirection) {
      return ((ball.GetPosition().x - ball.GetRadius()
               <= top_left_corner.x) && ball.GetVelocity().x < 0)
             || ((ball.GetPosition().x + ball.GetRadius()
                  >= bottom_right_corner.x) && ball.GetVelocity().x > 0);
    }

    if (wall_direction == kYDirection) {
      return ((ball.GetPosition().y - ball.GetRadius()
               <= top_left_corner.y) && ball.GetVelocity().y < 0)
             || ((ball.GetPosition().y + ball.GetRadius()
                  >= bottom_right_corner.y) && ball.GetVelocity().y > 0);
    }
    return false;
  }

  bool CollisionManager::HasBubbleCollision(const Ball& ball,
                                               const Bubble& bubble) {
    // if the ball is going in the direction of the bubble and the radius intersect
    return false;
  }
  void CollisionManager::UpdateBallVelocityUponBubbleCollision(
    const Ball& ball, const Bubble& bubble) {
    // multiply velocity by -1
  }

}  // namespace bubblebounce