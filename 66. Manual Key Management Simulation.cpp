#include <stdio.h>
#include <string.h>

struct Key
{
    int spi;
    char source[20];
    char destination[20];
    char key[30];
};

int main()
{
    struct Key k[3];
    char source[20], destination[20];
    int i, found = 0;

    /* Manual Key Configuration */

    k[0].spi = 1001;
    strcpy(k[0].source, "192.168.1.1");
    strcpy(k[0].destination, "192.168.1.2");
    strcpy(k[0].key, "KEY12345");

    k[1].spi = 1002;
    strcpy(k[1].source, "10.0.0.1");
    strcpy(k[1].destination, "10.0.0.2");
    strcpy(k[1].key, "SECURE456");

    k[2].spi = 1003;
    strcpy(k[2].source, "172.16.0.1");
    strcpy(k[2].destination, "172.16.0.2");
    strcpy(k[2].key, "IPSEC789");

    printf("----- Manual Key Database -----\n");

    for(i = 0; i < 3; i++)
    {
        printf("\nSA %d\n", i + 1);
        printf("SPI         : %d\n", k[i].spi);
        printf("Source      : %s\n", k[i].source);
        printf("Destination : %s\n", k[i].destination);
        printf("Key         : %s\n", k[i].key);
    }

    printf("\nEnter Source IP: ");
    scanf("%s", source);

    printf("Enter Destination IP: ");
    scanf("%s", destination);

    /* Key Lookup */

    for(i = 0; i < 3; i++)
    {
        if(strcmp(source, k[i].source) == 0 &&
           strcmp(destination, k[i].destination) == 0)
        {
            printf("\n----- Key Found -----\n");
            printf("SPI : %d\n", k[i].spi);
            printf("Key : %s\n", k[i].key);

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\nNo key found for this communication.\n");
    }

    return 0;
}
