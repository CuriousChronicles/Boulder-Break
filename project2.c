/* ENGGEN131 C Project 2022 - Boulder Break */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define CAVE_SIZE 10

// Task One: InitialiseStory
void InitialiseStory(char* paragraph) {
    char story[] = "A brave adventurer is stuck in a cave!\nWrite a new story here.";
    int i = 0;
    for (i=0; story[i] != '\0'; i++) {
        paragraph[i] = story[i];
    }
    paragraph[i] = '\0';
}

// Task Two: PrintCave
/* This function prints the cave out.
1 is represented as '#' (a solid wall) and 0 is a blank space */
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
            } else if (cave[i][j] == 'o') {
                // Print boulder
                printf("o");
            }
        }
        printf("\n");
    }
}

// Task Three: InitialiseCave
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

/* This function returns true if every element of the outer boarder of the maze only 
consists of solid walls or exit positions*/
int IsBorderComplete(int cave[CAVE_SIZE][CAVE_SIZE])
{
    int i = 0; //row
    int j = 0; //col
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if ((i == 0) || (i == 9)) {
                // If at top and bottom rows
                if (cave[i][j] == '0') {
                    // If it is a blank space then return 0
                    return 0;
                }
            } else if ((j == 0) || (j == 9)){
                // If at first or last column
                if  (cave[i][j] == '0') {
                    // If it is a blank space then return 0
                    return 0;
                }
            }
        }
    }
    return 1;
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

/* This function adds an item into the cave at a specified location*/
void AddItem(int cave[CAVE_SIZE][CAVE_SIZE], int row, int col, char *element)
{
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
            cave[row][col] = 'o';  
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

//int MakeMove(int cave[CAVE_SIZE][CAVE_SIZE], char move)
//{
//}


/***********************************************************/
/***********************************************************/
/******* A SIMPLE MAIN FUNCTION TO TEST YOUR PROGRESS ******/
/***********************************************************/
/***********************************************************/

/* You should add your own tests in here */
int main(void)
{
    int caveB[CAVE_SIZE][CAVE_SIZE] = {
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };
    PrintCave(caveB);
    printf("Complete? %d\n", IsBorderComplete(caveB));
    return 0;
    return 0;
}