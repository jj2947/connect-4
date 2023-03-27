/* Connect Four game where users input the row number (from left to right) that they
want to drop their token into

Author: Jessica Jiang
Date Last Modified: 27/3/23*/

#include <stdio.h>
#define width 7
#define height 6

// Function that prints the connect four board
void PrintBoard(char boardArray[height][width])
{

    int row, col, column;

    for (col = 0; col < width; col++)
    {
        printf("%i ", col + 1);
    }

    printf("%c", '\n');

    for (row = 0; row < height; row++)
    {
        column = 0;
        for (col = 0; col < width; col++)
        {

            if (row == 0 || row == height - 1)
            {
                boardArray[row][column] = '-';
                boardArray[row][column++] = '-';

                printf("%c ", '-');
            }
            else if (col == 0 || col == width - 1)
            {
                printf("%c ", '|');
                boardArray[row][column] = '|';
                boardArray[row][column++] = '|';
            }
            else
            {
                printf("  ");
                boardArray[row][column] = ' ';
                boardArray[row][column++] = ' ';
            }
            column++;
        }
        printf("\n");
    }
}

int main(void)
{
    char boardArray[height][width] = {0};

    PrintBoard(boardArray);
    return 0;
}