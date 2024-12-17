# CENG209 Homework Assignment
 
Text-Based Dungeon Adventure Game

1. Overview

	This project is a text-based adventure game written in the C programming language. The game challenges the player to navigate through a 3x3 dungeon map, battle dangerous creatures, avoid traps, collect items, and ultimately 	find the treasure hidden in the last room (Room 9).

	The game implements a modular structure using separate files for managing different components, such as the player, rooms, creatures, items, traps, and game logic.

-------------------------------------------------------------------------------------------------------------------

2. Gameplay

Objective

	Explore the dungeon and find the Treasure Chest located in Room 9.

	Defeat creatures, survive traps, and collect the Door Key to unlock Room 9.


     Starting the Game


When the game starts:

	1. The dungeon map is initialized with creatures, items, and traps placed in specific rooms.

	2. The player, represented as the "Hero", starts in a random room with:

		100 HP (Health Points)

		10 Strength (Attack Power)


				Commands


The player interacts with the game by entering simple text commands:


Command                      	Description


look 				Describes the current room and its contents.

stats				Displays the player's health and strength.

inventory			Shows the player's current inventory.

move <direction> 		Moves the player in the specified direction (up, down, left, or right).

pickup 				Picks up items in the room (if available).
	
attack 				Fights the creature in the room.

map 				Displays the dungeon map layout.

exit				Exits the game.


Game Progression

	Items: Items like Health Potion, Shield, and Weapons help the player recover health or increase attack 	power.

	Traps: Traps deal damage to the player when entering certain rooms.

	Creatures: Defeat creatures blocking the path to progress further.

	Locked Rooms: Room 9 (Treasure Room) requires the Door Key to enter.


				Winning the Game

To win:

	1. Collect the Door Key from Room 7.

	2. Defeat the Dragon in Room 9.

	3. Pick up the Treasure Chest.

	4. Celebrate your victory with the game-ending message!

-------------------------------------------------------------------------------------------------------------------

3. Code Structure

The project is organized into modular files for better readability and maintainability.

				Main Files


File				Description

main.c				Entry point of the game. Initializes the game and starts the main game loop.

game.c/game.h			Handles the core game logic, processes commands, and manages the game loop.

map.c/map.h			Sets up the dungeon map, room connections, and initial placement of entities.

room.c/room.h			Manages room descriptions, traps, creatures, and items within rooms.

player.c/player.h		Manages the player, including health, strength, inventory, and stats.

creature.c/creature.h		Manages creature behaviors and battle mechanics.

item.c/item.h			Handles items and their effects on the player.

trap.c/trap.h			Manages traps and their effects when activated.


Core Functions

1. Game Initialization

	initGame: Sets up the player and the map.

	initMap: Creates the dungeon layout and populates rooms with creatures, traps, and items.

2. Player Actions

	processCommand: Processes user input (e.g., movement, combat, inventory).

	addItemToInventory: Adds items to the player's inventory and applies their effects.

	startBattle: Initiates combat with creatures.

3. Room and Map Management

	describeRoom: Displays the room's description and its contents.

	roomEntryMessage: Provides special messages for specific rooms.

	activateTrap: Activates traps when a player enters a room.

4. Game Loop

	gameLoop: Runs the game continuously until the player exits or wins.

-------------------------------------------------------------------------------------------------------------------

4. Game Mechanics

				Map Layout

The dungeon consists of a 3x3 grid of rooms:

Room1 --- Room2 --- Room3
  |        |         |
Room4 --- Room5 --- Room6
  |        |         |
Room7 --- Room8 --- Room9

Each room may contain:

	Creatures: Enemies like Goblins, Orcs, and Dragons.

	Items: Useful objects like Health Potions, Shields, and the Door Key.

	Traps: Hazards that deal damage to the player.


				Combat System


When the player encounters a creature:

	1. The player attacks first, reducing the creature's health based on their strength.

	2. The creature counterattacks, reducing the player's health based on its attack power.

	3. Combat continues until either the creature or the player is defeated.

	4. If the player's health reaches 0, the game ends.

Traps

	Traps deal instant damage when triggered.

	If the player's health drops to 0 due to a trap, the game ends immediately.

Inventory System

	The player can carry items like weapons, potions, and keys.

	Items can:

		Restore health (e.g., Health Potion).

		Increase attack power (e.g., Dagger).

		Unlock rooms (e.g., Door Key).

-------------------------------------------------------------------------------------------------------------------

5. How to Run the Game

				Compilation

To compile the game, use the following command:

	gcc -o dungeon main.c game.c map.c room.c player.c creature.c item.c trap.c


				Running the Game

Run the compiled executable:

	./dungeon

Playing the Game

Follow the on-screen instructions and enter commands to explore the dungeon, defeat enemies, and win the game.

-------------------------------------------------------------------------------------------------------------------

6. Example Gameplay

Welcome to the Dungeon Adventure Game!

Map:
Room1 --- Room2 --- Room3
  |        |         |
Room4 --- Room5 --- Room6
  |        |         |
Room7 --- Room8 --- Room9

Objective: Find the treasure chest to win the game!

Enter command: look
You're in: Room 1 - A quiet chamber.
There is a creature in this room!
Creature: Goblin
Health: 20
Attack Power: 5

Enter command: attack
You attack the Goblin!
The Goblin attacks you!
Your Health: 95 | Goblin Health: 10

Enter command: pickup
There is nothing to pick up here.

Enter command: move right
You're in: Room 2 - A dimly lit hallway.
Growling sounds are heard!?

-------------------------------------------------------------------------------------------------------------------

7. Conclusion

This project demonstrates:

Modular programming and structure in C.

Use of pointers, dynamic memory allocation, and structures.

Text-based game development with user commands and real-time feedback.

Enjoy playing the game and exploring the dungeon!
