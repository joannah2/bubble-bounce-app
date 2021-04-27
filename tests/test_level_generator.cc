#include <core/level_generator.h>

#include <catch2/catch.hpp>

using bubblebounce::LevelGenerator;
using bubblebounce::GameLevel;

/**
 * Testing Strategy for Level Generator class:
 * - invalid inputs
 * - getters
 * - generated levels upon construction 
 */

TEST_CASE("Test invalid level generator inputs") {
  SECTION("top_left_corner.x > bottom_right_corner.x") {
    REQUIRE_THROWS_AS(
      LevelGenerator(glm::vec2{100, 0}, glm::vec2{50, 50}),
      std::invalid_argument);
  }
  
  SECTION("top_left_corner.x = bottom_right_corner.x") {
    REQUIRE_THROWS_AS(
      LevelGenerator(glm::vec2{50, 0}, glm::vec2{50, 50}),
      std::invalid_argument);
  }
  
  SECTION("top_left_corner.y > bottom_right_corner.y") {
    REQUIRE_THROWS_AS(
      LevelGenerator(glm::vec2{0, 100}, glm::vec2{50, 50}),
      std::invalid_argument);
  }
  
  SECTION("top_left_corner.y > bottom_right_corner.y") {
    REQUIRE_THROWS_AS(
      LevelGenerator(glm::vec2{0, 50}, glm::vec2{50, 50}),
      std::invalid_argument);
  }
  
  SECTION("top_left_corner = bottom_right_corner") {
    REQUIRE_THROWS_AS(
      LevelGenerator(glm::vec2{50, 50}, glm::vec2{50, 50}),
      std::invalid_argument);
  }
  
  SECTION("top_left_corner.x > bottom_right_corner.x and"
          " top_left_corner.y > bottom_right_corner.y") {
    REQUIRE_THROWS_AS(
      LevelGenerator(glm::vec2{100, 100}, glm::vec2{50, 50}),
      std::invalid_argument);
  }
}

TEST_CASE("Test getters") {
  LevelGenerator game(glm::vec2{0, 0},
                      glm::vec2{10, 10});

  SECTION("Starting number of levels") {
    REQUIRE(game.GetNumberOfLevels() == 2);
  }
  
  SECTION("Default bubble count by level") {
    REQUIRE(game.GetLevelDefaultBubbleCount(0) == 0);
    REQUIRE(game.GetLevelDefaultBubbleCount(1) == 35);
  }
  
  SECTION("Invalid high level parameter for default count") {
    REQUIRE_THROWS_AS(game.GetLevelDefaultBubbleCount(2),
                      std::invalid_argument);
  }
}

TEST_CASE("Test game levels generated upon constructor call") {
  LevelGenerator game(glm::vec2{0, 0},
                  glm::vec2{10, 10});
  GameLevel empty_level;
  
  SECTION("Generated level 0") {
    GameLevel level = game.GetGeneratedGameLevel(0);
    REQUIRE(level == empty_level);
  }
  
  SECTION("Generated level one") {
    GameLevel level = game.GetGeneratedGameLevel(1);
    REQUIRE(level.GetLevel() == 1);
    REQUIRE(level.GetPlayerLives() == 5);
    REQUIRE(level.GetPlayerScore() == 0);
    REQUIRE(level.GetLevelBubbles().size() == 35);
  }
  
  SECTION("Invalid high level parameter") {
    REQUIRE_THROWS_AS(game.GetGeneratedGameLevel(2),
                      std::invalid_argument);
  }
}