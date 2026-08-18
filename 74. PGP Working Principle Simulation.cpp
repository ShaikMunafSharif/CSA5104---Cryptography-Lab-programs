#include <stdio.h>
#include <string.h>

void encrypt(char message[], char key[], char encrypted[])
{
    int i;

    for(i = 0; message[i] != '\0'; i++)
    {
        encrypted[i] = message[i] ^ key[i % strlen(key)];
    }

    encrypted[i] = '\0';
}

void decrypt(char encrypted[], char key[], char decrypted[])
{
    int i;

    for(i = 0; encrypted[i] != '\0'; i++)
    {
        decrypted[i] = encrypted[i] ^ key[i % strlen(key)];
    }

    decrypted[i] = '\0';
}

int main()
{
    char message[100];
    char key[50];
    char encrypted[100];
    char decrypted[100];
    int i;

    printf("Enter Message: ");
    scanf("%s", message);

    printf("Enter Secret Key: ");
    scanf("%s", key);

    /* Encryption */
    encrypt(message, key, encrypted);

    printf("\n----- PGP Encryption -----\n");
    printf("Original Message : %s\n", message);

    printf("Encrypted Data   : ");

    for(i = 0; encrypted[i] != '\0'; i++)
    {
        printf("%02X ", (unsigned char)encrypted[i]);
    }

    printf("\n");

    /* Decryption */
    decrypt(encrypted, key, decrypted);

    printf("\n----- PGP Decryption -----\n");
    printf("Decrypted Message : %s\n", decrypted);

    return 0;
}
