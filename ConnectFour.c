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

            if (row == 0 || row == height - 1)
            {
                boardArray[row][column] = '-';
            }
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

// Function that prints the connect four board
void PrintBoard(char boardArray[height][width])
{

    int row, col;

    printf("\n  ");

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

    scanf("%d", &column);

    while (boardArray[1][column] != ' ')
    {
        for (int col = 0; col < width; col++)
        {
            if (boardArray[1][col] == ' ')
            {
                printf("Player %d Enter Valid Column Number: ", player);
                scanf("%d", &column);
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
        else
        {
            i++;
        }

        if (i == width - 1)
        {
            printf("Player %d Enter Valid Column Number: ", player);
            scanf("%d", &column);
            i = 1;
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
    int win = 0;

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
            if (boardArray[row][col] == symbol)
            {
                count++;

                if (count == 4)
                {
                    win = 1;
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
        for (col = 1; col < width - 1; col++)
        {
            if (boardArray[row][col] == symbol)
            {
                count++;

                if (count == 4)
                {
                    win = 1;
                }
            }
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
            maxRow = row - 3;
            maxCol = col + 3;
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
            maxRow = row - 3;
            maxCol = col - 3;
            if (maxRow >= 0 && maxCol >= 0 && boardArray[row][col] == symbol && boardArray[row - 1][col - 1] == symbol && boardArray[row - 2][col - 2] == symbol && boardArray[row - 3][col - 3] == symbol)
            {
                win = 1;
            }
        }
    }

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

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (boardArray[i][j] == ' ')
            {
                i = height;
                break;
            }
            else if (i == height - 1 && j == width - 1)
            {
                printf("\n\nTie!!\n\n");
                return 1;
            }
        }
    }
    return 0;
}

// Function that assigns the player's move to the boardArray
void MakeMove(char boardArray[height][width], int move, int player)
{

    int i;

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

int main(void)
{
    char boardArray[height][width] = {0};

    InitialiseBoard(boardArray);
    PrintBoard(boardArray);

    int p1Win = 0;
    int p2Win = 0;

    /* Main game loop */
    while (p1Win == 0 && p2Win == 0)
    {
        int move1 = GetMove(boardArray, 1);
        MakeMove(boardArray, move1, 1);
        PrintBoard(boardArray);
        p1Win = CheckWin(boardArray, 1);

        if (p1Win == 1)
        {
            break;
        }

        int move2 = GetMove(boardArray, 2);
        MakeMove(boardArray, move2, 2);
        PrintBoard(boardArray);
        p2Win = CheckWin(boardArray, 2);
    }

    return 0;
}