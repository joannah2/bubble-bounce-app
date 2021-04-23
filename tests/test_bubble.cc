#include <core/bubble.h>

#include <catch2/catch.hpp>

using bubblebounce::Bubble;

/**
 * Testing Strategy for Bubble class
 * - invalid inputs
 * - setting/getting methods
 */

TEST_CASE("Test invalid bubble inputs") {
  SECTION("Negative radius bubble") {
    REQUIRE_THROWS_AS(Bubble("teal", glm::vec2{0,0}, -10.0f,
                                    bubblebounce::Bubble::Unpoppable,
                        bubblebounce::Bubble::Strong), std::invalid_argument);
  }

  SECTION("0 radius bubble") {
    REQUIRE_THROWS_AS(Bubble("teal", glm::vec2{0,0}, 0.0f,
                             bubblebounce::Bubble::Unpoppable,
                             bubblebounce::Bubble::Strong), std::invalid_argument);
  }

  SECTION("Unpoppable bubble has state popped") {
    REQUIRE_THROWS_AS(Bubble("teal", glm::vec2{0,0}, -10.0f,
                             bubblebounce::Bubble::Unpoppable,
                             bubblebounce::Bubble::Popped), std::invalid_argument);
  }

  SECTION("Setting unpoppable bubble to popped state") {
    Bubble bubble("teal", glm::vec2{0,0}, 10.0f,
                  bubblebounce::Bubble::Unpoppable,
                  bubblebounce::Bubble::Strong);
    REQUIRE_THROWS_AS(bubble.SetBubbleState(bubblebounce::Bubble::Popped),
                      std::invalid_argument);
  }
}

TEST_CASE("Test Bubble getting/setting methods") {
  Bubble bubble("teal", glm::vec2{0,0}, 10.0f,
                bubblebounce::Bubble::NormalBubble,
                bubblebounce::Bubble::Strong);
  
  SECTION("Get color") {
    REQUIRE(bubble.GetColor() == ci::Color("teal"));
  }

  SECTION("Get radius") {
    REQUIRE(bubble.GetRadius() == 10.0f);
  }
  
  SECTION("Get position") {
    REQUIRE(bubble.GetPosition() == glm::vec2{0, 0});
  }

  SECTION("Get type") {
    REQUIRE(bubble.GetBubbleType() == bubblebounce::Bubble::NormalBubble);
  }

  SECTION("Get state") {
    REQUIRE(bubble.GetBubbleState() == bubblebounce::Bubble::Strong);
  }

  SECTION("Lower the bubble state from strong to medium") {
    bubble.LowerBubbleState();
    REQUIRE(bubble.GetBubbleState() == bubblebounce::Bubble::Medium);
  }
  
  SECTION("Lower the bubble state from medium to weak") {
    bubble.SetBubbleState(bubblebounce::Bubble::Medium);
    bubble.LowerBubbleState();
    REQUIRE(bubble.GetBubbleState() == bubblebounce::Bubble::Weak);
  }
  
  SECTION("Lower the bubble state from weak to popped") {
    bubble.SetBubbleState(bubblebounce::Bubble::Weak);
    bubble.LowerBubbleState();
    REQUIRE(bubble.GetBubbleState() == bubblebounce::Bubble::Popped);
  }
  
  SECTION("Lowering popped bubble state remains same") {
    bubble.SetBubbleState(bubblebounce::Bubble::Popped);
    bubble.LowerBubbleState();
    REQUIRE(bubble.GetBubbleState() == bubblebounce::Bubble::Popped);
  }
}