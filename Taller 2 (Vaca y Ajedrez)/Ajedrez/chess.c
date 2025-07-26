#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *in, *out;

    char c, piece;
    int i = 0, j, row, col, rowMove = 0, colMove = 0;

    in = fopen("tableroin.txt", "r");
    out = fopen("tablerout.txt", "w");

    if (in != NULL)
    {

        while (fscanf(in, "%c", &c) == 1)
        {
            i++;
            j = 0;

            while (c != '\n' && !feof(in))
            {
                j++;

                if (c != '*')
                {
                    piece = c;
                    row = i;
                    col = j;
                }
                fscanf(in, "%c", &c);
            }
        }
    }

    if (piece == 'C')
    {
        printf("Caballo encontrado en la posicion (%d, %d).\n", row, col);

        for (int i = 0; i < 8; i++)
        {

            if (i < 4)
            {
                if (i < 2)
                {
                    rowMove = row - 2;
                }
                else
                {
                    rowMove = row + 2;
                }

                if (i % 2 == 0)
                {
                    colMove = col - 1;
                }
                else
                {
                    colMove = col + 1;
                }
            }
            else
            {
                if (i < 6)
                {
                    colMove = col - 2;
                }
                else
                {
                    colMove = col + 2;
                }

                if (i % 2 == 0)
                {
                    rowMove = row - 1;
                }
                else
                {
                    rowMove = row + 1;
                }
            }

            if (rowMove > 0 && rowMove < 7 && colMove > 0 && colMove < 7 && i < 7)
            {
                printf("(%d, %d); ", rowMove, colMove);
            }
        }
        printf("(%d, %d).\n", rowMove, colMove);
    }
    else
    {

        printf("Torre encontrada en la posicion (%d, %d).\n", row, col);
        printf("Los posibles movimientos son:\n");

        for (int i = 1; i <= 2; i++)
        {
            if (row + i > 0 && row + i < 7)
                printf("(%d, %d);", row + i, col);
        }
        for (int i = 1; i <= 2; i++)
        {
            if (row - i > 0 && row - i < 7)
                printf("(%d, %d);", row - i, col);
        }
        for (int i = 1; i <= 2; i++)
        {
            if (col + i > 0 && col + i < 7)
                printf("(%d, %d);", row, col + i);
        }

        if (col - 1 > 0 && col - 1 < 7)
            printf("(%d, %d);", row, col - 1);
        if (col - 2 > 0 && col - 2 < 7)
            printf("(%d, %d).\n", row, col - 2);
    }

    printf("Seleccione uno de ellos (fil, col): ");
    scanf("%d %d", &row, &col);

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {

            if (i == row - 1 && j == col - 1)
            {
                fprintf(out, "%c", piece);
            }
            else
            {
                fprintf(out, "*");
            }
        }
        fprintf(out, "\n");
    }

    fclose(in);
    fclose(out);
    return 0;
}
