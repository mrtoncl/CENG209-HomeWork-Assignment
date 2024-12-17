#ifndef TRAP_H
#define TRAP_H

#include "player.h"  // Include the player header to interact with the player

// Trap structure definition
typedef struct {
    char name[50];  // Name of the trap
    int damage;     // Damage value the trap deals
} Trap;

// Function prototypes for trap operations
void describeTrap(const Trap *trap);          // Provides information about the trap
void activateTrap(Trap *trap, Player *player); // Activates the trap and deals damage to the player

#endif // TRAP_H
