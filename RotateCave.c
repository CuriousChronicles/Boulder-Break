// Task 8
#include <stdio.h>
#include <string.h>
#define  CAVE_SIZE 10
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
            } else if (cave[i][j] == 'X') {
                // Print player
                printf("X");
            } else if (cave[i][j] == '*') {
                // Print hole
                printf("*");
            } else if (cave[i][j] == '+') {
                // Print treasure
                printf("+");
            } else if (cave[i][j] == 'O') {
                // Print boulder
                printf("O");
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



/* This function adds an item into the cave at a specified location*/
void AddItem(int cave[CAVE_SIZE][CAVE_SIZE], int row, int col, char *element)
{
    // Check if the position is within the 2D array
    if (((row >= 0) && (row < 10)) && ((col >= 0) && (col < 10))) {
        // Check if there is already a player
        int i = 0;
        int j = 0;
        int numPlayer = 0;
        // If numPlayer = 1, then there is already a player
        // If numPLayer = 0, then there is no player in the cave
        for (i =0; i < 10 ; i++) {
            for (j = 0; j < 10; j++) {
                // If there is a player at any position in the cave, then, add 1 to numPlayer
                if (cave[i][j] == 'X') {
                    numPlayer++;
                }
            }
        }

        // Check if the spot is an empty spot
        if (cave[row][col] == 0) {
            // Add player, only if there is no other player in the cave already
            if (numPlayer == 0) {
                if (strcmp(element, "player") == 0) {
                    cave[row][col] = 'X';
                }
            }
            // Add hole, represented as a '*'
            if (strcmp(element, "hole") == 0) {
                cave[row][col] = '*';
            }
            // Add treasure, represented as a '+'
            if (strcmp(element, "treasure") == 0) {
                cave[row][col] = '+';
            }
            // Add boulder, represented as a 'o'
            if (strcmp(element, "boulder") == 0) {
                cave[row][col] = 'O';  
            }
        }
    }
}


/* This function modifies the cave by ritating it 90 degrees in the clockwise direction. 
All the contents of the cave also rotate 90 degrees*/
void RotateCave(int cave[CAVE_SIZE][CAVE_SIZE])
{
    // Temporary array
    int temp[CAVE_SIZE][CAVE_SIZE];
    int i = 0; //row 
    int j = 0; //col 

    // Copy 90 degree cave to temp array
    for (i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            temp[j][9-i] = cave[i][j];
        }
    }
    // copy temp array to cave
    int m = 0;
    int n = 0;
    for (m = 0; m < 10; m++) {
        for (n = 0; n < 10; n++) {
            cave[m][n] = temp[m][n];
        }
    }
}

int main(void)
{
    char layoutA[200] = "1111111111100000000110000000011000000001100000000E10000000011000000001100000000110000000011111111111";
    int caveA[CAVE_SIZE][CAVE_SIZE] = {0};
    InitialiseCave(caveA, layoutA);
    AddItem(caveA, 7, 3, "player");
    AddItem(caveA, 2, 2, "boulder");
    AddItem(caveA, 2, 3, "boulder");
    AddItem(caveA, 4, 6, "boulder");
    AddItem(caveA, 5, 7, "boulder");
    AddItem(caveA, 6, 8, "boulder");
    AddItem(caveA, 7, 1, "hole");
    AddItem(caveA, 8, 3, "hole");
    AddItem(caveA, 6, 4, "treasure");
    AddItem(caveA, 3, 5, "treasure");
    AddItem(caveA, 1, 1, "treasure");
    AddItem(caveA, 8, 8, "treasure");
    AddItem(caveA, 5, 1, "hole");
    AddItem(caveA, 6, 1, "hole");
    RotateCave(caveA);
    RotateCave(caveA);
    PrintCave(caveA);
    return 0;
}