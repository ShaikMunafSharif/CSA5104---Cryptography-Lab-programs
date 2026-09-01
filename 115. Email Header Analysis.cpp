#include <stdio.h>
#include <string.h>

int main()
{
    char header[1000];
    char *line;

    printf("============================================\n");
    printf("            EMAIL HEADER ANALYZER\n");
    printf("============================================\n");

    printf("\nEnter email header information.\n");
    printf("Enter END on a separate line to finish.\n\n");

    header[0] = '\0';

    while(1)
    {
        char temp[200];

        fgets(temp, sizeof(temp), stdin);

        if(strcmp(temp, "END\n") == 0 ||
           strcmp(temp, "END") == 0)
            break;

        strcat(header, temp);
    }

    printf("\n============================================\n");
    printf("             ANALYZED EMAIL HEADER\n");
    printf("============================================\n");

    line = strtok(header, "\n");

    while(line != NULL)
    {
        if(strncmp(line, "From:", 5) == 0)
        {
            printf("\nSender      : %s", line + 5);
        }
        else if(strncmp(line, "To:", 3) == 0)
        {
            printf("\nReceiver    : %s", line + 3);
        }
        else if(strncmp(line, "Date:", 5) == 0)
        {
            printf("\nTimestamp   : %s", line + 5);
        }
        else if(strncmp(line, "Received:", 9) == 0)
        {
            printf("\nRouting Path: %s", line + 9);
        }

        line = strtok(NULL, "\n");
    }

    printf("\n\n============================================\n");
    printf("          EMAIL ANALYSIS COMPLETED\n");
    printf("============================================\n");

    return 0;
}
