#include <stdio.h>
#include <string.h>

int calculateHash(char message[])
{
    int hash = 0;
    int i;

    for(i = 0; message[i] != '\0'; i++)
    {
        hash = hash + message[i];
    }

    return hash;
}

int main()
{
    char message[100];
    char received[100];
    int signature;
    int receivedHash;

    printf("Enter Message: ");
    scanf(" %[^\n]", message);

    /* Generate Digital Signature */
    signature = calculateHash(message);

    printf("\n----- Signature Generation -----\n");
    printf("Message   : %s\n", message);
    printf("Signature : %d\n", signature);

    /* Receiver receives message */
    printf("\nEnter Received Message: ");
    scanf(" %[^\n]", received);

    /* Verify Signature */
    receivedHash = calculateHash(received);

    printf("\n----- Signature Verification -----\n");
    printf("Received Hash : %d\n", receivedHash);
    printf("Original Signature : %d\n", signature);

    if(receivedHash == signature)
    {
        printf("Digital Signature: VALID\n");
        printf("Message Integrity: Verified\n");
    }
    else
    {
        printf("Digital Signature: INVALID\n");
        printf("Message may have been modified.\n");
    }

    return 0;
}
