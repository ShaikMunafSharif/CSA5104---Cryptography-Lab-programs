#include <stdio.h>
#include <string.h>

struct SA
{
    char source[20];
    char destination[20];
    char protocol[10];
    int spi;
};

int main()
{
    struct SA sa[3];
    char src[20], dest[20];
    int i, found = 0;

    strcpy(sa[0].source, "192.168.1.1");
    strcpy(sa[0].destination, "192.168.1.2");
    strcpy(sa[0].protocol, "ESP");
    sa[0].spi = 1001;

    strcpy(sa[1].source, "10.0.0.1");
    strcpy(sa[1].destination, "10.0.0.2");
    strcpy(sa[1].protocol, "AH");
    sa[1].spi = 2001;

    strcpy(sa[2].source, "172.16.0.1");
    strcpy(sa[2].destination, "172.16.0.2");
    strcpy(sa[2].protocol, "ESP");
    sa[2].spi = 3001;

    printf("Enter Source IP: ");
    scanf("%s", src);

    printf("Enter Destination IP: ");
    scanf("%s", dest);

    for(i = 0; i < 3; i++)
    {
        if(strcmp(src, sa[i].source) == 0 &&
           strcmp(dest, sa[i].destination) == 0)
        {
            printf("\nSecurity Association Found\n");
            printf("Protocol : %s\n", sa[i].protocol);
            printf("SPI      : %d\n", sa[i].spi);

            found = 1;
            break;
        }
    }

    if(!found)
        printf("\nNo Security Association Found\n");

    return 0;
}
