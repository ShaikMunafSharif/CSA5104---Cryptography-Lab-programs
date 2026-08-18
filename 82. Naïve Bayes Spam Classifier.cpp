#include <stdio.h>
#include <string.h>

int main()
{
    char message[200];

    int spam = 0;
    int ham = 0;

    printf("Enter Email Message:\n");
    scanf(" %[^\n]", message);

    /*
       Simple training knowledge:
       Spam words: win, prize, free, offer, money
       Ham words : meeting, project, class, report, tomorrow
    */

    if(strstr(message, "win") != NULL)
        spam++;

    if(strstr(message, "prize") != NULL)
        spam++;

    if(strstr(message, "free") != NULL)
        spam++;

    if(strstr(message, "offer") != NULL)
        spam++;

    if(strstr(message, "money") != NULL)
        spam++;

    if(strstr(message, "meeting") != NULL)
        ham++;

    if(strstr(message, "project") != NULL)
        ham++;

    if(strstr(message, "class") != NULL)
        ham++;

    if(strstr(message, "report") != NULL)
        ham++;

    if(strstr(message, "tomorrow") != NULL)
        ham++;

    printf("\n----- Naive Bayes Spam Classifier -----\n");

    printf("Spam Score : %d\n", spam);
    printf("Ham Score  : %d\n", ham);

    if(spam > ham)
    {
        printf("Prediction : SPAM\n");
    }
    else
    {
        printf("Prediction : NOT SPAM\n");
    }

    return 0;
}
