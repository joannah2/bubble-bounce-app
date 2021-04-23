#include <core/ball.h>

#include <catch2/catch.hpp>

using bubblebounce::Ball;

/**
 * Testing Strategy for Ball class
 * - invalid inputs
 * - setting/getting methods
 * - updating ball velocities
 */

TEST_CASE("Test invalid ball inputs") {
  Ball ball("teal", glm::vec2{0,0}, glm::vec2{1,1},
            10.0f);
  
  SECTION("Negative radius ball") {
    REQUIRE_THROWS_AS(Ball("purple", glm::vec2{0, 0}, glm::vec2{1, 1},
                           -10.0f), std::invalid_argument);
  }

  SECTION("0 radius ball") {
    REQUIRE_THROWS_AS(Ball("purple", glm::vec2{0, 0}, glm::vec2{1, 1},
                           0.0f), std::invalid_argument);
  }
  
  SECTION("Negative radius when resetting attributes") {
    REQUIRE_THROWS_AS(ball.ResetAttributes("white", glm::vec2{0, 0}, glm::vec2{1, 1},
                                            -10.0f), std::invalid_argument);
  }

  SECTION("0 radius when resetting attributes") {
    REQUIRE_THROWS_AS(ball.ResetAttributes("white", glm::vec2{0, 0}, glm::vec2{1, 1},
                                           0.0f), std::invalid_argument);
  }
}
  TEST_CASE("Test Ball getting/setting methods") {
  Ball ball("teal", glm::vec2{0,0}, glm::vec2{1,1},
       10.0f);

  SECTION("Get color") {
    REQUIRE(ball.GetColor() == ci::Color("teal"));
  }

  SECTION("Get radius") {
    REQUIRE(ball.GetRadius() == 10.0f);
  }

  SECTION("Get position") {
    REQUIRE(ball.GetPosition() == glm::vec2{0, 0});
  }

  SECTION("Get velocity") {
    REQUIRE(ball.GetVelocity() == glm::vec2{1, 1});
  }

  SECTION("Resetting ball attributes to different values") {
    ball.ResetAttributes("white", glm::vec2{10, 10}, 
                         glm::vec2{1, 1}, 5.0f);
    REQUIRE(ball.GetColor() == "white");
    REQUIRE(ball.GetPosition() == glm::vec2{10, 10});
    REQUIRE(ball.GetVelocity() == glm::vec2{1, 1});
    REQUIRE(ball.GetRadius() == 5.0f);
  }
}

TEST_CASE("Test Ball updating velocities") {
  Ball positive_velocity_ball("teal", glm::vec2{0,0},
                              glm::vec2{1,1},10.0f);
  Ball negative_velocity_ball("teal", glm::vec2{0,0},
                              glm::vec2{-1,-1},10.0f);
  
  SECTION("Increase position by velocity") {
    positive_velocity_ball.IncreasePositionByVelocity();
    REQUIRE(positive_velocity_ball.GetPosition() == glm::vec2{1, 1});
  }
  
  SECTION("Increase position by velocity") {
    negative_velocity_ball.IncreasePositionByVelocity();
    REQUIRE(negative_velocity_ball.GetPosition() == glm::vec2{-1, -1});
  }

  SECTION("Reverse x velocity") {
    positive_velocity_ball.ReverseXVelocity();
    REQUIRE(positive_velocity_ball.GetVelocity() == glm::vec2{-1, 1});
  }

  SECTION("Reverse y velocity") {
    negative_velocity_ball.ReverseYVelocity();
    REQUIRE(negative_velocity_ball.GetVelocity() == glm::vec2{-1, 1});
  }
}