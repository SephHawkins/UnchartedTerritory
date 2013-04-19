# Game Design Document
----
#Overall Gameplay
The player will start at the bottom of the screen when the game begins. Asteroids will fall from the top of the screen towards the
player. The player must dodge or shoot the asteroids. Alien spaceships will move onto the screen and attack the player in 
different ways. The player must dodge the attacks and can shoot the aliens.

After a certain amount of time, the asteroids and aliens will leave, and there will be a boss fight. The boss will be stationary 
at the top of the screen, and will fire a variety of attacks at the player. If the player defeats the boss, the game will begin at 
the beginning, with the player retaining their lives and score, but with everything faster.

##Things in the Game
1. The player
	* The player will control a spaceship at the bottom of the screen, which will be represented by a spaceship image
2. Alien Spaceships
	*There will be two different kinds of alien spaceships, represented by different UFO type images
	*The first type will fly straight across the screen, firing basic projectiles at the player
	*The second type will dive down from the top, firing missiles before shooting off in a random direction
3. Weaponry
	*There will be two different kinds of weapons in the game
	*The first is a basic bullet, which travels in a straight line and damages its target on impact
	*The second is a missile, which flys in a straight line but explodes, doing extra damage if it hits anything or when it
	 reaches the bottom of the screen
4. Asteroids
	*Asteroids will fall from the top of the screen straight down
	*Some asteroids will be larger, and break into smaller ones when they are damaged
5. Boss Alien Ship
	*There will be one boss in the game
	*The boss will have both normal kinds of weapons, and a unique beam weapon of its own
	*The beam weapon creates a line that will destroy anything in it until it fades

##Control Scheme
1. The left and right arrowkeys or A and D will be used to move the player's ship to the left and right, respectively
2. The Ctrl key will be used to fire bullets at the enemies
3. The Shift key will be used to fire missiles at the enemies
4. The P key will be used to pause the game

##Score
The score can change in the following ways:
1. Shooting an asteroid +1 point
2. Shooting a large asteroid +3 points
3. Shooting a basic alien ship +5 points
4. Shooting a divebombing alien ship +5 point
5. Destroying a divebombing alien ship +10 points
5. Shooting a falling missile +1 point
6. Shooting the boss alien ship +5 points
7. Destroying the boss ship +50 points
8. Losing a life -10 points

##Lives
The player will contain an int that will measure the number of lives that they have left
Their lives go down on:
1. Collision with an asteroid
2. Collision with an alien ship
3. Collision with a bullet
4. Collision with a missile
5. Collision with a beam
The game will be over once the player has lost all of their lives.
When they lose a life, the game will pause for a few seconds, clear the screen of weapons, and the player can continue

##Interface
The basic interface will consist of one view
The view will contain:
* A name field
* A start button that only works once the name field has been filled
* A quit button that exits the game
* A pause button that pauses the game
* A box containing the top scores for the game
![The Board Setup](https://sphotos-a.xx.fbcdn.net/hphotos-prn1/64461_10200105554173863_739153238_n.jpg "The Board Setup")

###Classes
* A MainWindow class
* A generic object class for all game objects
* A player object class
* A dive-bombing alien object class
* A basic alien spaceship object class
* A basic bullet object class
* A missile object class
* A boss ship object class
* An asteroid object class
