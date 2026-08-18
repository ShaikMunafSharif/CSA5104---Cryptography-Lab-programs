#include <stdio.h>
#include <string.h>

int main()
{
    char sender[100];
    char authenticated[100];

    printf("Enter Sender Email: ");
    scanf("%s", sender);

    printf("Enter Authenticated Email: ");
    scanf("%s", authenticated);

    printf("\n----- Email Spoof Detection -----\n");
    printf("Sender        : %s\n", sender);
    printf("Authenticated : %s\n", authenticated);

    if(strcmp(sender, authenticated) == 0)
    {
        printf("\nResult : Email appears AUTHENTIC.\n");
    }
    else
    {
        printf("\nResult : Possible EMAIL SPOOFING detected.\n");
    }

    return 0;
}
