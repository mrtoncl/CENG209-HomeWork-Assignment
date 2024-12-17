#include "creature.h"
#include <stdio.h>
#include <stdlib.h>

// Savaş başlatma fonksiyonu
void startBattle(Player *player, Creature *creature) {
    printf("Battle started with %s!\n", creature->name);

    while (player->health > 0 && creature->health > 0) {
        // Oyuncu saldırır
        printf("You attack the %s!\n", creature->name);
        creature->health -= player->strength;  // Yaratığın canını azalt

        if (creature->health <= 0) {
            // Yaratık öldü
            printf("You defeated the %s!\n", creature->name);
            return;
        }

        // Yaratık saldırır
        printf("The %s attacks you!\n", creature->name);
        player->health -= creature->attackPower;  // Oyuncunun canını azalt

        if (player->health <= 0) {
            // Oyuncu öldü
            printf("You were defeated by the %s...\n", creature->name);
            exit(0);  // Oyunu bitir
        }

        // Durum bilgisi
        printf("Your Health: %d | %s Health: %d\n", player->health, creature->name, creature->health);
    }
}


// Yaratığın açıklamasını yapar
void creatureDescription(const Creature *creature) {
    if (creature != NULL) {
        printf("Creature: %s\n", creature->name);
        printf("Health: %d\n", creature->health);
        printf("Attack Power: %d\n", creature->attackPower);
    }
}
