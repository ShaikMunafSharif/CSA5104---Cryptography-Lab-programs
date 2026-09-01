#include <stdio.h>
#include <string.h>

int main()
{
    char from[100];
    char replyTo[100];
    char received[100];

    printf("============================================\n");
    printf("          SPOOFED EMAIL DETECTION\n");
    printf("============================================\n");

    printf("\nEnter From address: ");
    scanf("%s", from);

    printf("Enter Reply-To address: ");
    scanf("%s", replyTo);

    printf("Enter Received domain: ");
    scanf("%s", received);

    printf("\n--------------------------------------------\n");
    printf("          EMAIL HEADER ANALYSIS\n");
    printf("--------------------------------------------\n");

    printf("From Address     : %s\n", from);
    printf("Reply-To Address  : %s\n", replyTo);
    printf("Received Domain   : %s\n", received);

    printf("\n--------------------------------------------\n");
    printf("          SPOOFING CHECK\n");
    printf("--------------------------------------------\n");

    /*
       Simple check:
       Compare the domain part of From and Reply-To.
    */

    char *fromDomain = strchr(from, '@');
    char *replyDomain = strchr(replyTo, '@');

    if(fromDomain != NULL && replyDomain != NULL)
    {
        if(strcmp(fromDomain, replyDomain) == 0)
        {
            printf("From and Reply-To domains match.\n");
            printf("Email appears NORMAL.\n");
        }
        else
        {
            printf("From and Reply-To domains do NOT match.\n");
            printf("WARNING: Possible Spoofed Email.\n");
        }
    }
    else
    {
        printf("Invalid email address format.\n");
    }

    printf("\n============================================\n");

    return 0;
}
