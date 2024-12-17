#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "room.h"
#include "creature.h"

// Oyun yapısını tanımlayan struct
typedef struct {
    Player player;
    Room *currentRoom;
} Game;

// Game işlev prototipleri
void initGame(Game *game);
void processCommand(Game *game, const char *command);
void gameLoop(Game *game);

#endif // GAME_H
