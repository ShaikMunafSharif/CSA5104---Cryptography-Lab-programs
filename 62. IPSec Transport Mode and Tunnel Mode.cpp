#include <stdio.h>
#include <string.h>

int main()
{
    char packet[100];
    int choice;

    printf("Enter IP Packet Data: ");
    scanf("%s", packet);

    printf("\nSelect IPSec Mode:\n");
    printf("1. Transport Mode\n");
    printf("2. Tunnel Mode\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        printf("\n----- Transport Mode -----\n");
        printf("Original IP Header : Preserved\n");
        printf("Original Data      : %s\n", packet);
        printf("IPSec Header       : Added\n");
        printf("Result             : Original IP packet protected\n");
    }
    else if(choice == 2)
    {
        printf("\n----- Tunnel Mode -----\n");
        printf("Original IP Header : Encapsulated\n");
        printf("Original Data      : %s\n", packet);
        printf("New IP Header      : Added\n");
        printf("IPSec Header       : Added\n");
        printf("Result             : Complete original packet protected\n");
    }
    else
    {
        printf("Invalid Choice\n");
    }

    return 0;
}
