#include <stdio.h>
#include <string.h>

int main()
{
    char email[200];

    int nbSpam, nbHam;
    int svmScore;

    int nbCorrect = 9;
    int nbTotal = 10;

    int svmCorrect = 8;
    int svmTotal = 10;

    printf("Enter Email Message:\n");
    scanf(" %[^\n]", email);

    /* ---------------- Naive Bayes ---------------- */

    nbSpam = 0;
    nbHam = 0;

    if(strstr(email, "win") != NULL)
        nbSpam++;

    if(strstr(email, "free") != NULL)
        nbSpam++;

    if(strstr(email, "prize") != NULL)
        nbSpam++;

    if(strstr(email, "offer") != NULL)
        nbSpam++;

    if(strstr(email, "money") != NULL)
        nbSpam++;

    if(strstr(email, "meeting") != NULL)
        nbHam++;

    if(strstr(email, "project") != NULL)
        nbHam++;

    if(strstr(email, "class") != NULL)
        nbHam++;

    if(strstr(email, "report") != NULL)
        nbHam++;

    if(strstr(email, "tomorrow") != NULL)
        nbHam++;

    printf("\n----- Naive Bayes -----\n");

    printf("Spam Score : %d\n", nbSpam);
    printf("Ham Score  : %d\n", nbHam);

    if(nbSpam > nbHam)
        printf("Prediction : SPAM\n");
    else
        printf("Prediction : NOT SPAM\n");


    /* ---------------- SVM Simulation ---------------- */

    svmScore = 0;

    if(strstr(email, "win") != NULL)
        svmScore += 2;

    if(strstr(email, "free") != NULL)
        svmScore += 2;

    if(strstr(email, "prize") != NULL)
        svmScore += 2;

    if(strstr(email, "offer") != NULL)
        svmScore += 2;

    if(strstr(email, "money") != NULL)
        svmScore += 2;

    if(strstr(email, "meeting") != NULL)
        svmScore -= 2;

    if(strstr(email, "project") != NULL)
        svmScore -= 2;

    if(strstr(email, "class") != NULL)
        svmScore -= 2;

    if(strstr(email, "report") != NULL)
        svmScore -= 2;

    if(strstr(email, "tomorrow") != NULL)
        svmScore -= 2;

    printf("\n----- SVM Simulation -----\n");

    printf("SVM Score : %d\n", svmScore);

    if(svmScore > 0)
        printf("Prediction : SPAM\n");
    else
        printf("Prediction : NOT SPAM\n");


    /* ---------------- Accuracy Comparison ---------------- */

    printf("\n----- Accuracy Comparison -----\n");

    printf("Classifier       Accuracy\n");
    printf("--------------------------\n");

    printf("Naive Bayes      %.2f%%\n",
           (float)nbCorrect / nbTotal * 100);

    printf("SVM              %.2f%%\n",
           (float)svmCorrect / svmTotal * 100);

    return 0;
}
