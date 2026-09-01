#include <stdio.h>
#include <string.h>

void encrypt(char message[], int publicKey)
{
    int i;

    for(i = 0; message[i] != '\0'; i++)
    {
        message[i] = message[i] + publicKey;
    }
}

void decrypt(char message[], int privateKey)
{
    int i;

    for(i = 0; message[i] != '\0'; i++)
    {
        message[i] = message[i] - privateKey;
    }
}

int main()
{
    char message[200];
    int publicKey;
    int privateKey;

    printf("============================================\n");
    printf("       PGP EMAIL ENCRYPTION/DECRYPTION\n");
    printf("============================================\n");

    printf("\nEnter Email Message: ");
    fgets(message, sizeof(message), stdin);

    message[strcspn(message, "\n")] = '\0';

    printf("Enter Public Key: ");
    scanf("%d", &publicKey);

    printf("Enter Private Key: ");
    scanf("%d", &privateKey);

    printf("\n--------------------------------------------\n");
    printf("             ENCRYPTION\n");
    printf("--------------------------------------------\n");

    printf("Original Message : %s\n", message);

    encrypt(message, publicKey);

    printf("Encrypted Message: %s\n", message);

    printf("\nEmail encrypted using Public Key.\n");

    printf("\n--------------------------------------------\n");
    printf("             DECRYPTION\n");
    printf("--------------------------------------------\n");

    decrypt(message, privateKey);

    printf("Decrypted Message: %s\n", message);

    printf("\nEmail decrypted using Private Key.\n");

    printf("\n--------------------------------------------\n");

    if(privateKey == publicKey)
    {
        printf("Message Verification: SUCCESSFUL\n");
        printf("Original message recovered.\n");
    }
    else
    {
        printf("Message Verification: FAILED\n");
        printf("Keys do not match in this simulation.\n");
    }

    printf("\n============================================\n");

    return 0;
}
