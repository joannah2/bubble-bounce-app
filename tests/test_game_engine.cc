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
  
  SECTION("Get the current level") {
    GameLevel level = game.GetCurrentLevel();
    REQUIRE(level.GetLevel() == 1);
    REQUIRE(level.GetPlayerScore() == 0);
    REQUIRE(level.GetPlayerLives() == 5);
    REQUIRE(level.GetLevelBubbles().size() == 35);
  }
}