// Oyunu başlatan fonksiyon
#include "game.h"
#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Oyunu başlatan fonksiyon
void initGame(Game *game) {

    // Haritayı başlat
    Map map;
    initMap(&map);

    // Rastgele başlangıç odası seç
    srand(time(NULL));
    int startX = 0;
    int startY = 0;

    // Oyuncuyu başlat ve başlangıç odasını ayarla
    initPlayer(&game->player, "Hero",10);
    game->currentRoom = getRoom(&map, startX, startY);

    // Başlangıç odasını tanımla
    printf("Map: \n");
    printf("Room1 --- Room2 --- Room3\n");
    printf("  |        |         |\n");
    printf("Room4 --- Room5 --- Room6\n");
    printf("  |        |         |\n");
    printf("Room7 --- Room8 --- Room9\n");
    printf("Objective: Find the treasure chest to win the game!\n\n");
    roomEntryMessage(game->currentRoom);
}


// Kullanıcı komutlarını işleyen fonksiyon
void processCommand(Game *game, const char *command) {
    if (strcmp(command, "look") == 0) {
        describeRoom(game->currentRoom);
    }
    else if(strcmp(command, "stats") == 0){
        describePlayer(&game->player);
    }
    else if (strcmp(command, "inventory") == 0) {
        printInventory(&game->player);
    } else if (strncmp(command, "move", 4) == 0) {
        char direction[10];
        sscanf(command, "move %s", direction);

        if(game->currentRoom->creature != NULL){
            printf("You have to defeat the enemy before you leave the room!");
        }
        else{
            Room *nextRoom = NULL;
            if (strcmp(direction, "up") == 0) nextRoom = game->currentRoom->up;
            else if (strcmp(direction, "down") == 0) nextRoom = game->currentRoom->down;
            else if (strcmp(direction, "left") == 0) nextRoom = game->currentRoom->left;
            else if (strcmp(direction, "right") == 0) nextRoom = game->currentRoom->right;

            // Eğer 9. odaya geçiş yapılmaya çalışılıyorsa kontrol et
            if (nextRoom != NULL && strcmp(nextRoom->description, "Room 9 - A treasure room!") == 0) {
                int isKeyPresent = 0;
                for (int i = 0; i < game->player.inventoryCapacity; i++) {
                    if (game->player.inventory[i] != NULL && strcmp(game->player.inventory[i]->name, "Door Key") == 0) {
                        isKeyPresent = 1;  // Eşya bulundu
                    }
                }
                if (isKeyPresent != 1) {
                    printf("You need the 'key' to enter this room!\n");
                    return;  // Odaya girişe izin verilmez
                }
            }

            if (nextRoom) {
                game->currentRoom = nextRoom;
                roomEntryMessage(game->currentRoom);
                if (game->currentRoom->trap != NULL){
                     activateTrap(game->currentRoom->trap, &game->player);  // Tuzak devreye girer
                }
            }    
            else {
                printf("You can't move in that direction!\n");
            }
        }
    } else if (strncmp(command, "pickup", 6) == 0) {
        if(game->currentRoom->creature != NULL){
            printf("You have to defeat the enemy first!\n");
        }
        else{
            if (game->currentRoom->item) {

                addItemToInventory(&game->player, game->currentRoom->item);
                game->currentRoom->item = NULL;
            } else {
                printf("There is nothing to pick up here.\n");
        }
        }
    } else if (strncmp(command, "attack", 6) == 0) {
        startBattle(&game->player, game->currentRoom->creature);
        if(game->player.health != 0){
            game->currentRoom->creature = NULL;
        }
    }else if(strcmp(command, "map") == 0){
        printf("Map: \n");
        printf("Room1 --- Room2 --- Room3\n");
        printf("  |        |         |\n");
        printf("Room4 --- Room5 --- Room6\n");
        printf("  |        |         |\n");
        printf("Room7 --- Room8 --- Room9\n");
        printf("Objective: Find the treasure chest to win the game!\n\n");
    } else if (strcmp(command, "exit") == 0) {
        printf("Exiting game. Goodbye!\n");
        exit(0);
    } else {
        printf("Invalid command!\n");
    }
}

// Ana oyun döngüsü
void gameLoop(Game *game) {
    char command[50];

    while (1) {
        printf("\nEnter command: ");
        fgets(command, 50, stdin);
        command[strcspn(command, "\n")] = '\0'; // Newline karakterini sil
        processCommand(game, command);
    }
}
