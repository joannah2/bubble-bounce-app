#include <core/game_level.h>
#include <core/bubble.h>

#include <catch2/catch.hpp>

using bubblebounce::GameLevel;
using bubblebounce::Bubble;

/**
 * Test Strategy for Game Level
 * - initializing attributes
 *  - getters/setters for bubbles vector
 */
TEST_CASE("Test constructor and retrieving level attributes") {
  SECTION("Empty constructor proper initialization") {
    GameLevel level;
    REQUIRE(level.GetLevel() == 0);
    REQUIRE(level.GetPlayerLives() == 0);
    REQUIRE(level.GetLevelBubbles().empty());
  }

  SECTION("GameLevel invalid starting lives") {
    std::vector<Bubble> bubbles;
    REQUIRE_THROWS_AS(GameLevel(1, 0, bubbles), 
                      std::invalid_argument);
  }

  SECTION("GameLevel proper initialization") {
    std::vector<Bubble> bubbles;
    GameLevel level(1, 5, bubbles);
    REQUIRE(level.GetLevel() == 1);
    REQUIRE(level.GetPlayerLives() == 5);
    REQUIRE(level.GetLevelBubbles().empty());
  }
}

TEST_CASE("Test Getters/Setters for bubbles") {
  std::vector<Bubble> white_bubbles;
  for (size_t i = 0; i < 5; ++i) {
    Bubble bubble("white", glm::vec2{0,0}, 5.0f,
                  bubblebounce::Bubble::NormalBubble,
                  bubblebounce::Bubble::Strong);
    white_bubbles.emplace_back(bubble);
  }

  std::vector<Bubble> red_bubbles;
  for (size_t i = 0; i < 5; ++i) {
    Bubble bubble("red", glm::vec2{0,0}, 10.0f,
                  bubblebounce::Bubble::SpecialBubble,
                  bubblebounce::Bubble::Medium);
    red_bubbles.emplace_back(bubble);
  }
  
  GameLevel level(1, 5, white_bubbles);
  
  SECTION("Get level white_bubbles") {
    std::vector<Bubble> level_bubbles = level.GetLevelBubbles();
    for (size_t i = 0; i < white_bubbles.size(); ++i) {
      REQUIRE(white_bubbles[i] == level_bubbles[i]);
    }
  }

  SECTION("Set level white_bubbles") {
    level.SetBubbles(red_bubbles);
    std::vector<Bubble> level_bubbles = level.GetLevelBubbles();
    for (size_t i = 0; i < red_bubbles.size(); ++i) {
      REQUIRE(red_bubbles[i] == level_bubbles[i]);
    }
  }
}