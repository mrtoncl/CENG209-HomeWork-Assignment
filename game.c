// Game initialization function
#include "game.h"
#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Initializes the game, including the map and the player
void initGame(Game *game) {

    // Initialize the map
    Map map;
    initMap(&map);

    // Select the starting room
    int startX = 0;
    int startY = 0;

    // Initialize the player and set the starting room
    initPlayer(&game->player, "Hero", 10);
    game->currentRoom = getRoom(&map, startX, startY);

    // Display the map and objective
    printf("Map: \n");
    printf("Room1 --- Room2 --- Room3\n");
    printf("  |        |         |\n");
    printf("Room4 --- Room5 --- Room6\n");
    printf("  |        |         |\n");
    printf("Room7 --- Room8 --- Room9\n");
    printf("Objective: Find the treasure chest to win the game!\n\n");
    roomEntryMessage(game->currentRoom);
}

// Function to process user commands
void processCommand(Game *game, const char *command) {
    if (strcmp(command, "look") == 0) {
        describeRoom(game->currentRoom);  // Describe the current room
    }
    else if(strcmp(command, "stats") == 0){
        describePlayer(&game->player);  // Display player stats
    }
    else if (strcmp(command, "inventory") == 0) {
        printInventory(&game->player);  // Display player's inventory
    } else if (strncmp(command, "move", 4) == 0) {
        char direction[10];
        sscanf(command, "move %s", direction);

        // Check if the player needs to defeat an enemy before moving
        if(game->currentRoom->creature != NULL){
            printf("You have to defeat the enemy before you leave the room!");
        }
        else{
            Room *nextRoom = NULL;

            // Determine the direction and next room
            if (strcmp(direction, "up") == 0) nextRoom = game->currentRoom->up;
            else if (strcmp(direction, "down") == 0) nextRoom = game->currentRoom->down;
            else if (strcmp(direction, "left") == 0) nextRoom = game->currentRoom->left;
            else if (strcmp(direction, "right") == 0) nextRoom = game->currentRoom->right;

            // Check if the player has the key to enter the treasure room (Room 9)
            if (nextRoom != NULL && strcmp(nextRoom->description, "Room 9 - A treasure room!") == 0) {
                int isKeyPresent = 0;
                for (int i = 0; i < game->player.inventoryCapacity; i++) {
                    if (game->player.inventory[i] != NULL && strcmp(game->player.inventory[i]->name, "Door Key") == 0) {
                        isKeyPresent = 1;  // Key found
                    }
                }
                if (isKeyPresent != 1) {
                    printf("You need the 'key' to enter this room!\n");
                    return;  // Prevent entry to the room without the key
                }
            }

            // If a valid room is found, move the player there and handle any traps
            if (nextRoom) {
                game->currentRoom = nextRoom;
                roomEntryMessage(game->currentRoom);
                if (game->currentRoom->trap != NULL){
                     activateTrap(game->currentRoom->trap, &game->player);  // Trigger the trap if present
                }
            }    
            else {
                printf("You can't move in that direction!\n");
            }
        }
    } else if (strncmp(command, "pickup", 6) == 0) {
        // Ensure the player defeats the enemy before picking up items
        if(game->currentRoom->creature != NULL){
            printf("You have to defeat the enemy first!\n");
        }
        else{
            // Add item to player's inventory if available
            if (game->currentRoom->item) {
                addItemToInventory(&game->player, game->currentRoom->item);
                game->currentRoom->item = NULL;
            } else {
                printf("There is nothing to pick up here.\n");
            }
        }
    } else if (strncmp(command, "attack", 6) == 0) {
        // Start a battle with the creature in the room
        startBattle(&game->player, game->currentRoom->creature);
        if(game->player.health != 0){
            game->currentRoom->creature = NULL;  // Remove the creature after battle
        }
    }else if(strcmp(command, "map") == 0){
        // Display the map again
        printf("Map: \n");
        printf("Room1 --- Room2 --- Room3\n");
        printf("  |        |         |\n");
        printf("Room4 --- Room5 --- Room6\n");
        printf("  |        |         |\n");
        printf("Room7 --- Room8 --- Room9\n");
        printf("Objective: Find the treasure chest to win the game!\n\n");
    } else if (strcmp(command, "exit") == 0) {
        // Exit the game
        printf("Exiting game. Goodbye!\n");
        exit(0);
    } else {
        // Invalid command
        printf("Invalid command!\n");
    }
}

// Main game loop that waits for and processes player commands
void gameLoop(Game *game) {
    char command[50];

    // Continuous loop for processing commands until exit
    while (1) {
        printf("\nEnter command: ");
        fgets(command, 50, stdin);
        command[strcspn(command, "\n")] = '\0'; // Remove the newline character
        processCommand(game, command);  // Process the entered command
    }
}
