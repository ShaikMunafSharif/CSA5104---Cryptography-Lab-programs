#include <stdio.h>
#include <time.h>
#include <string.h>

int main()
{
    char data[1000];
    int i;
    int packetSize;

    clock_t start, end;
    double ahTime, espTime;

    printf("============================================\n");
    printf("       AH vs ESP PERFORMANCE COMPARISON\n");
    printf("============================================\n");

    printf("\nEnter packet data: ");
    fgets(data, sizeof(data), stdin);

    data[strcspn(data, "\n")] = '\0';

    packetSize = strlen(data);

    /* ---------------- AH ---------------- */

    start = clock();

    for(i = 0; i < 1000000; i++)
    {
        /* Simulate AH processing */
        unsigned long hash = 0;
        int j;

        for(j = 0; data[j] != '\0'; j++)
        {
            hash = hash + data[j];
        }
    }

    end = clock();

    ahTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    /* ---------------- ESP ---------------- */

    start = clock();

    for(i = 0; i < 1000000; i++)
    {
        /* Simulate ESP encryption */
        int j;
        char encrypted[1000];

        for(j = 0; data[j] != '\0'; j++)
        {
            encrypted[j] = data[j] ^ 5;
        }

        encrypted[j] = '\0';
    }

    end = clock();

    espTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\n--------------------------------------------\n");
    printf("             PACKET INFORMATION\n");
    printf("--------------------------------------------\n");

    printf("Original Packet Size : %d bytes\n", packetSize);

    printf("\n--------------------------------------------\n");
    printf("             PERFORMANCE TABLE\n");
    printf("--------------------------------------------\n");

    printf("\n%-10s %-20s %-20s\n",
           "Protocol", "Processing Time", "Packet Overhead");

    printf("--------------------------------------------\n");

    printf("%-10s %-20.6f %-20s\n",
           "AH", ahTime, "24 bytes");

    printf("%-10s %-20.6f %-20s\n",
           "ESP", espTime, "32 bytes");

    printf("\n--------------------------------------------\n");
    printf("             COMPARISON\n");
    printf("--------------------------------------------\n");

    if(ahTime < espTime)
        printf("AH processing time is lower.\n");
    else
        printf("ESP processing time is lower.\n");

    printf("AH provides integrity and authentication.\n");
    printf("ESP provides encryption, integrity and authentication.\n");

    printf("\n============================================\n");

    return 0;
}
