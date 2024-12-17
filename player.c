#include "player.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initPlayer(Player *player, const char *name, int inventoryCapacity) {
    // Oyuncunun adını ayarla
    strncpy(player->name, name, sizeof(player->name) - 1);
    player->name[sizeof(player->name) - 1] = '\0';  // Güvenlik için null-terminate
    
    // Sağlık ve güç değerlerini başlat (isteğe bağlı)
    player->health = 100;
    player->strength = 10;

    player->inventoryCapacity = inventoryCapacity;  // Envanter kapasitesini ayarla
    player->inventory = malloc(inventoryCapacity * sizeof(Item*));  // Eşyalar için belleği ayır
    for (int i = 0; i < inventoryCapacity; i++) {
        player->inventory[i] = NULL;  // Envanteri başlat (boş öğeler)
    }
}

void addItemToInventory(Player *player, const Item *item) {
    for (int i = 0; i < player->inventoryCapacity; i++) {
        if (player->inventory[i] == NULL) {
            if(strcmp(item->name, "Dagger") == 0 || strcmp(item->name, "Rusty Sword") == 0){
                player->inventory[i] = (Item*)item;  // Eşyayı envantere ekle
                printf("Added %s to inventory.\n", item->name);
                player->strength += item->value;
                return;
            }
            if(strcmp(item->name, "Golden Talisman") == 0){
                player->inventory[i] = (Item*)item;  // Eşyayı envantere ekle
                printf("Added %s to inventory.\n", item->name);
                player->health += item->value;
                player->strength += item->value;
                return;
            }
            if(strcmp(item->name, "Health Potion") == 0 || strcmp(item->name, "Shield") == 0){
                printf("%s used!\n", item->name);
                player->health += item->value;
                return;
            }
            if(strcmp(item->name, "Door Key") == 0){
                player->inventory[i] = (Item*)item;  // Eşyayı envantere ekle
                printf("Added %s to inventory.\n", item->name);
                return;
            }
            if(strcmp(item->name, "Treasure Chest") == 0){
                printf("You win the game!\n");
                printf("GAME OVER!");
                exit(0);
            }
            
        }
    }
    printf("Inventory is full!\n");
}

void printInventory(const Player *player) {
    if(player->inventory[0] == NULL){
        printf("Inventory is empty!");
    }
    else{
        printf("Inventory:\n");
    for (int i = 0; i < player->inventoryCapacity; i++) {
        if (player->inventory[i] != NULL) {
            printf(" - %s\n", player->inventory[i]->name);  // Eşyaların ismini yazdırıyoruz
        }
    }
    }
    
}

void describePlayer(Player *player){
    printf("\nName: %s\n", player->name);
    printf("Health: %d\n", player->health);
    printf("Strength: %d\n", player->strength);
}
