/* Connect Four game where users input the row number (from left to right) that they
want to drop their token into

Author: Jessica Jiang
Date Last Modified: */

#include <stdio.h>
#define width 7
#define height 6

// Function that prints the connect four board
void PrintBoard(char boardArray[height][width])
{

    int row, col, column;

    for (col = 0; col < width; col++)
    {
        printf("%i", col + 1);
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

                printf("%c", '-');
            }
            else if (col == 0 || col == width - 1)
            {
                printf("%c", '|');
                boardArray[row][column] = '|';
            }
            else
            {
                printf(" ");
                boardArray[row][column] = ' ';
            }
            column++;
        }
        printf("\n");
    }
}

/*Function that gets the column they want to drop their token into from the player*/
int GetMove()
{
    int column, i;
    int valid = 0;
    i = 1;
    printf("\nEnter Column Number: ");

    // Ignore any invalid columns
    scanf("%d", &column);

    while (valid == 0 && i <= width)
    {
        if (i == column)
        {
            valid = 1;
            return column;
        }
        else
        {
            i++;
        }

        if (i == width + 1)
        {
            printf("Enter Column Number: ");
            scanf("%d", &column);
            i = 0;
        }
    }
    return column;
}

int CheckWin(char boardArray[height][width], int player)
{

    int count = 0;
    char symbol;
    int row;
    int col;

    if (player == 1)
    {
        symbol = 'X';
    }
    else
    {
        symbol = 'O';
    }

    // Check for vertical win
    for (col = 0; col < width; col++)
    {
        count = 0;
        for (row = height - 1; row >= 0; row--)
        {
            if (boardArray[row][col] == symbol)
            {
                count++;

                if (count == 4)
                {
                    return 1;
                }
            }
            else if (boardArray[row][col] != symbol && count >= 1)
            {
                count = 0;
            }
        }
    }

    // Check for horizontal win
    for (row = height - 1; row >= 0; row--)
    {
        count = 0;
        for (col = 0; col < width; col++)
        {
            if (boardArray[row][col] == symbol)
            {
                count++;

                if (count == 4)
                {
                    return 1;
                }
            }
            else if (boardArray[row][col] != symbol && count >= 1)
            {
                count = 0;
            }
        }
    }
}

int MakeMove(int boardArray[height][width], int move, int player)
{

    int i;

    for (i = height - 1; i > 0; i++)
    {
        if (boardArray[i][move] == ' ')
        {

            if (player == 1)
            {
                boardArray[i][move] = 'X';
                return move;
            }
            else
            {
                boardArray[i][move] = 'O';
                return move;
            }
        }
    }
    return -1;
}

int main(void)
{
    char boardArray[height][width] = {0};

    PrintBoard(boardArray);
    GetMove();
    return 0;
}