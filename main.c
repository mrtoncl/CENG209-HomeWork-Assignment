#include <stdio.h>
#include "game.h"

int main() {
    Game game;  // Declare a Game instance

    // Initialize the game by setting up the player and the initial room
    initGame(&game);

    // Start the game loop, where the user can enter commands
    gameLoop(&game);

    return 0;  // Exit the program
}
