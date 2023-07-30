// Task 6
#include <stdio.h>
#define CAVE_SIZE 10
/* This function prints the cave out.
1 is represented as '#' (a solid wall), 0 and 'E' is a blank space */
void PrintCave(int cave[CAVE_SIZE][CAVE_SIZE])
{
    int i = 0; //row
    int j = 0; //col
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (cave[i][j] == 1) {
                printf("#");
            } else if (cave[i][j] == 0) {
                printf(" ");
            } else if (cave[i][j] == 'E') {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/* This function initialises each element of the array using the values in the string.
The value '0' represents an empty space, the value '1' represents a solid wall, 
and the value 'E' represents an exit. */
void InitialiseCave(int cave[CAVE_SIZE][CAVE_SIZE], char *layout)
{
    int i = 0; //rows
    int j = 0; // cols
    // Run through the cave from left to right, top to bottom
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (layout[10*i + j] == '1') {
                // If layout at 10*i + j is '1' store int 1 int cave array
                cave[i][j] = 1;
            } else if (layout[10*i + j] == 'E') {
                // If layout at 10*i + j is 'E' store int 69 ('E') int cave array
                cave[i][j] = 'E';
            } else {
                // If layout at 10*i + j is '0' store int 0 int cave array
                cave[i][j] = 0;
            }
        }
    }
}


/* This funciton checks the location of the exit.
It the exit is on the outside of the boarder and is not on a corner, then the function returns true.
Otherwise it should return false*/
int IsExitAccessible(int cave[CAVE_SIZE][CAVE_SIZE])
{
    int i = 0;
    int j = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (cave[i][j] == 'E') {
                // Check if exit is in the corner
                if (((i == 0) && (j == 0)) || ((i == 0) && (j == 9)) || ((i == 9) && (j == 0)) || ((i == 9) && (j == 9))){
                    // If condition true, then return 0
                    return 0;
                // Check if exit position of on the outside
                } else if ((i == 0) || (i == 9) || (j == 0) || (j == 9)) {
                    // If exit is on the outside, return 1
                    return 1;
                } else {
                    // Else, it therefore must be inside of cave, so return 0
                    return 0;
                }
            }
        }
    }
    // 0 means it did not find E
    return 0;
}
int main(void)
{
    char layoutB[200] = "1111111111E00000000110000000011000000001100000000110000000011000000001100000000110000000011111111111";
    int caveB[CAVE_SIZE][CAVE_SIZE] = {0};
    InitialiseCave(caveB, layoutB);
    PrintCave(caveB);
    printf("Accessible? %d\n", IsExitAccessible(caveB));

	return 0;
}