README. TXT


0. Downloading the game:

Place the game folder into an easy to find directory.


1. Building the Game:

For running in Linux:

Libraries required: SFML

Instructions for installing SFML:

In terminal, input:

sudo apt -get install libsfml-dev

(If error occurs)

sudo apt -get update

If g++ is present on system, then run makefile. Otherwise, update g++.


2. Running the Game:

In terminal, get to the game directory, type ‘make’ to compile and build.
 
Type ‘./catAndMouse’ to run the game. 

At this point the terminal will pop up another screen, switching focus to this new screen. 

Return to the terminal again and enter the IP4 address (ex: 172.16.254.1). 

Then enter ‘m’ or ‘a’ for the appropriate characters: ‘m’ for Marine and ‘a’ for Alien. 
 
For testing proposes, we recommend running the game two consoles to represent two players. Also use the same IP address for both players.


3. Playing the Game:

Basic controls:

W = up
S = down
A = left
D = right
Mouse = 360 directional view
Left Mouse Button = shooting
Right Mouse Button = deploy item in inventory
E = Interact with objects in game.

Debug controls:
1 = Deploy explosive mine
2 = Deploy grav mine
Shift: toggle running - Note, may cause character to run through walls
O: teleport to Alien spawn position
P: teleport to Marine spawn position
H: gets HP of opposing player, time, player angle
J: distance of the interactable objects to the player

BUGS:
Bullets still pass through walls.
Hitbox is very small, must shoot the center of your opponent to damage them