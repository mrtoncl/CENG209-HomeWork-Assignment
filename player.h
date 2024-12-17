#ifndef PLAYER_H
#define PLAYER_H

#include "item.h"  // Item'ı dahil et

typedef struct Player {
    char name[50];
    int health;
    int strength;
    int inventoryCapacity;  // Envanter kapasitesi
    Item **inventory;       // Envanterdeki eşyaların işaretçileri (Item* türünde dizi)
} Player;

// Fonksiyon prototipleri
void initPlayer(Player *player, const char *name, int inventoryCapacity);  // İsim ve kapasite alacak
void printInventory(const Player *player);
void addItemToInventory(Player *player, const Item *item);
void describePlayer(Player *player);

#endif // PLAYER_H
