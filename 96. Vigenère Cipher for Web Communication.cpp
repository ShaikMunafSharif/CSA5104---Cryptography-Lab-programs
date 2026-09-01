#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char text[], char key[])
{
    int i, j = 0;
    int keyLen = strlen(key);

    for(i = 0; text[i] != '\0'; i++)
    {
        if(isalpha(text[i]))
        {
            char base = isupper(text[i]) ? 'A' : 'a';

            text[i] = (text[i] - base +
                       toupper(key[j % keyLen]) - 'A') % 26 + base;

            j++;
        }
    }
}

void decrypt(char text[], char key[])
{
    int i, j = 0;
    int keyLen = strlen(key);

    for(i = 0; text[i] != '\0'; i++)
    {
        if(isalpha(text[i]))
        {
            char base = isupper(text[i]) ? 'A' : 'a';

            text[i] = (text[i] - base -
                       (toupper(key[j % keyLen]) - 'A') + 26) % 26 + base;

            j++;
        }
    }
}

int main()
{
    char message[200];
    char key[50];
    char encrypted[200];

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    message[strcspn(message, "\n")] = '\0';

    printf("Enter keyword: ");
    scanf("%s", key);

    strcpy(encrypted, message);

    /* Encryption */
    encrypt(encrypted, key);

    printf("\n----- VIGENERE CIPHER -----\n");

    printf("Original Message : %s\n", message);
    printf("Keyword          : %s\n", key);
    printf("Encrypted Message: %s\n", encrypted);

    /* Decryption */
    decrypt(encrypted, key);

    printf("Decrypted Message: %s\n", encrypted);

    return 0;
}
