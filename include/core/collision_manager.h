#pragma once

#include <vector>

#include "ball.h"
#include "bubble.h"

namespace bubblebounce {

  /**
   * A class to manage particle calculations for determining particle-wall
   * contact, particle-particle collisions, and the resulting velocities of
   * particle collisions.
   */
  class CollisionManager {
  public:
    /**
       * Constructs an instance of a particle collision calculator.
     */
    CollisionManager();

    bool HasWallCollision(const Ball& ball, char wall_direction,
                          glm::vec2& top_left_corner,
                          glm::vec2& bottom_right_corner);

    bool HasBubbleCollision(const Ball& ball, const Bubble& bubble);

    /**
       * Calls helper method to calculate new particle velocities for the 2
       * colliding particles and updates their respective velocities accordingly.
       * @param particle_1 reference to one of the particles in the collision
       * @param particle_2 reference to the other particle in the collision
     */
    void UpdateBallVelocityUponBubbleCollision(const Ball& ball, const Bubble& bubble);

  private:
    /* Vertical walls correspond to 'x' */
    static constexpr char kXDirection = 'x';
    /* Horizontal walls correspond to 'y' */
    static constexpr char kYDirection = 'y';
  };

}  // namespace bubblebounce
