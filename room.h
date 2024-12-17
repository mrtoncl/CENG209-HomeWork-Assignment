#ifndef ROOM_H
#define ROOM_H

#include "creature.h"
#include "item.h"  // Include the Item header to use the Item structure
#include "trap.h"

// Room structure
typedef struct Room {
    char description[256];  // Description of the room
    struct Room *up;        // Pointer to the room above (north)
    struct Room *down;      // Pointer to the room below (south)
    struct Room *left;      // Pointer to the room on the left (west)
    struct Room *right;     // Pointer to the room on the right (east)
    Creature *creature;     // Pointer to the creature in the room (if any)
    Item *item;             // Pointer to the item in the room (if any)
    Trap *trap;             // Pointer to the trap in the room (if any)
} Room;

// Function to describe a room, including the creature and item (if present)
void describeRoom(const Room *room);

// Function to print the entry message when a player enters a room
void roomEntryMessage(const Room *room);

#endif // ROOM_H
