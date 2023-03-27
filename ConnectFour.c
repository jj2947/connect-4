/* Connect Four game where users input the row number (from left to right) that they
want to drop their token into

Author: Jessica Jiang
Date Last Modified: 27/3/23*/

#include <stdio.h>

// Function that prints the connect four board
void PrintBoard (int width, int height) {

    int row, col, column;

    char boardArray[height][width*2];

    for(col = 0; col < width; col++) {
        printf("%i ", col+1);
    }

    printf("%c", '\n');

    for (row = 0; row < height; row++) {
        column = 0;
        for (col = 0; col < width; col++) {

            if (row == 0 || row == height -1) {
                boardArray[row][column] = '-';
                boardArray[row][column++] = '-';
                
                printf("%c ", '-');
            } else if (col == 0 || col == width -1) {
                printf("%c ", '|') ;
                boardArray[row][column] = '|';
                boardArray[row][column++] = '|';
            } else {
                printf("  ");
            }
            column++;
        }
        printf("\n");
    }
}

int main (void) {
    PrintBoard(10,6);
}