// Task 1
#include <stdio.h>
#define CAVE_SIZE 10

/* This function prints the cave out.
1 is represented as '#' (a solid wall) and 0 is a blank space */

void PrintCave(int cave[CAVE_SIZE][CAVE_SIZE])
{
    int i = 0; //row
    int j = 0; //col
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            // If 1, then print a solid wall
            if (cave[i][j] == 1) {
                printf("#");
            // If 0, then print an 'empty space'
            } else if (cave[i][j] == 0) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(void)
{
    int caveA[CAVE_SIZE][CAVE_SIZE] = {
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1},
    };
    PrintCave(caveA);
    return 0;
}