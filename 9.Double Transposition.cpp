#include <stdio.h>
#include <string.h>
#include <time.h>

void transposition(char text[], int key, char result[])
{
    char matrix[20][20];
    int len = strlen(text);
    int rows, i, j, k = 0, index = 0;

    rows = len / key;
    if (len % key != 0)
        rows++;

    // Fill matrix row-wise
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < key; j++)
        {
            if(k < len)
                matrix[i][j] = text[k++];
            else
                matrix[i][j] = 'X';
        }
    }

    // Read column-wise
    for(j = 0; j < key; j++)
    {
        for(i = 0; i < rows; i++)
        {
            result[index++] = matrix[i][j];
        }
    }

    result[index] = '\0';
}

int main()
{
    char text[100], first[100], second[100];
    int key1, key2;
    clock_t start, end;

    printf("Enter Plaintext: ");
    scanf("%s", text);

    printf("Enter First Key (Columns): ");
    scanf("%d", &key1);

    printf("Enter Second Key (Columns): ");
    scanf("%d", &key2);

    start = clock();

    transposition(text, key1, first);
    printf("\nAfter First Transposition : %s\n", first);

    transposition(first, key2, second);
    printf("After Second Transposition: %s\n", second);

    end = clock();

    printf("\nExecution Time: %.6f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
