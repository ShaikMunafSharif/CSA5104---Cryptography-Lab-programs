#include <stdio.h>
#include <string.h>

void encrypt(char text[], int key)
{
    int i;

    for(i = 0; text[i] != '\0'; i++)
    {
        text[i] = text[i] + key;
    }
}

void decrypt(char text[], int key)
{
    int i;

    for(i = 0; text[i] != '\0'; i++)
    {
        text[i] = text[i] - key;
    }
}

int main()
{
    char sender[50];
    char receiver[50];
    char message[200];

    int key;

    printf("============================================\n");
    printf("        PGP WORKING PRINCIPLE SIMULATION\n");
    printf("============================================\n");

    printf("\nEnter Sender Name: ");
    scanf("%s", sender);

    printf("Enter Receiver Name: ");
    scanf("%s", receiver);

    getchar();

    printf("Enter Email Message: ");
    fgets(message, sizeof(message), stdin);

    message[strcspn(message, "\n")] = '\0';

    printf("Enter encryption key: ");
    scanf("%d", &key);

    printf("\n--------------------------------------------\n");
    printf("             PGP ENCRYPTION\n");
    printf("--------------------------------------------\n");

    printf("Sender   : %s\n", sender);
    printf("Receiver : %s\n", receiver);
    printf("Original Message : %s\n", message);

    /* Encrypt message */
    encrypt(message, key);

    printf("Encrypted Message: %s\n", message);

    printf("\nMessage sent securely to receiver.\n");

    printf("\n--------------------------------------------\n");
    printf("             PGP DECRYPTION\n");
    printf("--------------------------------------------\n");

    /* Decrypt message */
    decrypt(message, key);

    printf("Receiver : %s\n", receiver);
    printf("Decrypted Message: %s\n", message);

    printf("\n--------------------------------------------\n");
    printf("             PGP RESULT\n");
    printf("--------------------------------------------\n");

    printf("Encryption : SUCCESSFUL\n");
    printf("Decryption : SUCCESSFUL\n");
    printf("Original message recovered successfully.\n");

    printf("\n============================================\n");

    return 0;
}
