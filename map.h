#ifndef MAP_H
#define MAP_H

#include "room.h"

// 3x3 haritayı tanımlayan Map yapısı
typedef struct {
    Room *rooms[3][3];  // 3x3 oda matrisi
} Map;

// Haritayı başlatır ve odaları oluşturur
void initMap(Map *map);

// Belirli bir koordinattaki odayı döndürür
Room* getRoom(Map *map, int x, int y);

#endif
