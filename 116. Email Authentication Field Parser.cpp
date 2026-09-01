#include <stdio.h>
#include <string.h>

int main()
{
    char header[1500];
    char *line;

    printf("============================================\n");
    printf("       EMAIL AUTHENTICATION FIELD PARSER\n");
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
    printf("        AUTHENTICATION INFORMATION\n");
    printf("============================================\n");

    line = strtok(header, "\n");

    while(line != NULL)
    {
        if(strstr(line, "spf=") != NULL)
        {
            printf("\nSPF Result  : ");
            
            if(strstr(line, "spf=pass") != NULL)
                printf("PASS\n");
            else if(strstr(line, "spf=fail") != NULL)
                printf("FAIL\n");
            else
                printf("UNKNOWN\n");
        }

        if(strstr(line, "dkim=") != NULL)
        {
            printf("DKIM Result : ");

            if(strstr(line, "dkim=pass") != NULL)
                printf("PASS\n");
            else if(strstr(line, "dkim=fail") != NULL)
                printf("FAIL\n");
            else
                printf("UNKNOWN\n");
        }

        if(strstr(line, "dmarc=") != NULL)
        {
            printf("DMARC Result: ");

            if(strstr(line, "dmarc=pass") != NULL)
                printf("PASS\n");
            else if(strstr(line, "dmarc=fail") != NULL)
                printf("FAIL\n");
            else
                printf("UNKNOWN\n");
        }

        line = strtok(NULL, "\n");
    }

    printf("\n============================================\n");
    printf("       AUTHENTICATION PARSING COMPLETED\n");
    printf("============================================\n");

    return 0;
}
