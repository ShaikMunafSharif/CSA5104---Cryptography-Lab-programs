#include <stdio.h>
#include <string.h>

int main()
{
    char url[200];
    char attachment[50];
    char sender[100];
    int risk = 0;

    printf("Enter Sender Email: ");
    scanf("%s", sender);

    printf("Enter URL in Email: ");
    scanf("%s", url);

    printf("Enter Attachment Name (enter none if no attachment): ");
    scanf("%s", attachment);

    printf("\n----- Phishing Email Analysis -----\n");

    printf("Sender     : %s\n", sender);
    printf("URL        : %s\n", url);
    printf("Attachment : %s\n", attachment);

    /* Check suspicious URL */

    if(strstr(url, "http://") != NULL)
    {
        printf("\nWarning: URL is not using HTTPS.\n");
        risk++;
    }

    if(strstr(url, "login") != NULL)
    {
        printf("Warning: URL contains 'login'.\n");
        risk++;
    }

    if(strstr(url, "verify") != NULL)
    {
        printf("Warning: URL contains 'verify'.\n");
        risk++;
    }

    if(strstr(url, "free") != NULL)
    {
        printf("Warning: Suspicious keyword in URL.\n");
        risk++;
    }

    /* Check attachment */

    if(strstr(attachment, ".exe") != NULL)
    {
        printf("Warning: Executable attachment detected.\n");
        risk++;
    }

    if(strstr(attachment, ".bat") != NULL)
    {
        printf("Warning: Batch file attachment detected.\n");
        risk++;
    }

    /* Check sender */

    if(strstr(sender, "@") == NULL)
    {
        printf("Warning: Invalid sender address.\n");
        risk++;
    }

    printf("\n----- Risk Analysis -----\n");
    printf("Risk Score: %d\n", risk);

    if(risk >= 3)
    {
        printf("Result: HIGH RISK - Possible Phishing Email\n");
    }
    else if(risk == 2)
    {
        printf("Result: MEDIUM RISK - Check Email Carefully\n");
    }
    else
    {
        printf("Result: LOW RISK - No Major Warning Found\n");
    }

    return 0;
}
