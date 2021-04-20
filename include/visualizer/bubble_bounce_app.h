#pragma once

#include "core/bubble.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "container.h"

namespace bubblebounce {

/**
 * An app for visualizing the behavior of an ideal gas.
 * Includes a container for pas bubbles and 3 histograms corresponding
 * to the bubbles by color in the container.
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
     * Update the frame with recalculated bubble positions and velocities.
     */
    void update() override;

    /**
     * Receive keyboard events for adding bubbles by color, removing bubbles,
     * and clearing the container.
     * @param event keyboard key pressed by user
     */
    void keyDown(ci::app::KeyEvent event) override;
    
    void mouseMove(ci::app::MouseEvent event) override;

  private:
    /* Window screen specifications */
    static constexpr int kWindowWidth = 1200;
    static constexpr int kWindowHeight = 900;
    static constexpr int kLeftMargin = 100;
    static constexpr int kRightMargin = 400;
    const ci::Color kBlackBackgroundColor = "black";

    /* Purple bubble specifications */
//    const ci::Color kColorPurple = "purple";
//    static constexpr float kPurplebubbleRadius = 10.0f;
//    static constexpr double kPurplebubbleMass = 10.0;
//    static constexpr double kPurpleBaseVelocity = 5.0;

    Container container_;
    GameLevelDefaults level_defaults_;
    GameLevel game_level_;
    bool is_new_game_;
    
    std::vector<std::vector<Bubble>> level_bubble_defaults_;
    
  };

}  // namespace bubblebounce