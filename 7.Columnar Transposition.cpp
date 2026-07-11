#include <stdio.h>
#include <string.h>

int main()
{
    char text[100], pad;
    char matrix[20][20];
    int key, len, rows, i, j, k = 0;

    printf("Enter Plaintext: ");
    scanf("%s", text);

    printf("Enter Key Length (Columns): ");
    scanf("%d", &key);

    printf("Enter Padding Character: ");
    scanf(" %c", &pad);

    len = strlen(text);

    rows = len / key;
    if (len % key != 0)
        rows++;

    // Fill Matrix
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < key; j++)
        {
            if(k < len)
                matrix[i][j] = text[k++];
            else
                matrix[i][j] = pad;
        }
    }

    // Display Matrix
    printf("\nRow-wise Matrix:\n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < key; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }

    // Encryption
    printf("\nCiphertext: ");
    for(j = 0; j < key; j++)
    {
        for(i = 0; i < rows; i++)
            printf("%c", matrix[i][j]);
    }

    printf("\n");

    return 0;
}
