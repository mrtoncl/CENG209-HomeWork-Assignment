#ifndef TRAP_H
#define TRAP_H

#include "player.h"  // Oyuncuya hasar vermek için

// Trap yapısı
typedef struct {
    char name[50];  // Tuzak adı
    int damage;     // Tuzak hasar değeri
} Trap;

// Trap işlev prototipleri
void describeTrap(const Trap *trap);          // Tuzak hakkında bilgi verir
void activateTrap(Trap *trap, Player *player); // Tuzak devreye girer ve oyuncuya hasar verir

#endif // TRAP_H
