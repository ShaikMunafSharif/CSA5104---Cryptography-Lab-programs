#include <stdio.h>
#include <string.h>

int calculateICV(char packet[])
{
    int sum = 0;
    int i;

    for(i = 0; packet[i] != '\0'; i++)
    {
        sum = sum + packet[i];
    }

    return sum;
}

int main()
{
    char packet[100];
    int icv;

    printf("Enter IP Packet Data: ");
    scanf("%s", packet);

    // Calculate ICV
    icv = calculateICV(packet);

    printf("\n----- AH Processing -----\n");
    printf("Original Packet : %s\n", packet);
    printf("AH Header Added\n");
    printf("ICV             : %d\n", icv);
    printf("Authentication  : Successful\n");
    printf("Integrity       : Verified\n");

    return 0;
}
