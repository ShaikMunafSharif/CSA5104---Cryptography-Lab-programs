#include <stdio.h>
#include <string.h>

int main()
{
    char sender[100];
    char receiver[100];
    char route[100];
    char time[100];

    printf("Enter Sender Email: ");
    scanf("%s", sender);

    printf("Enter Receiver Email: ");
    scanf("%s", receiver);

    printf("Enter Routing Path: ");
    scanf("%s", route);

    printf("Enter Timestamp: ");
    scanf("%s", time);

    printf("\n----- Email Header Analysis -----\n");

    printf("Sender        : %s\n", sender);
    printf("Receiver      : %s\n", receiver);
    printf("Routing Path  : %s\n", route);
    printf("Timestamp     : %s\n", time);

    printf("\nEmail Header Analysis Completed.\n");

    return 0;
}
