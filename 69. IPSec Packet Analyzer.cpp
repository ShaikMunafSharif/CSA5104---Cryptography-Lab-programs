#include <stdio.h>
#include <string.h>

int main()
{
    char packet[100];
    char protocol[20];

    printf("Enter Packet Data: ");
    scanf("%s", packet);

    printf("Enter IPSec Protocol (AH/ESP/None): ");
    scanf("%s", protocol);

    printf("\n----- Packet Analysis -----\n");
    printf("Packet Data : %s\n", packet);

    if(strcmp(protocol, "AH") == 0 ||
       strcmp(protocol, "ah") == 0)
    {
        printf("IPSec Header : AH\n");
        printf("Status       : AH Header Detected\n");
        printf("Service      : Integrity and Authentication\n");
    }
    else if(strcmp(protocol, "ESP") == 0 ||
            strcmp(protocol, "esp") == 0)
    {
        printf("IPSec Header : ESP\n");
        printf("Status       : ESP Header Detected\n");
        printf("Service      : Encryption and Authentication\n");
    }
    else if(strcmp(protocol, "None") == 0 ||
            strcmp(protocol, "none") == 0)
    {
        printf("IPSec Header : None\n");
        printf("Status       : No IPSec Header Detected\n");
    }
    else
    {
        printf("Unknown Protocol\n");
    }

    return 0;
}
