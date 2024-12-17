#ifndef CREATURE_H
#define CREATURE_H

#include "player.h"

// Creature structure that represents an enemy or creature in the game
typedef struct {
    char name[50];        // Name of the creature
    int health;           // Health points of the creature
    int attackPower;      // Attack power of the creature
} Creature;

// Function to start a battle between the player and the creature
void startBattle(Player *player, Creature *creature);

// Function to display the creature's description (name, health, attack power)
void creatureDescription(const Creature *creature);

#endif // CREATURE_H
