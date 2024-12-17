#include "player.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initializes the player with a given name and inventory capacity
void initPlayer(Player *player, const char *name, int inventoryCapacity) {
    // Set the player's name
    strncpy(player->name, name, sizeof(player->name) - 1);
    player->name[sizeof(player->name) - 1] = '\0';  // Null-terminate for safety
    
    // Initialize health and strength (optional)
    player->health = 500;
    player->strength = 30;

    player->inventoryCapacity = inventoryCapacity;  // Set inventory capacity
    player->inventory = malloc(inventoryCapacity * sizeof(Item*));  // Allocate memory for items
    for (int i = 0; i < inventoryCapacity; i++) {
        player->inventory[i] = NULL;  // Initialize inventory with empty slots
    }
}

// Adds an item to the player's inventory, adjusting health or strength if necessary
void addItemToInventory(Player *player, const Item *item) {
    for (int i = 0; i < player->inventoryCapacity; i++) {
        if (player->inventory[i] == NULL) {
            // Handle different types of items
            if (strcmp(item->name, "Dagger") == 0 || strcmp(item->name, "Rusty Sword") == 0) {
                player->inventory[i] = (Item*)item;  // Add item to inventory
                printf("Added %s to inventory.\n", item->name);
                player->strength += item->value;  // Increase strength
                return;
            }
            if (strcmp(item->name, "Golden Talisman") == 0) {
                player->inventory[i] = (Item*)item;  // Add item to inventory
                printf("Added %s to inventory.\n", item->name);
                player->health += item->value;  // Increase health
                player->strength += item->value;  // Increase strength
                return;
            }
            if (strcmp(item->name, "Health Potion") == 0 || strcmp(item->name, "Shield") == 0) {
                printf("%s used!\n", item->name);
                player->health += item->value;  // Increase health
                return;
            }
            if (strcmp(item->name, "Door Key") == 0) {
                player->inventory[i] = (Item*)item;  // Add item to inventory
                printf("Added %s to inventory.\n", item->name);
                return;
            }
            if (strcmp(item->name, "Treasure Chest") == 0) {
                printf("You win the game!\n");
                printf("GAME OVER!");
                exit(0);  // Exit the game if treasure chest is picked
            }
        }
    }
    printf("Inventory is full!\n");  // If no space is available in the inventory
}

// Prints the player's inventory
void printInventory(const Player *player) {
    if (player->inventory[0] == NULL) {
        printf("Inventory is empty!\n");
    } else {
        printf("Inventory:\n");
        for (int i = 0; i < player->inventoryCapacity; i++) {
            if (player->inventory[i] != NULL) {
                printf(" - %s\n", player->inventory[i]->name);  // Print item names
            }
        }
    }
}

// Describes the player's current status
void describePlayer(Player *player) {
    printf("\nName: %s\n", player->name);
    printf("Health: %d\n", player->health);
    printf("Strength: %d\n", player->strength);
}
