#include <stdio.h>
#include "game.h"

int main() {
    Game game;

    // Oyunu başlat
    initGame(&game);

    // Kullanıcıdan komut bekleyen oyun döngüsünü başlat
    gameLoop(&game);

    return 0;
}
