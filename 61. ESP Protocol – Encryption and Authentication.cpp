#include <stdio.h>
#include <string.h>

int calculateICV(char data[])
{
    int sum = 0;
    int i;

    for(i = 0; data[i] != '\0'; i++)
        sum += data[i];

    return sum;
}

int main()
{
    char packet[100];
    char key[20];
    char encrypted[100];
    int icv;
    int i;

    printf("Enter IP Packet Data: ");
    scanf("%s", packet);

    printf("Enter Encryption Key: ");
    scanf("%s", key);

    /* Simple encryption using XOR */
    for(i = 0; packet[i] != '\0'; i++)
    {
        encrypted[i] = packet[i] ^ key[i % strlen(key)];
    }

    encrypted[i] = '\0';

    /* Calculate ICV */
    icv = calculateICV(packet);

    printf("\n----- ESP Processing -----\n");

    printf("Original Packet : %s\n", packet);

    printf("ESP Header      : Added\n");

    printf("Encrypted Data  : ");

    for(i = 0; encrypted[i] != '\0'; i++)
    {
        printf("%02X ", (unsigned char)encrypted[i]);
    }

    printf("\n");

    printf("ICV             : %d\n", icv);
    printf("Authentication  : Provided\n");
    printf("Confidentiality : Provided\n");

    return 0;
}
