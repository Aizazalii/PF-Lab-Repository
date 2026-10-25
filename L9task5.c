#include <stdio.h>

void printGrid(int (*grid)[5]) {
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++)
            printf("%d ", grid[r][c]);
        printf("\n");
    }
}

int countNeighbours(int (*grid)[5], int row, int col) {
    int count = 0;
    for (int r = row - 1; r <= row + 1; r++)
        for (int c = col - 1; c <= col + 1; c++) {
            if (r == row && c == col) continue;           // skip itself
            if (r >= 0 && r < 5 && c >= 0 && c < 5)       // stay inside grid
                count += grid[r][c] & 1;                  // read bit 0 only
        }
    return count;
}

void nextGeneration(int (*grid)[5]) {
    for (int r = 0; r < 5; r++)
        for (int c = 0; c < 5; c++) {
            int n = countNeighbours(grid, r, c);
            int alive = grid[r][c] & 1;
            if ((alive && (n == 2 || n == 3)) || (!alive && n == 3))
                grid[r][c] |= 2;                          // set bit 1 = next state
        }
    for (int r = 0; r < 5; r++)
        for (int c = 0; c < 5; c++)
            grid[r][c] >>= 1;                             // next state becomes current
}

int main() {
    int grid[5][5] = {0};
    int gens;
    grid[1][2] = grid[2][2] = grid[3][2] = 1;

    do {
        printf("Enter number of generations (0-50): ");
        scanf("%d", &gens);
        if (gens < 0 || gens > 50)
            printf("Invalid number\n");
    } while (gens < 0 || gens > 50);

    printf("Generation 0:\n");
    printGrid(grid);
    for (int g = 1; g <= gens; g++) {
        nextGeneration(grid);
        printf("Generation %d:\n", g);
        printGrid(grid);
    }
    return 0;
}