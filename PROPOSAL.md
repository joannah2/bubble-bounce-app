# Final Project Proposal
## Game Selection
I would like to design and implement a game based on a mix between Brick Breaker and Bubble Shooter. My proposed Bubble Bounce is a multi-level game where the player uses a paddle to deflect a ball to clear the bubbles for a given level. There will be various levels, with increasing difficulty as each level will have an associated given number of bubbles. The bubble placements can also increase the game difficulty. The player has an initial number of lives, which is reduced by 1 for every missed ball. The player can earn more lives by advancing to the next level. The game ends either when a player completes all the levels or has no live left.

## Background
I took my first real programming class in my senior year. I learned how to do coding with Python using a very limited and primitive user interface. I wanted to be able to design and implement a graphic based game that can deflect objects and collect points, similar to the few games I was familiar with when I was younger. I also really enjoy seeing the practical uses of math in problem-solving and liked visualy seeing the affect proper mathematical implementations have.

I decided to design and implement **Bubble Bounce** for my CS 126 Final Project. It allows me to put into practice the programming skills and the lessons I learned from class and past projects with regards to object-oriented design, debugging, and testing skills while working with an application such as Cinder. Through working on the weekly machine projects, specifically the  Ideal Gas simulation, inspired and challenged me to propose and the Bubble Bounce. In the Ideal Gas homework, I gained a better understanding on the physics regarding how object collision is to handled and how to proper design the system as objects interact with each other based on external events (i.e. collisions) and internal object states (i.e. balls, paddle, and walls/panels). The graphic interface provided through Cinder motivated me to work on a graphic-based and user friendly game.

## Timeline
### Week 1:
* Design and implement all the object classes required for the game. These include:
    - Ball
    - Bubbles
    - Paddle
    - The GameEngine
* Design a strategy to manage various ball-bubble-panel collision scenarios:
    - when a ball hits the upper, left, and right panels
    - when a ball falls through the bottom floor
    - when a ball bounces off the paddle
    - when a ball hits the bubbles
   
### Week 2:
* Design and implement the graphical User Interface for displaying:
    - class(es) to handle graphical UI
    - the Game Window
    - playing instructions
    - the associated Game Levels
    - User Lives Remaining count
   
### Week 3:
* Design and implement graphics for game components:
    - Game Winning Screen
    - Game Losing Screen
    - Ball, paddle, chestnuts, dashboard, backgrounds, etc
    - Integrate game UI with internal classes
 
* Throughout the weeks, there will also be various test cases to:
    - Ensure all testable features function properly
    - Ensure proper physics and graphical user interface integrate well
    - Check various edge cases (ie different scenarios of bubble-ball-wall interactions)

* Implement Extra Features:
    - Support for different objects or object behavior based on object type/color
    - Paddle length adjustment for each new level
    - Adjust ball velocity for easier paddle deflection
