#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game_of_life.h"

/*
void initialize_grid(Grid *grid) {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            grid->cells[i][j] = 0;  // Initialize all cells to dead
        }
    }

    // You can initialize some cells as alive for testing
    grid->cells[1][2] = 1;
    grid->cells[2][3] = 1;
    grid->cells[3][1] = 1;
    grid->cells[3][2] = 1;
    grid->cells[3][3] = 1;
}
*/
void initialize_grid(Grid *grid) {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the grid with random values
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            grid->cells[i][j] = rand() % 2;  // Randomly set cells to 0 or 1
        }
    }
}

void update_grid(Grid *grid) {
    Grid new_grid = *grid;

    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            int alive_neighbors = 0;

            // Count alive neighbors
            for (int x = -1; x <= 1; ++x) {
                for (int y = -1; y <= 1; ++y) {
                    if (x == 0 && y == 0) continue;
                    int ni = i + x;
                    int nj = j + y;
                    if (ni >= 0 && ni < GRID_SIZE && nj >= 0 && nj < GRID_SIZE) {
                        alive_neighbors += grid->cells[ni][nj];
                    }
                }
            }

            // Apply the rules of the game
            if (grid->cells[i][j] == 1) {
                if (alive_neighbors < 2 || alive_neighbors > 3) {
                    new_grid.cells[i][j] = 0;  // Cell dies
                }
            } else {
                if (alive_neighbors == 3) {
                    new_grid.cells[i][j] = 1;  // Cell becomes alive
                }
            }
        }
    }

    *grid = new_grid;  // Update the grid
}

void print_grid(const Grid *grid) {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            printf(grid->cells[i][j] ? "O " : ". ");
        }
        printf("\n");
    }
}
