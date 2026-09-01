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

unsigned long simpleHash(char text[])
{
    unsigned long hash = 5381;
    int i;

    for(i = 0; text[i] != '\0'; i++)
    {
        hash = ((hash << 5) + hash) ^ text[i];
    }

    return hash;
}

int main()
{
    char message[200];
    char received[200];

    int key;

    unsigned long senderHash;
    unsigned long receiverHash;

    printf("========== SECURE CLIENT-SERVER COMMUNICATION ==========\n");

    printf("\nEnter message from Client: ");
    fgets(message, sizeof(message), stdin);

    message[strcspn(message, "\n")] = '\0';

    printf("Enter symmetric key: ");
    scanf("%d", &key);

    /* Client calculates hash */
    senderHash = simpleHash(message);

    /* Encrypt message */
    strcpy(received, message);
    encrypt(received, key);

    printf("\n----- CLIENT SIDE -----\n");
    printf("Original Message : %s\n", message);
    printf("Message Hash     : %lu\n", senderHash);
    printf("Encrypted Message: %s\n", received);

    /* Simulate transmission */
    printf("\nSending encrypted message to Server...\n");

    /* Server decrypts message */
    decrypt(received, key);

    /* Server calculates hash */
    receiverHash = simpleHash(received);

    printf("\n----- SERVER SIDE -----\n");
    printf("Decrypted Message: %s\n", received);
    printf("Received Hash    : %lu\n", receiverHash);

    /* Verify integrity */
    printf("\n----- SECURITY CHECK -----\n");

    if(senderHash == receiverHash)
    {
        printf("Hash values match.\n");
        printf("Message Integrity Verified.\n");
        printf("Secure Communication Successful.\n");
    }
    else
    {
        printf("Hash values do not match.\n");
        printf("Message may have been modified.\n");
    }

    return 0;
}
