#include <stdio.h>
#include <unistd.h>  // For usleep
#include "game_of_life.h"

int main() {
    Grid grid;
    initialize_grid(&grid);

    while (1) {
        print_grid(&grid);
        update_grid(&grid);
        usleep(200000);  // Sleep for 200ms
        printf("\033[H\033[J");  // Clear the screen
    }

    return 0;
}
