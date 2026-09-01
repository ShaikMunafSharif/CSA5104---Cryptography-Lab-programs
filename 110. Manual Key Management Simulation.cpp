#include <stdio.h>
#include <string.h>

struct SecurityAssociation
{
    int sa_id;
    char source[50];
    char destination[50];
    char encryptionKey[50];
};

int main()
{
    struct SecurityAssociation sa;
    char inputSource[50];
    char inputDestination[50];

    printf("============================================\n");
    printf("       MANUAL KEY MANAGEMENT SIMULATION\n");
    printf("============================================\n");

    printf("\nEnter SA ID: ");
    scanf("%d", &sa.sa_id);

    printf("Enter Source IP: ");
    scanf("%s", sa.source);

    printf("Enter Destination IP: ");
    scanf("%s", sa.destination);

    printf("Enter Encryption Key: ");
    scanf("%s", sa.encryptionKey);

    printf("\n--------------------------------------------\n");
    printf("       SECURITY ASSOCIATION CREATED\n");
    printf("--------------------------------------------\n");

    printf("SA ID           : %d\n", sa.sa_id);
    printf("Source IP       : %s\n", sa.source);
    printf("Destination IP  : %s\n", sa.destination);
    printf("Encryption Key  : %s\n", sa.encryptionKey);

    printf("\n--------------------------------------------\n");
    printf("       KEY LOOKUP\n");
    printf("--------------------------------------------\n");

    printf("Enter Source IP: ");
    scanf("%s", inputSource);

    printf("Enter Destination IP: ");
    scanf("%s", inputDestination);

    if(strcmp(inputSource, sa.source) == 0 &&
       strcmp(inputDestination, sa.destination) == 0)
    {
        printf("\nSecurity Association Found!\n");
        printf("SA ID          : %d\n", sa.sa_id);
        printf("Encryption Key : %s\n", sa.encryptionKey);
        printf("Status         : KEY AVAILABLE\n");
    }
    else
    {
        printf("\nSecurity Association Not Found.\n");
        printf("Status         : KEY NOT AVAILABLE\n");
    }

    printf("\n============================================\n");

    return 0;
}
