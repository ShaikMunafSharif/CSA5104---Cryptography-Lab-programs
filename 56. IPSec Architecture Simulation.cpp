#include <stdio.h>
#include <string.h>

int main()
{
    char packet[100];
    char protocol[10];
    char mode[20];

    printf("Enter IP Packet Data: ");
    scanf("%s", packet);

    printf("Enter IPSec Protocol (AH/ESP): ");
    scanf("%s", protocol);

    printf("Enter Mode (Transport/Tunnel): ");
    scanf("%s", mode);

    printf("\n----- IPSec Processing -----\n");

    printf("1. Original Packet : %s\n", packet);

    printf("2. Security Policy : Checked\n");

    printf("3. Security Association : Found\n");

    printf("4. Protocol : %s\n", protocol);

    printf("5. Mode : %s\n", mode);

    if(strcmp(protocol, "AH") == 0)
    {
        printf("6. AH Header Added\n");
        printf("7. Integrity and Authentication Provided\n");
    }
    else if(strcmp(protocol, "ESP") == 0)
    {
        printf("6. ESP Header Added\n");
        printf("7. Packet Encryption and Authentication Applied\n");
    }
    else
    {
        printf("Invalid IPSec Protocol\n");
        return 0;
    }

    printf("8. Secure Packet Sent Successfully\n");

    return 0;
}
