#pragma once

#include "core/bubble.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "container.h"

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

  private:
    /* Window screen specifications */
    static constexpr int kWindowWidth = 1200;
    static constexpr int kWindowHeight = 900;
    static constexpr int kLeftMargin = 100;
    static constexpr int kRightMargin = 400;
    const ci::Color kBlackBackgroundColor = "black";

    Container container_;
    GameLevelDefaults level_defaults_;
    GameLevel game_level_;
    bool is_new_game_;
    
    std::vector<std::vector<Bubble>> level_bubble_defaults_;
    
  };

}  // namespace bubblebounce