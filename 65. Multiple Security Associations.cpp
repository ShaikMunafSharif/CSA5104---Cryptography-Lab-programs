#include <stdio.h>
#include <string.h>

struct SA
{
    int spi;
    char source[20];
    char destination[20];
    char protocol[10];
};

int main()
{
    struct SA sa[3];
    char source[20], destination[20];
    int i, found = 0;

    /* Security Association 1 */
    sa[0].spi = 1001;
    strcpy(sa[0].source, "192.168.1.1");
    strcpy(sa[0].destination, "192.168.1.2");
    strcpy(sa[0].protocol, "ESP");

    /* Security Association 2 */
    sa[1].spi = 1002;
    strcpy(sa[1].source, "10.0.0.1");
    strcpy(sa[1].destination, "10.0.0.2");
    strcpy(sa[1].protocol, "AH");

    /* Security Association 3 */
    sa[2].spi = 1003;
    strcpy(sa[2].source, "172.16.0.1");
    strcpy(sa[2].destination, "172.16.0.2");
    strcpy(sa[2].protocol, "ESP");

    printf("----- Security Association Database -----\n");

    for(i = 0; i < 3; i++)
    {
        printf("\nSA %d\n", i + 1);
        printf("SPI         : %d\n", sa[i].spi);
        printf("Source      : %s\n", sa[i].source);
        printf("Destination : %s\n", sa[i].destination);
        printf("Protocol    : %s\n", sa[i].protocol);
    }

    printf("\nEnter Source IP: ");
    scanf("%s", source);

    printf("Enter Destination IP: ");
    scanf("%s", destination);

    /* SA Lookup */
    for(i = 0; i < 3; i++)
    {
        if(strcmp(source, sa[i].source) == 0 &&
           strcmp(destination, sa[i].destination) == 0)
        {
            printf("\n----- Matching Security Association -----\n");
            printf("SPI      : %d\n", sa[i].spi);
            printf("Protocol : %s\n", sa[i].protocol);

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\nNo matching Security Association found.\n");
    }

    return 0;
}
