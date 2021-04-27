#include <visualizer/game_engine.h>

#include <catch2/catch.hpp>

using bubblebounce::GameEngine;
using bubblebounce::GameLevel;
using bubblebounce::Bubble;

/**
 * Testing Strategy for Game Engine class
 */

TEST_CASE("Test invalid game engine inputs") {
  SECTION("top_left_corner.x > bottom_right_corner.x") {
    REQUIRE_THROWS_AS(
      GameEngine(glm::vec2{100, 0}, glm::vec2{50, 50}),
      std::invalid_argument);
  }
  
  SECTION("top_left_corner.x = bottom_right_corner.x") {
    REQUIRE_THROWS_AS(
      GameEngine(glm::vec2{50, 0}, glm::vec2{50, 50}),
      std::invalid_argument);
  }
  
  SECTION("top_left_corner.y > bottom_right_corner.y") {
    REQUIRE_THROWS_AS(
      GameEngine(glm::vec2{0, 100}, glm::vec2{50, 50}),
      std::invalid_argument);
  }
  
  SECTION("top_left_corner.y > bottom_right_corner.y") {
    REQUIRE_THROWS_AS(
      GameEngine(glm::vec2{0, 50}, glm::vec2{50, 50}),
      std::invalid_argument);
  }
  
  SECTION("top_left_corner = bottom_right_corner") {
    REQUIRE_THROWS_AS(
      GameEngine(glm::vec2{50, 50}, glm::vec2{50, 50}),
      std::invalid_argument);
  }
  
  SECTION("top_left_corner.x > bottom_right_corner.x and"
          " top_left_corner.y > bottom_right_corner.y") {
    REQUIRE_THROWS_AS(
      GameEngine(glm::vec2{100, 100}, glm::vec2{50, 50}),
      std::invalid_argument);
  }
}


TEST_CASE("Test getters and proper level initialization") {
  GameEngine game(glm::vec2{0, 0}, 
                  glm::vec2{10, 10});
  
  SECTION("Get the current white_level") {
    std::vector<Bubble> white_bubbles;
    for (size_t i = 0; i < 5; ++i) {
      Bubble bubble("white", glm::vec2{0,0}, 5.0f,
                    bubblebounce::Bubble::NormalBubble,
                    bubblebounce::Bubble::Strong);
      white_bubbles.emplace_back(bubble);
    }

    GameLevel white_level(1, 5, white_bubbles);
    
    GameLevel level = game.GetCurrentLevel();
    REQUIRE(level == white_level);
  }
}