#include "map.h"
#include "creature.h"
#include "item.h"
#include "trap.h"
#include <stdlib.h>
#include <string.h>

// Odaların açıklamaları
const char *descriptions[3][3] = {
    {"Room 1 - A quiet chamber.", "Room 2 - A dimly lit hallway.", "Room 3 - A dusty old library."},
    {"Room 4 - A large dining room.", "Room 5 - The central hub of the dungeon.", "Room 6 - A narrow corridor."},
    {"Room 7 - A storage closet.", "Room 8 - A dark, damp cave.", "Room 9 - A treasure room!"}
};

// Creatures
Creature goblin = {"Goblin", 20, 5};
Creature orc = {"Orc", 40, 8};
Creature snake = {"Snake", 40, 8};
Creature skeleton = {"Skeleton", 30, 10};
Creature spider = {"Spider", 50, 12};
Creature vampire = {"Vampire", 60, 10};
Creature dragon = {"Dragon", 80, 25};


//Items
Item sword = {"Rusty Sword", 10, "You can use it for increasing your damage!"};
Item dagger = {"Dagger", 20, "You can use it for increasing your damage!"};
Item talisman = {"Golden Talisman", 10, "If you pickup, your attack damage and health will increase!"};
Item healthPot = {"Health Potion", 20, "If you use, your health will increase!"};
Item shield = {"Shield", 10, "You can defend yourself with this!"};
Item key = {"Door Key", 0, "This might open a door somewhere..."};
Item tresaure = {"Treasure Chest", 1000, "Open the chest, win the game!"};

//Traps
Trap bearTrap = {"Bear Trap", 10};
Trap fireTrap = {"Fire Trap", 15};

// Haritayı başlatır ve odaları oluşturur
void initMap(Map *map) {
    // Tüm odaları oluştur
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            map->rooms[i][j] = malloc(sizeof(Room));
            strcpy(map->rooms[i][j]->description, descriptions[i][j]);
            map->rooms[i][j]->up = map->rooms[i][j]->down = NULL;
            map->rooms[i][j]->left = map->rooms[i][j]->right = NULL;
            map->rooms[i][j]->creature = NULL;  // Başlangıçta yaratık yok
            map->rooms[i][j]->item = NULL;      // Başlangıçta eşya yok
        }
    }

    // Odaları bağla
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i > 0) map->rooms[i][j]->up = map->rooms[i - 1][j];  // North
            if (i < 2) map->rooms[i][j]->down = map->rooms[i + 1][j]; // South
            if (j > 0) map->rooms[i][j]->left = map->rooms[i][j - 1]; // West
            if (j < 2) map->rooms[i][j]->right = map->rooms[i][j + 1]; // East
        }
    }

    // Örnek olarak bazı odalara yaratık ve eşya ekleyelim
    map->rooms[0][0]->creature = &goblin;       
    map->rooms[0][0]->item = NULL; 
    map->rooms[0][0]->trap = NULL;             

    map->rooms[0][1]->trap = NULL;
    map->rooms[0][1]->creature = &orc;       
    map->rooms[0][1]->item = &sword;           

    map->rooms[0][2]->trap = &bearTrap;
    map->rooms[0][2]->creature = NULL;     
    map->rooms[0][2]->item = &healthPot;

    map->rooms[1][0]->trap = NULL;
    map->rooms[1][0]->creature = &snake;     
    map->rooms[1][0]->item = &dagger;

    map->rooms[1][1]->trap = NULL;
    map->rooms[1][1]->creature = &vampire;      
    map->rooms[1][1]->item = NULL;

    map->rooms[1][2]->trap = &fireTrap;
    map->rooms[1][2]->creature = NULL;      
    map->rooms[1][2]->item = &shield;

    map->rooms[2][0]->trap = NULL;
    map->rooms[2][0]->creature = &skeleton;     
    map->rooms[2][0]->item = &key;

    map->rooms[2][1]->trap = NULL;
    map->rooms[2][1]->creature = &spider;      
    map->rooms[2][1]->item = &talisman;

    map->rooms[2][2]->trap = NULL;
    map->rooms[2][2]->creature = &dragon;      
    map->rooms[2][2]->item = &tresaure;
}

// Belirli bir koordinattaki odayı döndürür
Room* getRoom(Map *map, int x, int y) {
    if (x >= 0 && x < 3 && y >= 0 && y < 3) {
        return map->rooms[x][y];
    }
    return NULL;  // Geçersiz koordinat
}
