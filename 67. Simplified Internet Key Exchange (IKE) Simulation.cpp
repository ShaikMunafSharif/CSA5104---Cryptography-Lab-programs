#include <stdio.h>
#include <string.h>

int main()
{
    char aliceKey[50];
    char bobKey[50];

    printf("----- Simplified IKE Simulation -----\n");

    printf("\nAlice: Sending Security Proposal...\n");
    printf("Proposal: AES Encryption + SHA Authentication\n");

    printf("Bob: Security Proposal Accepted.\n");

    printf("\nAlice: Enter Key Exchange Value: ");
    scanf("%s", aliceKey);

    printf("Bob: Enter Key Exchange Value: ");
    scanf("%s", bobKey);

    printf("\n----- Key Exchange -----\n");
    printf("Alice Key Value : %s\n", aliceKey);
    printf("Bob Key Value   : %s\n", bobKey);

    if(strcmp(aliceKey, bobKey) == 0)
    {
        printf("\nKey Exchange Successful.\n");
        printf("Shared Secret Established.\n");
        printf("IPSec Secure Session Established.\n");
    }
    else
    {
        printf("\nKey Exchange Failed.\n");
        printf("Secure Session Not Established.\n");
    }

    return 0;
}
