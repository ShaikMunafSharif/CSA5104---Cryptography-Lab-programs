#include <stdio.h>
#include <string.h>

int calculateICV(char data[])
{
    int sum = 0;
    int i;

    for(i = 0; data[i] != '\0'; i++)
    {
        sum = sum + data[i];
    }

    return sum;
}

int main()
{
    char packet[100];
    int icv;

    printf("Enter IP Packet Data: ");
    scanf("%s", packet);

    icv = calculateICV(packet);

    printf("\nIP Packet : %s\n", packet);
    printf("ICV       : %d\n", icv);

    return 0;
}
