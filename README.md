# Instructions
## Game Set-Up
To set up Bubble Bounce, the following are required:
* CLion (or a C++ IDEA)
* Cinder (C++ visual application)
* Microsoft Visual Studio Code 2019 Build Tools

To play the game, run cinder_app_main.cc located inside the apps folder.

## How to Play
Bubble Bounce consists of following elements:
* Paddle - controlled by mouse movement
* Ball - bounces off paddle, bubbles, and top/side walls
* Bubbles - most of which can be popped

The game objective is to pop all the poppable bubbles for the level. By using the mouse, the paddle can be moved horizontally to deflect the ball.
The game begins when the mouse is clicked to launch the ball in the desired direction. The player must keep the ball alive by keeping it from fallling
through the bottom of the game windwow. If it falls through the bottom, the player loses a life. The game is over when the player runs out of lives.
To win, the player must pop all the possible bubbles while having more than 0 lives.

### Bubble Types
There are 3 types of bubbles:
* Unpoppable Bubble : cannot be popped
* Special Bubble : worth 3 points
* Normal Bubble : worth 1 point

Bubbles that can be popped go through 3 stages before popping:
* Strong : requires 3 hits before popping
* Medium : requires 2 hits before popping
* Weak : requires 1 hit before popping

## Score
The status panel tracks the remaining lives and score, as well as the player's high score. 
Each time a poppable bubble is hit, its state lowers by one stage.
Once a weak state bubble is hit, it pops and the player earns its corresponding point value.
