#include <stdio.h>
#include <string.h>

char rail[10][100];

int main()
{
    char text[100], cipher[100], decrypt[100];
    int rails, len, i, j;
    int row = 0, dir = 1, index = 0;

    printf("Enter Plaintext: ");
    scanf("%s", text);

    printf("Enter Number of Rails: ");
    scanf("%d", &rails);

    len = strlen(text);

    // Initialize matrix
    for(i = 0; i < rails; i++)
        for(j = 0; j < len; j++)
            rail[i][j] = ' ';

    // Fill Rail Matrix
    row = 0;
    dir = 1;

    for(i = 0; i < len; i++)
    {
        rail[row][i] = text[i];

        if(row == 0)
            dir = 1;
        else if(row == rails - 1)
            dir = -1;

        row += dir;
    }

    // Display Rail Matrix
    printf("\nRail Matrix:\n");
    for(i = 0; i < rails; i++)
    {
        for(j = 0; j < len; j++)
            printf("%c ", rail[i][j]);
        printf("\n");
    }

    // Encryption
    index = 0;
    for(i = 0; i < rails; i++)
    {
        for(j = 0; j < len; j++)
        {
            if(rail[i][j] != ' ')
                cipher[index++] = rail[i][j];
        }
    }
    cipher[index] = '\0';

    printf("\nEncrypted Text: %s\n", cipher);

    // -------- Decryption --------

    // Clear matrix
    for(i = 0; i < rails; i++)
        for(j = 0; j < len; j++)
            rail[i][j] = ' ';

    // Mark zigzag path
    row = 0;
    dir = 1;

    for(i = 0; i < len; i++)
    {
        rail[row][i] = '*';

        if(row == 0)
            dir = 1;
        else if(row == rails - 1)
            dir = -1;

        row += dir;
    }

    // Fill ciphertext
    index = 0;
    for(i = 0; i < rails; i++)
    {
        for(j = 0; j < len; j++)
        {
            if(rail[i][j] == '*')
                rail[i][j] = cipher[index++];
        }
    }

    // Read zigzag
    row = 0;
    dir = 1;

    for(i = 0; i < len; i++)
    {
        decrypt[i] = rail[row][i];

        if(row == 0)
            dir = 1;
        else if(row == rails - 1)
            dir = -1;

        row += dir;
    }

    decrypt[len] = '\0';

    printf("Decrypted Text: %s\n", decrypt);

    return 0;
}
