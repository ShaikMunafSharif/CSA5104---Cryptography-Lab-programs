#include <stdio.h>
#include <string.h>

int main()
{
    char packet[200];

    printf("============================================\n");
    printf("             IPSec PACKET ANALYZER\n");
    printf("============================================\n");

    printf("\nEnter packet header/protocol information: ");
    fgets(packet, sizeof(packet), stdin);

    packet[strcspn(packet, "\n")] = '\0';

    printf("\n--------------------------------------------\n");
    printf("             PACKET ANALYSIS\n");
    printf("--------------------------------------------\n");

    printf("Captured Packet: %s\n", packet);

    if(strstr(packet, "AH") != NULL ||
       strstr(packet, "ah") != NULL)
    {
        printf("\nIPSec AH Header: FOUND\n");
        printf("Protocol: Authentication Header\n");
        printf("Purpose: Integrity and Authentication\n");
    }
    else
    {
        printf("\nIPSec AH Header: NOT FOUND\n");
    }

    if(strstr(packet, "ESP") != NULL ||
       strstr(packet, "esp") != NULL)
    {
        printf("\nIPSec ESP Header: FOUND\n");
        printf("Protocol: Encapsulating Security Payload\n");
        printf("Purpose: Encryption and Authentication\n");
    }
    else
    {
        printf("\nIPSec ESP Header: NOT FOUND\n");
    }

    if(strstr(packet, "AH") == NULL &&
       strstr(packet, "ah") == NULL &&
       strstr(packet, "ESP") == NULL &&
       strstr(packet, "esp") == NULL)
    {
        printf("\nNo IPSec header detected.\n");
    }

    printf("\n============================================\n");

    return 0;
}
