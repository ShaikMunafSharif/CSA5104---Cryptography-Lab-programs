#include <stdio.h>
#include <string.h>

/* Simple hash function */
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

/* Generate simple HMAC */
unsigned long generateHMAC(char message[], char key[])
{
    char combined[500];

    strcpy(combined, key);
    strcat(combined, message);
    strcat(combined, key);

    return simpleHash(combined);
}

int main()
{
    char message[300];
    char key[100];

    unsigned long hmac1;
    unsigned long hmac2;

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    message[strcspn(message, "\n")] = '\0';

    printf("Enter secret key: ");
    fgets(key, sizeof(key), stdin);

    key[strcspn(key, "\n")] = '\0';

    /* Generate HMAC */
    hmac1 = generateHMAC(message, key);

    printf("\n----- HMAC GENERATION -----\n");

    printf("Message : %s\n", message);
    printf("Key     : %s\n", key);
    printf("HMAC    : %08lx\n", hmac1);

    /* Simulate verification */
    printf("\n----- HMAC VERIFICATION -----\n");

    hmac2 = generateHMAC(message, key);

    printf("Generated HMAC : %08lx\n", hmac2);

    if(hmac1 == hmac2)
    {
        printf("HMAC Verified Successfully.\n");
        printf("Message is authentic and unchanged.\n");
    }
    else
    {
        printf("HMAC Verification Failed.\n");
        printf("Message may have been modified.\n");
    }

    return 0;
}
