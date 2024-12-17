#include "item.h"
#include <stdio.h>
#include <string.h>

// Eşyayı açıklayan fonksiyon
void describeItem(const Item *item) {
    if (item != NULL) {
        if(strcmp(item->name, "Dagger") == 0 || strcmp(item->name, "Rusty Sword") == 0){
            printf("Item: %s\n", item->name);
            printf("Description: %s\n", item->description);
            printf("Value: +%d attack\n", item->value);
        }
        if(strcmp(item->name, "Golden Talisman") == 0){
            printf("Item: %s\n", item->name);
            printf("Description: %s\n", item->description);
            printf("Value: +%d attack & health\n", item->value);
        }
        if(strcmp(item->name, "Health Potion") == 0 || strcmp(item->name, "Shield") == 0){
            printf("Item: %s\n", item->name);
            printf("Description: %s\n", item->description);
            printf("Value: +%d health\n", item->value);
        }
        if(strcmp(item->name, "Door Key") == 0){
            printf("Item: %s\n", item->name);
            printf("Description: %s\n", item->description);
        }
        if(strcmp(item->name, "Treasure Chest") == 0){
            printf("Item: %s\n", item->name);
            printf("Description: %s\n", item->description);
        }
    }
}
