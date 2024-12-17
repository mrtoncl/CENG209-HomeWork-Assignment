#ifndef PLAYER_H
#define PLAYER_H

#include "item.h"  // Include Item header for item definitions

// Player structure definition
typedef struct Player {
    char name[50];  // Player's name
    int health;     // Player's health points
    int strength;   // Player's strength points
    int inventoryCapacity;  // Inventory capacity (maximum number of items)
    Item **inventory;       // Array of pointers to items in the player's inventory
} Player;

// Function prototypes

// Initializes a player with the given name and inventory capacity
void initPlayer(Player *player, const char *name, int inventoryCapacity);

// Prints the player's inventory
void printInventory(const Player *player);

// Adds an item to the player's inventory, adjusting health or strength if necessary
void addItemToInventory(Player *player, const Item *item);

// Displays the player's current status (name, health, and strength)
void describePlayer(Player *player);

#endif // PLAYER_H
