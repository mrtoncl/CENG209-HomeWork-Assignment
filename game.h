#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "room.h"
#include "creature.h"

// Structure defining the game, which includes the player and the current room
typedef struct {
    Player player;          // The player in the game
    Room *currentRoom;      // The room where the player is currently located
} Game;

// Function prototypes for the game operations
void initGame(Game *game);          // Initializes the game and the starting room
void processCommand(Game *game, const char *command);  // Processes the user's command input
void gameLoop(Game *game);          // Main game loop, handles user commands in a continuous loop

#endif // GAME_H
