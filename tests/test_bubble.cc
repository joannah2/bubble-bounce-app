#include <core/bubble.h>

#include <catch2/catch.hpp>

using bubblebounce::Bubble;

/**
 * Testing Strategy for Bubble class
 * - invalid inputs
 * - setting/getting methods and handling different colors
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

  SECTION("All bubble types have default color from initialization") {
    REQUIRE(bubble.GetColor() == "teal");
    REQUIRE(bubble.GetNormalMediumColor() == ci::Color("teal"));
    REQUIRE(bubble.GetNormalWeakColor() == ci::Color("teal"));
    REQUIRE(bubble.GetSpecialMediumColor() == ci::Color("teal"));
    REQUIRE(bubble.GetSpecialWeakColor() == ci::Color("teal"));
  }
  
  SECTION("Setting/getting the color for normal medium bubbles") {
    bubble.SetNormalMediumBubbleColor("white");
    REQUIRE(bubble.GetNormalMediumColor() == ci::Color("white"));
  }
  
  SECTION("Setting/getting the color for normal weak bubbles") {
    bubble.SetNormalWeakBubbleColor("blue");
    REQUIRE(bubble.GetNormalWeakColor() == ci::Color("blue"));
  }
  
  SECTION("Setting/getting the color for special medium bubbles") {
    bubble.SetSpecialMediumBubbleColor("green");
    REQUIRE(bubble.GetSpecialMediumColor() == ci::Color("green"));
  }
  
  SECTION("Setting/getting the color for special weak bubbles") {
    bubble.SetSpecialWeakBubbleColor("pink");
    REQUIRE(bubble.GetSpecialWeakColor() == ci::Color("pink"));
  }
}

TEST_CASE("Overloaded == operator for bubbles") {
  Bubble white_bubble("white", glm::vec2{0,0}, 5.0f,
                bubblebounce::Bubble::NormalBubble,
                bubblebounce::Bubble::Strong);
  Bubble identical_white_bubble("white", glm::vec2{0, 0}, 5.0f,
                                bubblebounce::Bubble::NormalBubble,
                                bubblebounce::Bubble::Strong);
  Bubble red_bubble("red", glm::vec2{10,10}, 15.0f,
                bubblebounce::Bubble::SpecialBubble,
                bubblebounce::Bubble::Medium);
  

  SECTION("Comparing equal balls") {
    REQUIRE(white_bubble == identical_white_bubble);
  }
  
  SECTION("Comparing unequal balls") {
    REQUIRE_FALSE(white_bubble == red_bubble);
  }
  
  SECTION("Change to bubble makes it unequal") {
    white_bubble.LowerBubbleState();
    REQUIRE_FALSE(white_bubble == identical_white_bubble);
  }
}