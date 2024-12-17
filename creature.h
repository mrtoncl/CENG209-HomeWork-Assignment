#ifndef CREATURE_H
#define CREATURE_H

#include "player.h"

typedef struct {
    char name[50];
    int health;
    int attackPower;
} Creature;

// Savaş başlatma fonksiyonu
void startBattle(Player *player, Creature *creature);

// Yaratığı açıklayan fonksiyon
void creatureDescription(const Creature *creature);

#endif // CREATURE_H
