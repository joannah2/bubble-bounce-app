#include <core/paddle.h>

#include <catch2/catch.hpp>

using bubblebounce::Paddle;

/**
 * Testing Strategy for Paddle class
 * - invalid inputs
 * - setting/getting methods
 * - resetting new paddle attributes
 */

TEST_CASE("Test invalid Paddle corner coordinates") {
  SECTION("top_left_corner.x > bottom_right_corner.x") {
    REQUIRE_THROWS_AS(
      Paddle(glm::vec2{10, 0}, glm::vec2{5, 5}, "white"),
      std::invalid_argument);
  }
  
  SECTION("top_left_corner.x = bottom_right_corner.x") {
    REQUIRE_THROWS_AS(
      Paddle(glm::vec2{5, 0}, glm::vec2{5, 5}, "white"),
      std::invalid_argument);
  }
  
  SECTION("top_left_corner.y > bottom_right_corner.y") {
    REQUIRE_THROWS_AS(
      Paddle(glm::vec2{0, 10}, glm::vec2{5, 5}, "white"),
      std::invalid_argument);
  }
  
  SECTION("top_left_corner.y > bottom_right_corner.y") {
    REQUIRE_THROWS_AS(
      Paddle(glm::vec2{0, 5}, glm::vec2{5, 5}, "white"),
      std::invalid_argument);
  }
  
  SECTION("top_left_corner = bottom_right_corner") {
    REQUIRE_THROWS_AS(
      Paddle(glm::vec2{5, 5}, glm::vec2{5, 5}, "white"),
      std::invalid_argument);
  }

  SECTION("corner x value.x > corner x value.y") {
    Paddle paddle(glm::vec2{0, 0}, glm::vec2{5, 5},
                  "white");
    REQUIRE_THROWS_AS(paddle.SetCornerXCoordinates(glm::vec2{10, 0}),
      std::invalid_argument);
  }
  
  SECTION("corner x value.x = corner x value.y") {
    Paddle paddle(glm::vec2{0, 0}, glm::vec2{5, 5},
                  "white");
    REQUIRE_THROWS_AS(paddle.SetCornerXCoordinates(glm::vec2{10, 10}),
      std::invalid_argument);
  }
  
  SECTION("Invalid corner coordinates when resetting paddle attributes") {
    Paddle paddle(glm::vec2{0, 0}, glm::vec2{5, 5},
                  "white");
    REQUIRE_THROWS_AS(paddle.ResetAttributes(glm::vec2{10, 0},
                                             glm::vec2{5, 5}, "white"),
                      std::invalid_argument);
  }
}

TEST_CASE("Test Paddle getting/setting methods") {
  Paddle paddle(glm::vec2{0, 0}, glm::vec2{5, 5},
                "white");

  SECTION("Get top left") {
    REQUIRE(paddle.GetTopLeftPosition() == glm::vec2{0, 0});
  }

  SECTION("Get bottom right") {
    REQUIRE(paddle.GetBottomRightPosition() == glm::vec2{5, 5});
  }

  SECTION("Get length") {
    REQUIRE(paddle.GetLength() == 5);
  }

  SECTION("Get color") {
    REQUIRE(paddle.GetColor() == ci::Color("white"));
  }

  SECTION("Resetting paddle attributes to different values") {
    paddle.ResetAttributes(glm::vec2{0, 0},
                         glm::vec2{10, 10}, "white");
    REQUIRE(paddle.GetColor() == "white");
    REQUIRE(paddle.GetTopLeftPosition() == glm::vec2{0, 0});
    REQUIRE(paddle.GetBottomRightPosition() == glm::vec2{10, 10});
  }
}