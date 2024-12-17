#include "trap.h"
#include <stdio.h>
#include <stdlib.h>

// Tuzak hakkında bilgi veren fonksiyon
void describeTrap(const Trap *trap) {
    if (trap != NULL) {
        printf("Trap name: %s\n", trap->name);
        printf("It can deal %d damage!\n", trap->damage);
    }
}

// Tuzak devreye girer ve oyuncuya hasar verir
void activateTrap(Trap *trap, Player *player) {
    if (trap != NULL && player != NULL) {
        printf("trYou triggered %s! It dealt %d damage!\n", trap->name, trap->damage);
        player->health -= trap->damage;

        // Oyuncunun sağlık durumunu kontrol et
        if (player->health <= 0) {
            printf("You died from the trap...\n");
            exit(0);  // Oyunu sonlandır
        }    
    }
}
