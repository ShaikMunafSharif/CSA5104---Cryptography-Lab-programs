#include <stdio.h>
#include <string.h>

int calculateHash(char message[])
{
    int hash = 0;
    int i;

    for(i = 0; message[i] != '\0'; i++)
    {
        hash += message[i];
    }

    return hash;
}

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
    char message[200];
    char key[50];
    char encrypted[200];
    char decrypted[200];

    int signature;
    int receivedHash;
    int i;

    printf("Enter Email Message: ");
    scanf(" %[^\n]", message);

    printf("Enter Secret Key: ");
    scanf("%s", key);

    /* Generate Signature */
    signature = calculateHash(message);

    /* Encrypt Message */
    encrypt(message, key, encrypted);

    printf("\n----- Sender Side -----\n");

    printf("Original Message : %s\n", message);
    printf("Digital Signature: %d\n", signature);

    printf("Encrypted Message: ");

    for(i = 0; encrypted[i] != '\0'; i++)
    {
        printf("%02X ", (unsigned char)encrypted[i]);
    }

    printf("\n");

    /* Receiver Side */

    decrypt(encrypted, key, decrypted);

    receivedHash = calculateHash(decrypted);

    printf("\n----- Receiver Side -----\n");

    printf("Decrypted Message : %s\n", decrypted);
    printf("Received Signature: %d\n", signature);
    printf("Calculated Hash   : %d\n", receivedHash);

    if(receivedHash == signature)
    {
        printf("\nSignature Verification: SUCCESS\n");
        printf("Secure Email Received Successfully.\n");
    }
    else
    {
        printf("\nSignature Verification: FAILED\n");
    }

    return 0;
}
