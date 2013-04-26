# Game - Programming Assignments Private Repository
### Student Information
  + Name: Joseph Boman
  + USC Email: jboman@usc.edu
  + USC ID: 4267029406

### Game Information
  + Game Name: Uncharted Territory
  + Game Description: A shooter game, where the player attempts to dodge or destroy asteroids and alien spacecraft to find and destroy the enemy mothership.
  + [Game Design Doc](GameDesignDoc.md)


#NOTE TO THE GRADER
My game's speed-up comes in the form of the boss battle, which takes about 30 seconds of play to reach.
The game drastically speeds up upon his arrival, and the more damage he takes, the faster the game goes.

### Compile & Run Instructions
The grader should use the following procedure to compile and run the code:
```shell
#Compile Instructions
qmake
make
#Doxygen Instructions
doxygen -g config.txt
doxygen config.txt
Then open index.html in the html directory
#Command to run
./game_jboman
```
