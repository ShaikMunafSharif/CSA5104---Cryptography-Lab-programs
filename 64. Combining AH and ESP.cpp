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

void encrypt(char data[], char key[], char result[])
{
    int i;

    for(i = 0; data[i] != '\0'; i++)
        result[i] = data[i] ^ key[i % strlen(key)];

    result[i] = '\0';
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

    printf("Enter Security Key: ");
    scanf("%s", key);

    /* ESP Encryption */
    encrypt(packet, key, encrypted);

    /* AH Integrity Check */
    icv = calculateICV(packet);

    printf("\n----- AH + ESP Processing -----\n");

    printf("Original Packet : %s\n", packet);

    printf("\nESP Processing:\n");
    printf("ESP Header      : Added\n");

    printf("Encrypted Data  : ");

    for(i = 0; encrypted[i] != '\0'; i++)
    {
        printf("%02X ", (unsigned char)encrypted[i]);
    }

    printf("\n");

    printf("\nAH Processing:\n");
    printf("AH Header       : Added\n");
    printf("ICV             : %d\n", icv);

    printf("\n----- Security Services -----\n");
    printf("Confidentiality : Provided by ESP\n");
    printf("Integrity       : Provided by AH\n");
    printf("Authentication  : Provided by AH\n");

    printf("\nSecure Packet Sent Successfully.\n");

    return 0;
}
