/* Connect Four game where users input the row number (from left to right) that they
want to drop their token into

Author: Jessica Jiang
Date Last Modified: 31/03/23*/

#include <stdio.h>
#define width 9
#define height 8

// Function that initialises the board
void InitialiseBoard(char boardArray[height][width])
{

    int row, col, column;

    for (row = 0; row < height; row++)
    {
        column = 0;
        for (col = 0; col < width; col++)
        {
            // If it's the first or last row, character is '-'
            if (row == 0 || row == height - 1)
            {
                boardArray[row][column] = '-';
            }

            // If its the first of last column character is '|'
            else if (col == 0 || col == width - 1)
            {
                boardArray[row][column] = '|';
            }
            else
            {
                boardArray[row][column] = ' ';
            }
            column++;
        }
    }
}

// Function that prints the connect four board from the boardArray
void PrintBoard(char boardArray[height][width])
{

    int row, col;

    printf("\n  ");

    // Prints the column numbers on top of the board
    for (col = 0; col < width - 2; col++)
    {
        printf("%i ", col + 1);
    }

    printf("%c", '\n');

    for (row = 0; row < height; row++)
    {
        for (col = 0; col < width; col++)
        {
            if (row == 0 || row == height - 1)
            {
                printf("%c ", '-');
            }
            else if (col == 0 || col == width - 1)
            {
                printf("%c ", '|');
            }
            else
            {
                printf("%c ", boardArray[row][col]);
            }
        }
        printf("\n");
    }
}

/*Function that gets the column they want to drop their token into from the player*/
int GetMove(char boardArray[height][width], int player)
{
    int column, i;
    int valid = 0;
    i = 1;

    printf("\nPlayer %d Enter Column Number: ", player);

    // Gets the column number from the player
    scanf("%d", &column);

    // If the column is full, ask the player to enter a valid column
    while (boardArray[1][column] != ' ')
    {

        // Loops through all columns to check if there are any columns that aren't full
        for (int col = 0; col < width; col++)
        {
            // If there are any columns that aren't full, ask the player to enter a valid column
            if (boardArray[1][col] == ' ')
            {
                printf("Player %d Enter Valid Column Number: ", player);
                scanf("%d", &column);

                // Breaks the for loop
                col = width;
            }
        }
    }

    // Ignore any invalid columns
    while (valid == 0 && i < width)
    {
        if (i == column)
        {
            valid = 1;
            break;
        }
        i++;

        /* If the column is invalid (i has already looped through all columns),
        ask the player to enter a valid column */
        if (i == width - 1)
        {
            printf("Player %d Enter Valid Column Number: ", player);
            scanf("%d", &column);

            // Reset i to 1 to check if the column is valid again in the while loop
            i = 1;
        }
    }
    return column;
}

// Function that checks if the player has won
int CheckWin(char boardArray[height][width], int player)
{
    int count = 0;
    char symbol;
    int row;
    int col;
    int win = 0;

    // Assigns the correct symbol for each player
    if (player == 1)
    {
        symbol = 'X';
    }
    else
    {
        symbol = 'O';
    }

    // Check for vertical win

    for (col = 1; col < width - 1; col++)
    {
        count = 0;
        for (row = height - 1; row >= 0; row--)
        {
            // If the symbol is the same as the player's symbol, increment count
            if (boardArray[row][col] == symbol)
            {
                count++;

                if (count == 4)
                {
                    win = 1;
                }
            }

            // If the symbol is not the same as the player's symbol, reset count and continue the loop
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
        for (col = 1; col < width - 1; col++)
        {
            // If the symbol is the same as the player's symbol, increment count
            if (boardArray[row][col] == symbol)
            {
                count++;

                if (count == 4)
                {
                    win = 1;
                }
            }

            // If the symbol is not the same as the player's symbol, reset count and continue the loop
            else if (boardArray[row][col] != symbol && count >= 1)
            {
                count = 0;
            }
        }
    }

    // Check for left diagonal win
    int maxRow, maxCol;

    for (row = 0; row < height; row++)
    {
        for (col = 0; col < width; col++)
        {
            // Set the maximum row and column to check that they will be within the boardArray bounds
            maxRow = row - 3;
            maxCol = col + 3;

            // If the maximum row and column are within the boardArray bounds and there are 4 symbols in a left diagonal, the player has won
            if (maxRow >= 0 && maxCol < width && boardArray[row][col] == symbol && boardArray[row - 1][col + 1] == symbol && boardArray[row - 2][col + 2] == symbol && boardArray[row - 3][col + 3] == symbol)
            {
                win = 1;
            }
        }
    }

    // Check for right diagonal win
    for (row = 0; row < height; row++)
    {
        for (col = 0; col < width; col++)
        {
            // Set the maximum row and column to check that they will be within the boardArray bounds
            maxRow = row - 3;
            maxCol = col - 3;

            // If the maximum row and column are within the boardArray bounds and there are 4 symbols in a right diagonal, the player has won
            if (maxRow >= 0 && maxCol >= 0 && boardArray[row][col] == symbol && boardArray[row - 1][col - 1] == symbol && boardArray[row - 2][col - 2] == symbol && boardArray[row - 3][col - 3] == symbol)
            {
                win = 1;
            }
        }
    }

    // If the player has won, print the player that won and return 1
    if (win == 1)
    {
        if (player == 1)
        {
            printf("\n\nPlayer 1 Wins!!\n\n");
            return 1;
        }
        else
        {
            printf("\n\nPlayer 2 Wins!!\n\n");
            return 1;
        }
    }

    // Check for tie, when the boardArray is full and neither player has won
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // If the board is not full, break the loop and the function will return 0
            if (boardArray[i][j] == ' ')
            {
                i = height;
                break;
            }

            // If the board is full and neither player has won, print tie and return 1
            else if (i == height - 1 && j == width - 1)
            {
                printf("\n\nTie!!\n\n");
                return 1;
            }
        }
    }

    // If the player has not won, return 0
    return 0;
}

// Function that assigns the player's move to the boardArray
void MakeMove(char boardArray[height][width], int move, int player)
{
    int i;

    /* Loop through the boardArray from the bottom to the top and assign the player's symbol to the
    first empty space in the column */
    for (i = height - 1; i >= 0; i--)
    {
        if (boardArray[i][move] == ' ')
        {

            if (player == 1)
            {
                boardArray[i][move] = 'X';
                break;
            }

            else
            {
                boardArray[i][move] = 'O';
                break;
            }
        }
    }
}

// Main function that implements the connect four game
int main(void)
{
    /* Initialise the boardArray */
    char boardArray[height][width] = {0};

    InitialiseBoard(boardArray);
    PrintBoard(boardArray);

    int p1Win = 0;
    int p2Win = 0;

    /* Main game loop */

    // While neither player has won, continue the game
    while (p1Win == 0 && p2Win == 0)
    {
        // Player 1's turn
        int move1 = GetMove(boardArray, 1);
        MakeMove(boardArray, move1, 1);
        PrintBoard(boardArray);

        // Checks if player 1 has won and assigns the value to p1Win
        p1Win = CheckWin(boardArray, 1);

        // If player 1 has won, break the while loop
        if (p1Win == 1)
        {
            break;
        }

        // Player 2's turn
        int move2 = GetMove(boardArray, 2);
        MakeMove(boardArray, move2, 2);
        PrintBoard(boardArray);

        // Checks if player 2 has won and assigns the value to p2Win
        p2Win = CheckWin(boardArray, 2);
    }

    return 0;
}