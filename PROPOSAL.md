# Final Project Proposal
## Game Selection
I would like to design and implement a video game based on the inspiration from the Brick Breaker game which  
first became available on BlackBerry platform in the early 2010.
My proposed Chestnut Cracker is a multi-level game. Player uses a nutcracker paddle to deflect a ball to break open
the chestnuts for a given level. There are 10 total levels.

Each level is associated with a given number of chestnuts, with higher levels featuring more chestnuts to break. The placements
of the chestnuts also present more challenges to complete the higher game levels.  
A player is initially given 10 chances (lives). Whenever the nut cracker paddle missed the nut ball the remaining chances is reduced by 1. Each time a level is completed, more lives will be added to the total remaining lives.

The number of additional lives is the game level number. A game ends either when a player completes all the  game levels or when the user has no chances (lives) left.

## Background
I took my first real programming class in my senior year. I learned how to do coding with Python using a very limited and
primitive user interface. I really wanted to be able to design and implement a graphic based video game that can
deflect objects and collect points similar to the one on Blackberry phones.
I really enjoy seeing the practical uses of math in problem-solving and like visuall seeing the affect proper mathematical implementations have.

I decided to design and implement **Chestnut Cracker** for my CS 126 Final Project. It allows me to put into practice the programming skills and the lessons I learned from class and past homework projects with regards to object-oriented design, debugging, and testing skills while working with an application such as Cinder. Through working on the weekly machine projects, specifically the  Ideal Gas simulation, inspired and challenged me to propose and the ChestNut Cracker. In the Ideal Gas homework, I gained a better understanding on the physics regarding how object collision is to handled and how to proper design the system as objects interact with each other based on external events (i.e. collisions) and internal object states (i.e. balls, paddle, and walls/panels). The graphic interface provided through Cinder motivated me to work on a graphic-based and user friendly video game.

## Timeline
### Week 1:
1)  Design and implement all the object classes required for the game. These include:
    - NutBall
    - Chestnuts
    - Nut Cracker Paddle
    - The GameEngine
2)  Design a strategy to manage various nutball-chestnut-panel collision scenarios:
    - when a ball hits the upper, left, and right panels
    - when a ball falls through the bottom floor
    - when a ball bounces off the nutcracker paddle
    - when a ball hits the chestnuts
3) Perform various test cases of the game:
    - ensure proper interactions among paddle, chestnuts, environment, and ball

### Week 2:
1) Design and implement the graphical User Interface for displaying:
    - class(es) to handle graphical UI
    - the Game Window
    - playing instructions
    - the associated Game Levels
    - User Lives Remaining count
2) Design and implement graphics for game components:
    - Game Winning Screen
    - Game Losing Screen
    - Ball, paddle, chestnuts, dashboard, backgrounds, etc
   
### Week 3:
1) Improve game design upon implementation
2) Perform additional test cases of the game:
    - Ensure all testable features function properly
    - Ensure proper physics and graphical user interface integrate well
    - Test various edge cases such as ball colliding with chestnuts and wall simultaneously
 
* Implement Extra Features:
    - Support for multiple balls or different types of objects
    - Paddle length adjustment for each new level
    - Adjust ball velocity for easier paddle deflection
