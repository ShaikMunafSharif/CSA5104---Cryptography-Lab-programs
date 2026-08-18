#include <stdio.h>
#include <string.h>

int main()
{
    char email[500];
    int spamScore = 0;

    printf("Enter Email Message:\n");
    scanf(" %[^\n]", email);

    printf("\n----- Spam Detection -----\n");

    if(strstr(email, "win") != NULL)
        spamScore++;

    if(strstr(email, "prize") != NULL)
        spamScore++;

    if(strstr(email, "free") != NULL)
        spamScore++;

    if(strstr(email, "offer") != NULL)
        spamScore++;

    if(strstr(email, "urgent") != NULL)
        spamScore++;

    if(strstr(email, "money") != NULL)
        spamScore++;

    if(strstr(email, "lottery") != NULL)
        spamScore++;

    printf("Spam Score: %d\n", spamScore);

    if(spamScore >= 2)
    {
        printf("Result: SPAM EMAIL\n");
    }
    else
    {
        printf("Result: NOT SPAM\n");
    }

    return 0;
}
