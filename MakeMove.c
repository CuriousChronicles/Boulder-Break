// Task 9
#include <stdio.h>
#include <string.h>
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



/* This function */
int MakeMove(int cave[CAVE_SIZE][CAVE_SIZE], char move)
{
    // Response
    // Rotate board so that player is always moving in the rightward direction
    if (move == 'w') {
        // If movement up ('w'), rotate 90 degrees clockwise
        RotateCave(cave);
    } else if (move == 'a') {
        // If movement left ('a'), rotate 180 degrees clockwise
        RotateCave(cave);
        RotateCave(cave);
    } else if (move == 's') {
        // If movement down ('s'), rotate 270 degrees clockwise
        RotateCave(cave);
        RotateCave(cave);
        RotateCave(cave);
    }
    // No rotation needed for 'd'

    // Find position of player, X
    int i = 0;
    int j = 0;
    int player_row, player_col;
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            if(cave[i][j] == 'X') {
                player_row = i;
                player_col = j;
                break;
            }
        }
    }
    // Decide movement
    if (cave[player_row][player_col + 1] == 0) {
        // If there a blank space
        // Move player to that spot
        cave[player_row][player_col] = 0;
        cave[player_row][player_col + 1] = 'X';

        // Rotate cave, back to original state
        if (move == 'w') {
            // If movement was up ('w'), rotate 270 degrees clockwise
            RotateCave(cave);
            RotateCave(cave);
            RotateCave(cave);
        } else if (move == 'a') {
            // If movement left ('a'), rotate 180 degrees clockwise
            RotateCave(cave);
            RotateCave(cave);
        } else if (move == 's') {
            // If movement down ('s'), rotate 270 degrees clockwise
            RotateCave(cave);
        }

        return 0;
    } else if (cave[player_row][player_col + 1] == 'E') {
        // If exit, move to exit space, return 2
        cave[player_row][player_col] = 0;
        cave[player_row][player_col + 1] = 'X';

        // Rotate cave, back to original state
        if (move == 'w') {
            // If movement was up ('w'), rotate 270 degrees clockwise
            RotateCave(cave);
            RotateCave(cave);
            RotateCave(cave);
        } else if (move == 'a') {
            // If movement left ('a'), rotate 180 degrees clockwise
            RotateCave(cave);
            RotateCave(cave);
        } else if (move == 's') {
            // If movement down ('s'), rotate 270 degrees clockwise
            RotateCave(cave);
        }

        return 2;
    } else if (cave[player_row][player_col + 1] == '*') {
        // If hole, player falls into the hole and disapears, return 1
        cave[player_row][player_col] = 0;
        cave[player_row][player_col + 1] = '*';

        // Rotate cave, back to original state
        if (move == 'w') {
            // If movement was up ('w'), rotate 270 degrees clockwise
            RotateCave(cave);
            RotateCave(cave);
            RotateCave(cave);
        } else if (move == 'a') {
            // If movement left ('a'), rotate 180 degrees clockwise
            RotateCave(cave);
            RotateCave(cave);
        } else if (move == 's') {
            // If movement down ('s'), rotate 270 degrees clockwise
            RotateCave(cave);
        }

        return 1;
    } else if (cave[player_row][player_col + 1] == '+') {
        // If treasure, player takes treasure, return 0
        cave[player_row][player_col] = 0;
        cave[player_row][player_col + 1] = 'X';

        // Rotate cave, back to original state
        if (move == 'w') {
            // If movement was up ('w'), rotate 270 degrees clockwise
            RotateCave(cave);
            RotateCave(cave);
            RotateCave(cave);
        } else if (move == 'a') {
            // If movement left ('a'), rotate 180 degrees clockwise
            RotateCave(cave);
            RotateCave(cave);
        } else if (move == 's') {
            // If movement down ('s'), rotate 270 degrees clockwise
            RotateCave(cave);
        }

        return 0;
    } else if (cave[player_row][player_col + 1] == 'O') {
        // If boulder, player does not move
        // The boulder, moves until it hits an object, return 0

        // Initial boulder pos
        int boulder_row = player_row;
        int boulder_col = player_col + 1;
        while (cave[boulder_row][boulder_col + 1] == 0) {
            cave[boulder_row][boulder_col] = 0;
            boulder_col++;
            cave[boulder_row][boulder_col] = 'O';
        }
        if (cave[boulder_row][boulder_col + 1] == '*') {
            // If boulder reaches a hole, hole and boulder disapear
            cave[boulder_row][boulder_col] = 0;
            cave[boulder_row][boulder_col + 1] = 0;
        } else if (cave[boulder_row][boulder_col + 1] == 'E') {
            // If boulder reaches the exit, the boulder disapears and exit remains
            cave[boulder_row][boulder_col] = 0;
        }

        // Rotate cave, back to original state
        if (move == 'w') {
            // If movement was up ('w'), rotate 270 degrees clockwise
            RotateCave(cave);
            RotateCave(cave);
            RotateCave(cave);
        } else if (move == 'a') {
            // If movement left ('a'), rotate 180 degrees clockwise
            RotateCave(cave);
            RotateCave(cave);
        } else if (move == 's') {
            // If movement down ('s'), rotate 270 degrees clockwise
            RotateCave(cave);
        }
        return 0;
    } else {
        // If a wall, cannot move, return 0

        // Rotate cave, back to original state
        if (move == 'w') {
            // If movement was up ('w'), rotate 270 degrees clockwise
            RotateCave(cave);
            RotateCave(cave);
            RotateCave(cave);
        } else if (move == 'a') {
            // If movement left ('a'), rotate 180 degrees clockwise
            RotateCave(cave);
            RotateCave(cave);
        } else if (move == 's') {
            // If movement down ('s'), rotate 270 degrees clockwise
            RotateCave(cave);
        }
        return 0;
    }
}

int main(void)
{
    char layout[200] = "111111000110001100011E111";
    int cave[CAVE_SIZE][CAVE_SIZE];
    InitialiseCave(cave, layout);
    AddItem(cave, 1, 1, "player");
    AddItem(cave, 2, 2, "boulder");
    AddItem(cave, 3, 1, "hole");

    MakeMove(cave, 'd');
    MakeMove(cave, 'd');
    MakeMove(cave, 's');
    MakeMove(cave, 'a');
    MakeMove(cave, 'a');
    MakeMove(cave, 'w');
    MakeMove(cave, 'a');
    MakeMove(cave, 's');
    MakeMove(cave, 's');
    MakeMove(cave, 's');

    PrintCave(cave);
    return 0;
}
