#include <stdio.h>
#include <string.h>

int main()
{
    char from[100];
    char to[100];
    char authentication[100];
    char dkim[50];
    char spf[50];

    printf("Enter From Email: ");
    scanf("%s", from);

    printf("Enter To Email: ");
    scanf("%s", to);

    printf("Enter Authentication Result: ");
    scanf("%s", authentication);

    printf("Enter DKIM Result (pass/fail): ");
    scanf("%s", dkim);

    printf("Enter SPF Result (pass/fail): ");
    scanf("%s", spf);

    printf("\n----- Email Authentication Analysis -----\n");

    printf("From                   : %s\n", from);
    printf("To                     : %s\n", to);
    printf("Authentication Result  : %s\n", authentication);
    printf("DKIM                   : %s\n", dkim);
    printf("SPF                    : %s\n", spf);

    if(strcmp(dkim, "pass") == 0 &&
       strcmp(spf, "pass") == 0)
    {
        printf("\nEmail Authentication: VALID\n");
    }
    else
    {
        printf("\nEmail Authentication: CHECK REQUIRED\n");
    }

    return 0;
}
