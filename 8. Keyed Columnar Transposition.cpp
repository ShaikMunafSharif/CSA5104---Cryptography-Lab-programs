#include <stdio.h>
#include <string.h>

int main()
{
    char text[100], key[20];
    char matrix[20][20];
    int rank[20];
    int len, rows, cols;
    int i, j, k = 0;

    printf("Enter Plaintext: ");
    scanf("%s", text);

    printf("Enter Keyword: ");
    scanf("%s", key);

    cols = strlen(key);
    len = strlen(text);

    rows = len / cols;
    if (len % cols != 0)
        rows++;

    // Fill Matrix
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            if(k < len)
                matrix[i][j] = text[k++];
            else
                matrix[i][j] = 'X';
        }
    }

    // Generate Ranking
    for(i = 0; i < cols; i++)
    {
        rank[i] = 1;
        for(j = 0; j < cols; j++)
        {
            if(key[j] < key[i])
                rank[i]++;
        }
    }

    printf("\nKeyword Ranking:\n");
    for(i = 0; i < cols; i++)
        printf("%c = %d\n", key[i], rank[i]);

    // Display Matrix
    printf("\nOriginal Matrix:\n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }

    // Encryption
    printf("\nCiphertext: ");

    for(k = 1; k <= cols; k++)
    {
        for(j = 0; j < cols; j++)
        {
            if(rank[j] == k)
            {
                for(i = 0; i < rows; i++)
                    printf("%c", matrix[i][j]);
            }
        }
    }

    printf("\n");

    return 0;
}
