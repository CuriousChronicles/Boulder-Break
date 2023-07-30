// Task 5
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

/* This function checks if there is a single 'exit' position in the 2-D array*/
int IsExitUnique(int cave[CAVE_SIZE][CAVE_SIZE])
{
    int i = 0;
    int j = 0;
    int numExits = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if(cave[i][j] == 'E') {
                // If an exit is detected at the i,j then add 1 to numExits
                numExits++;
            }
        }
    }
    if (numExits == 1) {
        // If there is only one exit, then return 1
        return 1;
    } else {
        // If there is not a single exit, then return 0
        return 0;
    }
}

int main(void) 
{
    char layout[200] = "11111111111000000001100000000110000000011000E0000110000000011000000001100000000110000000011111111111"; 
    int cave[CAVE_SIZE][CAVE_SIZE] = {0}; 
    InitialiseCave(cave, layout); 
    PrintCave(cave); 
    printf("Unique? %d\n", IsExitUnique(cave));
    return 0;
}