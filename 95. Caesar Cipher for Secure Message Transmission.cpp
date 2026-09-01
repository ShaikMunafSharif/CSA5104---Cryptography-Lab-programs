#include <stdio.h>
#include <string.h>

void encrypt(char text[], int key)
{
    int i;

    for(i = 0; text[i] != '\0'; i++)
    {
        if(text[i] >= 'A' && text[i] <= 'Z')
            text[i] = (text[i] - 'A' + key) % 26 + 'A';

        else if(text[i] >= 'a' && text[i] <= 'z')
            text[i] = (text[i] - 'a' + key) % 26 + 'a';
    }
}

void decrypt(char text[], int key)
{
    int i;

    for(i = 0; text[i] != '\0'; i++)
    {
        if(text[i] >= 'A' && text[i] <= 'Z')
            text[i] = (text[i] - 'A' - key + 26) % 26 + 'A';

        else if(text[i] >= 'a' && text[i] <= 'z')
            text[i] = (text[i] - 'a' - key + 26) % 26 + 'a';
    }
}

int main()
{
    char message[100];
    char encrypted[100];
    int key;

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    message[strcspn(message, "\n")] = '\0';

    printf("Enter key: ");
    scanf("%d", &key);

    key = key % 26;

    /* Copy original message */
    strcpy(encrypted, message);

    /* Encryption */
    encrypt(encrypted, key);

    printf("\n----- SECURE MESSAGE TRANSMISSION -----\n");

    printf("Original Message : %s\n", message);
    printf("Key               : %d\n", key);
    printf("Encrypted Message : %s\n", encrypted);

    /* Decryption */
    decrypt(encrypted, key);

    printf("Decrypted Message : %s\n", encrypted);

    return 0;
}
