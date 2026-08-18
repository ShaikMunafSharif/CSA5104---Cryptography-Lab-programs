#include <stdio.h>
#include <string.h>
#include <time.h>

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
    char packet[1000];
    char encrypted[1000];
    char key[] = "KEY123";
    int icv;
    int i, repeat = 100000;
    clock_t start, end;
    double ahTime, espTime;

    printf("Enter Packet Data: ");
    scanf("%s", packet);

    /* AH Processing */
    start = clock();

    for(i = 0; i < repeat; i++)
    {
        icv = calculateICV(packet);
    }

    end = clock();

    ahTime = (double)(end - start) / CLOCKS_PER_SEC;

    /* ESP Processing */
    start = clock();

    for(i = 0; i < repeat; i++)
    {
        encrypt(packet, key, encrypted);
        icv = calculateICV(packet);
    }

    end = clock();

    espTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n----- Performance Comparison -----\n");

    printf("\nProtocol\tProcessing Time\tPacket Overhead\n");
    printf("-----------------------------------------------\n");

    printf("AH\t\t%.6f sec\t24 bytes\n", ahTime);
    printf("ESP\t\t%.6f sec\t32 bytes\n", espTime);

    printf("\n----- Security Services -----\n");

    printf("AH  : Integrity + Authentication\n");
    printf("ESP : Encryption + Integrity + Authentication\n");

    return 0;
}
