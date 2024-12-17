#ifndef ITEM_H
#define ITEM_H

typedef struct Item {
    char name[50];        // Eşyanın adı
    int value;            // Eşyanın değeri veya etkisi (örneğin, sağlık iyileştirmesi)
    char description[256]; // Eşyanın açıklaması
} Item;

// Eşyayı açıklayan fonksiyon
void describeItem(const Item *item);

#endif // ITEM_H
