#include <stdio.h>
#include <string.h>

int main()
{
    char client[50];
    char server[50];
    char key[50];

    printf("============================================\n");
    printf("        SIMPLIFIED IKE PROTOCOL\n");
    printf("============================================\n");

    printf("\nEnter Client Name: ");
    scanf("%s", client);

    printf("Enter Server Name: ");
    scanf("%s", server);

    printf("Enter Shared Secret Key: ");
    scanf("%s", key);

    printf("\n--------------------------------------------\n");
    printf("          IKE SESSION ESTABLISHMENT\n");
    printf("--------------------------------------------\n");

    printf("\n1. IKE INITIATION\n");
    printf("%s sends request to %s.\n", client, server);

    printf("\n2. SECURITY PARAMETERS\n");
    printf("%s and %s exchange security parameters.\n",
           client, server);

    printf("\n3. KEY EXCHANGE\n");
    printf("Client and Server exchange key information.\n");

    printf("\n4. AUTHENTICATION\n");

    if(strlen(key) >= 6)
    {
        printf("Authentication Successful.\n");
    }
    else
    {
        printf("Authentication Failed.\n");
        return 0;
    }

    printf("\n5. SESSION KEY\n");
    printf("Secure session key established.\n");
    printf("Session Key: %s\n", key);

    printf("\n6. IKE COMPLETE\n");
    printf("IPSec Security Association is ready.\n");

    printf("\n--------------------------------------------\n");
    printf("        SECURE SESSION ESTABLISHED\n");
    printf("--------------------------------------------\n");

    printf("Client : %s\n", client);
    printf("Server : %s\n", server);
    printf("Status : SECURE\n");

    printf("\n============================================\n");

    return 0;
}
