#ifndef ITEM_H
#define ITEM_H

// Item structure definition
typedef struct Item {
    char name[50];        // The name of the item (e.g., "Dagger", "Health Potion")
    int value;            // The value or effect of the item (e.g., health restoration, attack boost)
    char description[256]; // A brief description of the item (e.g., "A sharp dagger")
} Item;

// Function to describe the item (prints the name, value, and description)
void describeItem(const Item *item);

#endif // ITEM_H
