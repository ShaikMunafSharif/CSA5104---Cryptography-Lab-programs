#include <stdio.h>
#include <string.h>

int calculateSignature(char message[])
{
    int sum = 0;
    int i;

    for(i = 0; message[i] != '\0'; i++)
    {
        sum += message[i];
    }

    return sum;
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
    char email[200];
    char key[50];
    char encrypted[200];
    char decrypted[200];

    int signature;
    int receivedSignature;
    int i;

    printf("Enter Email Message: ");
    scanf(" %[^\n]", email);

    printf("Enter Encryption Key: ");
    scanf("%s", key);

    /* Generate Digital Signature */
    signature = calculateSignature(email);

    /* Encrypt Email */
    encrypt(email, key, encrypted);

    printf("\n----- S/MIME Sender -----\n");

    printf("Original Email : %s\n", email);
    printf("Digital Signature : %d\n", signature);

    printf("Encrypted Email : ");

    for(i = 0; encrypted[i] != '\0'; i++)
    {
        printf("%02X ", (unsigned char)encrypted[i]);
    }

    printf("\n");

    /* Receiver decrypts email */
    decrypt(encrypted, key, decrypted);

    receivedSignature = calculateSignature(decrypted);

    printf("\n----- S/MIME Receiver -----\n");

    printf("Decrypted Email : %s\n", decrypted);
    printf("Original Signature : %d\n", signature);
    printf("Calculated Signature : %d\n", receivedSignature);

    if(signature == receivedSignature)
    {
        printf("\nDigital Signature: VALID\n");
        printf("Email Authentication: SUCCESS\n");
        printf("Email Integrity: VERIFIED\n");
    }
    else
    {
        printf("\nDigital Signature: INVALID\n");
        printf("Email may have been modified.\n");
    }

    return 0;
}
