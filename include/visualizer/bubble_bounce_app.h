#pragma once

#include "core/bubble.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "game_engine.h"
#include "game_display.h"

namespace bubblebounce {

/**
 * A bubble bounce game app where the user controls a paddle with their mouse to
 * bounce a ball off of with the goal of popping all the bubbles. The paddle can
 * only move left and right, and the ball must not fall through the bottom of 
 * the game window (container).
 */
  class BubbleBounceApp : public ci::app::App {
    
  public:
    /**
     * Creates a new bubble bounce app.
     */
    BubbleBounceApp();

    /**
     * Render the game simulation display.
     */
    void draw() override;

    /**
     * Update the frame with recalculated ball positions, paddle, and bubbles.
     */
    void update() override;

    /**
     * Receive keyboard events for adding bubbles by color, removing bubbles,
     * and clearing the container.
     * @param event keyboard key pressed by user
     */
    void keyDown(ci::app::KeyEvent event) override;
    
    /**
     * Receive mouse events for moving the paddle left and right by the mouse's
     * x coordinate.
     * @param event mouse movement by user
     */
    void mouseMove(ci::app::MouseEvent event) override;

    /**
     * Receive mouse event for launching the ball when mouse is clicked, only 
     * if the game is waiting for the user to begin.
     * @param event mouse event storing click information
     */
    void mouseDown(ci::app::MouseEvent event) override;
 
  private:
    // window screen specifications
    static constexpr int kWindowWidth = 1200;
    static constexpr int kWindowHeight = 900;
    
    const glm::vec2 kGameWindowTopLeft{100, 100};
    const glm::vec2 kGameWindowBottomRight{750, 800};
    const glm::vec2 kPanelTopLeft{800, 100};
    const glm::vec2 kPanelBottomRight{1100, 850};

    GameEngine game_engine_;
    GameDisplay game_display_;
    
    bool is_paused_;
    bool is_new_round_;
    bool is_game_over_;
  };

}  // namespace bubblebounce