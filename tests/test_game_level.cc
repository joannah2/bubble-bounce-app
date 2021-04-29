#include <core/game_level.h>

#include <catch2/catch.hpp>

using bubblebounce::GameLevel;
using bubblebounce::Bubble;

/**
 * Test Strategy for Game Level
 * - initializing attributes
 *  - getters/setters for bubbles vector
 *  - handling level winning/losing/resetting logic
 */
TEST_CASE("Test constructor and retrieving level attributes") {
  SECTION("Empty constructor proper initialization") {
    GameLevel level;
    REQUIRE(level.GetLevel() == 0);
    REQUIRE(level.GetPlayerLives() == 0);
    REQUIRE(level.GetPlayerScore() == 0);
    REQUIRE(level.GetLevelBubbles().empty());
  }

  SECTION("GameLevel proper initialization") {
    std::vector<Bubble> bubbles;
    GameLevel level(1, 5, bubbles);
    REQUIRE(level.GetLevel() == 1);
    REQUIRE(level.GetPlayerLives() == 5);
    REQUIRE(level.GetPlayerScore() == 0);
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

TEST_CASE("Test comparison operator for levels") {
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

  GameLevel white_level(1, 5, white_bubbles);
  GameLevel identical_white_level(1, 5, white_bubbles);
  GameLevel red_level(1, 5, red_bubbles);
  
  SECTION("Equal levels") {
    REQUIRE(white_level == identical_white_level);
  }

  SECTION("Unequal levels") {
    REQUIRE_FALSE(white_level == red_level);
  }
}

TEST_CASE("Test proper level logic") {
  std::vector<Bubble> white_bubbles;
  for (size_t i = 0; i < 5; ++i) {
    Bubble bubble("white", glm::vec2{0,0}, 5.0f,
                  bubblebounce::Bubble::NormalBubble,
                  bubblebounce::Bubble::Strong);
    white_bubbles.emplace_back(bubble);
  }

  GameLevel white_level(1, 5, white_bubbles);

  SECTION("Level won proper conditions") {
    std::vector<Bubble> empty_bubbles;
    GameLevel level(1, 5, empty_bubbles);
    REQUIRE(level.IsLevelWon());
  }

  SECTION("Level won is false with wrong conditions") {
    GameLevel level(1, 5, white_bubbles);
    REQUIRE_FALSE(level.IsLevelWon());
  }
  
  SECTION("Level lost with proper conditions") {
    GameLevel level(1, 0, white_bubbles);
    REQUIRE(level.IsLevelLost());
  }

  SECTION("Level lost is false with wrong condition") {
    GameLevel level(1, 5, white_bubbles);
    REQUIRE_FALSE(level.IsLevelLost());
  }
  
  SECTION("Level lost") {
    GameLevel level(1, 0, white_bubbles);
    REQUIRE(level.IsLevelLost());
  }

  SECTION("Resetting the level for the round") {
    white_level.ResetLevelForRound();
    REQUIRE(white_level.GetPlayerLives() == 4);
  }

  SECTION("Level over is true when the level lost or won") {
    GameLevel level(1, 0, white_bubbles);
    REQUIRE(level.IsLevelOver());
  }
  
  SECTION("Level over is false when level is not lost or won") {
    GameLevel level(1, 3, white_bubbles);
    REQUIRE_FALSE(level.IsLevelOver());
  }
}