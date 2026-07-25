#include <stdio.h>

int main()
{
    int likelihood, impact, risk;

    printf("Enter Likelihood (1-5): ");
    scanf("%d", &likelihood);

    printf("Enter Impact (1-5): ");
    scanf("%d", &impact);

    risk = likelihood * impact;

    printf("Risk Score: %d\n", risk);

    if(risk <= 5)
        printf("Risk Level: Low\n");
    else if(risk <= 15)
        printf("Risk Level: Medium\n");
    else
        printf("Risk Level: High\n");

    return 0;
}
