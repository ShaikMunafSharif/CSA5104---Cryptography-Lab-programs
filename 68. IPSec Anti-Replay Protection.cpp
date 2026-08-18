#include <stdio.h>

int main()
{
    int n, i;
    int sequence;
    int lastSequence = 0;

    printf("Enter Number of Packets: ");
    scanf("%d", &n);

    printf("\nEnter Packet Sequence Numbers:\n");

    for(i = 1; i <= n; i++)
    {
        printf("Packet %d: ", i);
        scanf("%d", &sequence);

        if(sequence > lastSequence)
        {
            printf("Packet Accepted\n");
            lastSequence = sequence;
        }
        else
        {
            printf("Packet Rejected - Replay Detected\n");
        }
    }

    printf("\nFinal Highest Sequence Number: %d\n",
           lastSequence);

    return 0;
}
