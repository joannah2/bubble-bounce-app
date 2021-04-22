# Final Project Proposal
## Game Selection
I would like to design and implement a game based on a mix between Brick Breaker
and Bubble Shooter. My proposed Bubble Bounce allows the player to control a 
paddle with their mouse to deflect a ball, the goal being to clear all possible 
bubbles. The game is over if the ball falls through the bottom of the window. 
Various factors are implemented to increase difficulty, including unpoppable 
bubbles and a progression from strong, medium, to weak bubble states before a 
bubble can pop. Popping a bubble will change the color of the ball.

## Background
I took my first real programming class in my senior year. I learned how to do 
coding with Python using a very limited and primitive user interface. I wanted 
to be able to design and implement a graphic based game that can deflect objects
and collect points, similar to the few games I was familiar with when I was 
younger.

I decided to design and implement **Bubble Bounce** for my CS 126 Final Project.
It allows me to put into practice the programming skills and the lessons I 
learned from class and past projects with regards to object-oriented design,
debugging, and testing skills while working with an application such as Cinder.
Through working on the weekly machine projects, specifically the  Ideal Gas 
simulation, inspired and challenged me to propose and the Bubble Bounce. In the
Ideal Gas homework, I gained a better understanding on the physics regarding 
how object collision is to handled and how to proper design the system as 
objects interact with each other based on external events (i.e. collisions) 
and internal object states (i.e. balls, paddle, and walls/panels). The graphic
interface provided through Cinder motivated me to work on a graphic-based and 
user friendly game.

## Timeline
### Week 1:
* Design and implement all the object classes required for the game:
    - Ball
    - Bubbles
    - Paddle
    - GameEngine
* Design a strategy to manage various ball-bubble-panel collision scenarios:
    - when a ball hits the upper, left, and right panels
    - when a ball falls through the bottom floor
    - when a ball bounces off the paddle
    - when a ball hits the bubbles

### Week 2:
* Design and implement internal game design:
  - different bubble types and bubble states
  - points system
  - differentiate bubble colors
* Test game strategy implementations
   
### Week 3:
* Design and implement visual for game components:
  - Game Winning Screen
  - Game Losing Screen
  - playing instructions
  - Ball, paddle, bubbles, dashboard, backgrounds, etc
  - Integrate game UI with internal classes

### Extra Feature Ideas:
* Support for different objects or object behavior based on object type/color
* Different levels 
* Adjust ball velocity for easier paddle deflection
