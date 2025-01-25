#include <stdio.h>
#include <stdlib.h>

void Free(int **board, int *row, int *col)
{
    for (int i = 0; i < 8; i++)
    {
        free(board[i]);
    }
    free(board);
    free(row);
    free(col);
}

int main()
{
    int **board = calloc(8, sizeof(int *));
    int *row = calloc(8, sizeof(int));
    int *col = calloc(8, sizeof(int));
    int cnt = 0;
    // int row[8];
    // int col[8];

    for (int i = 0; i < 8; i++)
    {
        board[i] = calloc(8, sizeof(int));
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char res;
            scanf(" %c", &res); // Added space before %c to consume leftover newline

            if (res == '*')
            {
                cnt++;
                board[i][j] = 1;

                // Check for invalid state in rows and columns
                if (row[i] == 1 || col[j] == 1)
                {
                    printf("invalid\n");
                    Free(board, row, col);
                    return 0;
                }

                row[i] = 1;
                col[j] = 1;

                // Check top-left diagonal
                for (int a = i - 1, b = j - 1; a >= 0 && b >= 0; a--, b--)
                {
                    if (board[a][b] == 1)
                    {
                        printf("invalid\n");
                        Free(board, row, col);
                        return 0;
                    }
                }

                // Check top-right diagonal
                for (int a = i - 1, b = j + 1; a >= 0 && b < 8; a--, b++)
                {
                    if (board[a][b] == 1)
                    {
                        printf("invalid\n");
                        Free(board, row, col);
                        return 0;
                    }
                }

                // Check bottom-left diagonal
                for (int a = i + 1, b = j - 1; a < 8 && b >= 0; a++, b--)
                {
                    if (board[a][b] == 1)
                    {
                        printf("invalid\n");
                        Free(board, row, col);
                        return 0;
                    }
                }

                // Check bottom-right diagonal
                for (int a = i + 1, b = j + 1; a < 8 && b < 8; a++, b++)
                {
                    if (board[a][b] == 1)
                    {
                        printf("invalid\n");
                        Free(board, row, col);
                        return 0;
                    }
                }
            }
        }
    }

    if (cnt != 8)
    {
        printf("invalid\n");
        return 0;
    }
    else
    {
        printf("valid\n");
    }
    Free(board, row, col);
    return 0;
}
