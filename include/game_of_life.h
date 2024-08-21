#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#define GRID_SIZE 20

typedef struct {
    int cells[GRID_SIZE][GRID_SIZE];
} Grid;

void initialize_grid(Grid *grid);
void update_grid(Grid *grid);
void print_grid(const Grid *grid);

#endif // GAME_OF_LIFE_H
