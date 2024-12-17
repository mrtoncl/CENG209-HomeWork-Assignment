#include "room.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Odanın açıklamasını yapma fonksiyonu
void describeRoom(const Room *room) {
    if (room->creature != NULL) {
        printf("\nThere is a creature in this room!\n");
        creatureDescription(room->creature);  // Eğer yaratık varsa, onun açıklaması yapılacak
    }
    else{
        printf("\nThere is no creature around here, you are safe for now!\n");
    }
    
    printf("\n");

    if (room->item != NULL) {
        printf("You see something shining in the corner of the room.\n");
        describeItem(room->item);  // Eğer eşya varsa, onun açıklaması yapılacak
    }
    else{
        printf("There is no item in this room!\n");
    }
}

void roomEntryMessage(const Room *room){
    printf("\nYou're in: %s\n", room->description);
    if(strcmp(room->description, "Room 1 - A quiet chamber.") == 0){
        printf("It's pretty quite in here.\n");
    }
    if(strcmp(room->description, "Room 2 - A dimly lit hallway.") == 0){
        printf("Growling sounds are heard!?\n");
    }
    if(strcmp(room->description, "Room 3 - A dusty old library.") == 0){
        printf("You felt like you were stepping on something!\n");
    }
    if(strcmp(room->description, "Room 4 - A large dining room.") == 0){
        printf("A hissing sound is heard!?\n");
    }
    if(strcmp(room->description, "Room 5 - The central hub of the dungeon.") == 0){
        printf("It smells like blood...\n");
    }
    if(strcmp(room->description, "Room 6 - A narrow corridor.") == 0){
        printf("A mechanism is activated!!!\n");
    }
    if(strcmp(room->description, "Room 7 - A storage closet.") == 0){
        printf("Strange bone sounds are heard...\n");
    }
    if(strcmp(room->description, "Room 8 - A dark, damp cave.") == 0){
        printf("There are spider webs everywhere. Disgusting...\n");
    }
    if(strcmp(room->description, "Room 9 - A treasure room!") == 0){
        printf("You can feel that fire burns your skin...\n");
    }
}
