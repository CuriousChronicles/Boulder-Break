#include <stdio.h>
/* This function takes in a pointer to a character as input, this pointer will refer to an 
array of characters into which your story should be written.
Conditions:
- story must be longer than 100 printable characters
- Max length of story can be 1999 characters
- Story must be broken into lines
- Max length of any line is 60 printable characters
*/
void InitialiseStory(char* paragraph) {
    char story[] = "Your walking through an ancient Egyptian tomb,\nwith your small torch, quivering in the darkness\nand thinking?\nYou wouldn\'t be in this mess if you didn\'t have a hefty\ndept with a notorious loan shark.\nBut before you can think more about your bad decisions,\n you hear a click and whoosh.\nYou feel gravity pulling you, as if, into the depths of hell.\nThud!\nLuckily there was something soft to break your fall.\nLooking around you see huge boulders, deep pits, and?\nGOLD!\nCollect the gold and escape from the cave.\nWe\'ll deal with the loan sharks later!?";
    int i = 0;
    for (i=0; story[i] != '\0'; i++) {
        paragraph[i] = story[i];
    }
    paragraph[i] = '\0';
}

int main(void)
{
    char story[2000];
    InitialiseStory(story);
    printf("%s\n", story);

    return 0;
}