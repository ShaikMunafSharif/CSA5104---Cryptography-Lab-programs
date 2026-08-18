#include <stdio.h>
#include <string.h>

int calculateICV(char packet[])
{
    int sum = 0;
    int i;

    for(i = 0; packet[i] != '\0'; i++)
        sum += packet[i];

    return sum;
}

int main()
{
    char packet[100];
    int icv;

    printf("Enter IP Packet Data: ");
    scanf("%s", packet);

    printf("\n----- Without AH -----\n");
    printf("Packet Sent : %s\n", packet);
    printf("Integrity   : Not Protected\n");
    printf("Authentication : Not Provided\n");

    icv = calculateICV(packet);

    printf("\n----- With AH -----\n");
    printf("Original Packet : %s\n", packet);
    printf("AH Header       : Added\n");
    printf("ICV             : %d\n", icv);
    printf("Integrity       : Protected\n");
    printf("Authentication  : Provided\n");

    return 0;
}
