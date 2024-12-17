#include "trap.h"
#include <stdio.h>
#include <stdlib.h>

// Function to describe a trap
void describeTrap(const Trap *trap) {
    if (trap != NULL) {  // Check if the trap exists
        printf("Trap name: %s\n", trap->name);  // Print the trap's name
        printf("It can deal %d damage!\n", trap->damage);  // Print the damage the trap can deal
    }
}

// Function to activate a trap and deal damage to the player
void activateTrap(Trap *trap, Player *player) {
    if (trap != NULL && player != NULL) {  // Check if both trap and player are valid
        printf("You triggered %s! It dealt %d damage!\n", trap->name, trap->damage);  // Inform the player of the trap activation
        player->health -= trap->damage;  // Reduce the player's health by the trap's damage

        // Check if the player's health reaches zero or below
        if (player->health <= 0) {
            printf("You died from the trap...\n");  // If the player dies, print a death message
            exit(0);  // Exit the game
        }
    }
}
