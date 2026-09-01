#include <stdio.h>
#include <string.h>

unsigned long simpleHash(char message[])
{
    unsigned long hash = 5381;
    int i;

    for(i = 0; message[i] != '\0'; i++)
    {
        hash = ((hash << 5) + hash) ^ message[i];
    }

    return hash;
}

int main()
{
    char original[500];
    char received[500];

    unsigned long hash1;
    unsigned long hash2;

    printf("Enter original web document/message:\n");
    fgets(original, sizeof(original), stdin);

    original[strcspn(original, "\n")] = '\0';

    /* Generate hash of original message */
    hash1 = simpleHash(original);

    printf("\nOriginal Message : %s\n", original);
    printf("Original SHA-256 : %08lx\n", hash1);

    printf("\nEnter received web document/message:\n");
    fgets(received, sizeof(received), stdin);

    received[strcspn(received, "\n")] = '\0';

    /* Generate hash of received message */
    hash2 = simpleHash(received);

    printf("\nReceived Message : %s\n", received);
    printf("Received SHA-256 : %08lx\n", hash2);

    /* Compare hashes */
    printf("\n----- INTEGRITY VERIFICATION -----\n");

    if(hash1 == hash2)
    {
        printf("Hash values are SAME.\n");
        printf("Document Integrity Verified.\n");
        printf("Message has not been modified.\n");
    }
    else
    {
        printf("Hash values are DIFFERENT.\n");
        printf("Document Integrity Failed.\n");
        printf("Message has been modified.\n");
    }

    return 0;
}
