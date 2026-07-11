#include <stdio.h>
#include <string.h>

void decrypt(char cipher[], int key)
{
    int len = strlen(cipher);
    int rows, i, j, index = 0;
    char matrix[20][20];
    char plain[100];

    rows = len / key;
    if (len % key != 0)
        rows++;

    // Fill matrix column-wise
    for(j = 0; j < key; j++)
    {
        for(i = 0; i < rows; i++)
        {
            if(index < len)
                matrix[i][j] = cipher[index++];
            else
                matrix[i][j] = 'X';
        }
    }

    // Read row-wise
    index = 0;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < key; j++)
        {
            if(index < len)
                plain[index++] = matrix[i][j];
        }
    }

    plain[len] = '\0';

    printf("Key Length %d : %s\n", key, plain);
}

int main()
{
    char cipher[100];

    printf("Enter Ciphertext: ");
    scanf("%s", cipher);

    printf("\nPossible Plaintexts:\n\n");

    for(int key = 2; key <= 8; key++)
    {
        decrypt(cipher, key);
    }

    printf("\nTop 5 Probable Plaintexts:\n");
    printf("(Choose the outputs that form meaningful English words.)\n");

    return 0;
}
