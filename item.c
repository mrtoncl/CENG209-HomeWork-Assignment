#include "item.h"
#include <stdio.h>
#include <string.h>

// Function to describe an item based on its name and attributes
void describeItem(const Item *item) {
    if (item != NULL) {
        // If the item is a Dagger or Rusty Sword, show attack value
        if(strcmp(item->name, "Dagger") == 0 || strcmp(item->name, "Rusty Sword") == 0){
            printf("Item: %s\n", item->name);
            printf("Description: %s\n", item->description);
            printf("Value: +%d attack\n", item->value);
        }
        // If the item is a Golden Talisman, show both attack and health value
        if(strcmp(item->name, "Golden Talisman") == 0){
            printf("Item: %s\n", item->name);
            printf("Description: %s\n", item->description);
            printf("Value: +%d attack & health\n", item->value);
        }
        // If the item is a Health Potion or Shield, show health value
        if(strcmp(item->name, "Health Potion") == 0 || strcmp(item->name, "Shield") == 0){
            printf("Item: %s\n", item->name);
            printf("Description: %s\n", item->description);
            printf("Value: +%d health\n", item->value);
        }
        // If the item is a Door Key, only show description (no value)
        if(strcmp(item->name, "Door Key") == 0){
            printf("Item: %s\n", item->name);
            printf("Description: %s\n", item->description);
        }
        // If the item is a Treasure Chest, only show description (no value)
        if(strcmp(item->name, "Treasure Chest") == 0){
            printf("Item: %s\n", item->name);
            printf("Description: %s\n", item->description);
        }
    }
}
