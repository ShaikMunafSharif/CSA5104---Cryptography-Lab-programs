#include <stdio.h>
#include <string.h>

void encrypt(char email[], char key[], char encrypted[])
{
    int i;

    for(i = 0; email[i] != '\0'; i++)
    {
        encrypted[i] = email[i] ^ key[i % strlen(key)];
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
    char email[200];
    char key[50];
    char encrypted[200];
    char decrypted[200];
    int i;

    printf("Enter Email Message: ");
    scanf(" %[^\n]", email);

    printf("Enter Encryption Key: ");
    scanf("%s", key);

    /* Encryption */
    encrypt(email, key, encrypted);

    printf("\n----- PGP Email Encryption -----\n");
    printf("Original Email : %s\n", email);

    printf("Encrypted Email: ");

    for(i = 0; encrypted[i] != '\0'; i++)
    {
        printf("%02X ", (unsigned char)encrypted[i]);
    }

    printf("\n");

    /* Decryption */
    decrypt(encrypted, key, decrypted);

    printf("\n----- PGP Email Decryption -----\n");
    printf("Decrypted Email: %s\n", decrypted);

    return 0;
}
