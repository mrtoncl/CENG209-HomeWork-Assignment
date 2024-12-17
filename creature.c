#include "creature.h"
#include <stdio.h>
#include <stdlib.h>

// Function to start a battle between the player and the creature
void startBattle(Player *player, Creature *creature) {
    printf("Battle started with %s!\n", creature->name);

    // Loop until either the player or the creature is defeated
    while (player->health > 0 && creature->health > 0) {
        // Player attacks the creature
        printf("You attack the %s!\n", creature->name);
        creature->health -= player->strength;  // Decrease creature's health by player's strength

        // Check if the creature is defeated
        if (creature->health <= 0) {
            printf("You defeated the %s!\n", creature->name);
            return;  // End the battle if the creature is defeated
        }

        // Creature attacks the player
        printf("The %s attacks you!\n", creature->name);
        player->health -= creature->attackPower;  // Decrease player's health by creature's attack power

        // Check if the player is defeated
        if (player->health <= 0) {
            printf("You were defeated by the %s...\n", creature->name);
            exit(0);  // Exit the game if the player is defeated
        }

        // Display current health status of the player and the creature
        printf("Your Health: %d | %s Health: %d\n", player->health, creature->name, creature->health);
    }
}

// Function to display the creature's description
void creatureDescription(const Creature *creature) {
    if (creature != NULL) {
        // Print the details of the creature
        printf("Creature: %s\n", creature->name);
        printf("Health: %d\n", creature->health);
        printf("Attack Power: %d\n", creature->attackPower);
    }
}
