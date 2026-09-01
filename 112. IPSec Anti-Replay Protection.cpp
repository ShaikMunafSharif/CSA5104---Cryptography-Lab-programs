#include <stdio.h>

int main()
{
    int lastSequence = 0;
    int sequence;
    int i;

    printf("============================================\n");
    printf("       IPSec ANTI-REPLAY PROTECTION\n");
    printf("============================================\n");

    printf("\nLast accepted sequence number: %d\n", lastSequence);

    printf("\nEnter number of packets: ");
    scanf("%d", &i);

    printf("\n--------------------------------------------\n");
    printf("          PACKET VERIFICATION\n");
    printf("--------------------------------------------\n");

    while(i > 0)
    {
        printf("\nEnter packet sequence number: ");
        scanf("%d", &sequence);

        if(sequence > lastSequence)
        {
            printf("Packet Accepted.\n");
            printf("Sequence Number: %d\n", sequence);

            lastSequence = sequence;
        }
        else
        {
            printf("Packet Rejected.\n");
            printf("Reason: Replay Attack Detected.\n");
        }

        i--;
    }

    printf("\n--------------------------------------------\n");
    printf("Final Last Accepted Sequence: %d\n", lastSequence);
    printf("--------------------------------------------\n");

    return 0;
}
