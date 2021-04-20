#pragma once

#include <core/game_level_defaults.h>
#include "cinder/gl/gl.h"
#include "core/bubble.h"
#include "core/ball.h"
#include "core/game_level.h"

namespace bubblebounce {
/**
 * The container in which all of the gas particles are contained. This class
 * stores all of the particles and updates them on each frame of the simulation.
 */
  class Container {
  public:
    /**
     * Takes the container boundaries to create container.
     * @param top_left vec2 coordinates of the container's top left corner
     * @param bottom_right_corner_ vec2 coordinates of the container's bottom
     * right corner
     * @throws illegal_argument if top left corner coordinates are greater than
     * or equal to bottom right corner coordinates
     */
    Container(const glm::vec2& top_left, const glm::vec2& bottom_right);

    /**
     * Displays the container walls and the current positions of the particles.
     */
    void Display() const;

    /**
     * Updates the positions and velocities of all particles.
     */
    void AdvanceOneFrame();

    /**
     * Adds a bubble to the container.
     * @param bubble bubble to be added to the container
     */
    void AddBubbleToContainer(const Bubble& bubble);

    /**
     * Removes all bubbles from the container.
     */
    void ClearContainer();

    void RemoveBubble();

    std::vector<Bubble>& GetContainerBubbles();
    
    // determine the left and right corners with the center mouse_position
    void UpdatePaddlePosition(const glm::vec2& mouse_position);
    
    bool IsRoundOver();
    enum Direction {
      kXDirection,
      kYDirection
    };

  private:
    /* Container attributes */
    const ci::Color kContainerWallColor = "white";

    /* Container coordinates */
    glm::vec2 top_left_;
    glm::vec2 bottom_right_;

    /* Store and manage bubbles and ball*/
    Ball ball_;
    std::vector<Bubble> bubbles_;

    // Initial positions

    glm::vec2 ball_position_{450, 750};
    glm::vec2 ball_velocity_ {0, 0};
    
    GameLevelDefaults level_defaults_;
    Paddle paddle_;
    
    /**
     * Update particle velocity accordingly if particle collides with the
     * container wall.
     * Horizontal wall collisions reverse y velocity and vertical wall collisions
     * reverse x velocity.
     */
    void UpdateVelocitiesIfWallCollision();

    /**
     * Update both particle's velocities accordingly if 2 particles collide.
     */
    void UpdateVelocitiesIfBubbleCollision();
    
    bool HasVerticalWallCollision();
    bool HasTopWallCollision();
    bool HasBubbleCollision(const Bubble& bubble);
    bool HasHitPaddle();
   
  };

}  // namespace bubblebounce