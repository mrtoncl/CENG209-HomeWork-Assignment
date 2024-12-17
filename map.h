#ifndef MAP_H
#define MAP_H

#include "room.h"

// Defines the Map structure, which contains a 3x3 grid of rooms
typedef struct {
    Room *rooms[3][3];  // 3x3 room matrix
} Map;

// Initializes the map and creates rooms
void initMap(Map *map);

// Returns a room at the specified coordinates
Room* getRoom(Map *map, int x, int y);

#endif
