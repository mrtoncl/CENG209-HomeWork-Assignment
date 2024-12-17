#ifndef ROOM_H
#define ROOM_H

#include "creature.h"
#include "item.h"  // Item'ı kullanabilmek için
#include "trap.h"

typedef struct Room {
    char description[256];
    struct Room *up;
    struct Room *down;
    struct Room *left;
    struct Room *right;
    Creature *creature;  // Odada yaratık
    Item *item;          // Odada eşya
    Trap *trap;
} Room;

void describeRoom(const Room *room);
void roomEntryMessage(const Room *room);

#endif // ROOM_H
