#include <stdio.h>
#include <string.h>

/* Simple hash function */
unsigned long simpleHash(char text[])
{
    unsigned long hash = 5381;
    int i;

    for(i = 0; text[i] != '\0'; i++)
    {
        hash = ((hash << 5) + hash) ^ text[i];
    }

    return hash;
}

int main()
{
    char orderInfo[200];
    char paymentInfo[200];

    char combined[400];

    unsigned long orderHash;
    unsigned long paymentHash;
    unsigned long dualHash;

    printf("============================================\n");
    printf("       SET DUAL SIGNATURE SIMULATION\n");
    printf("============================================\n");

    printf("\nEnter Order Information: ");
    fgets(orderInfo, sizeof(orderInfo), stdin);
    orderInfo[strcspn(orderInfo, "\n")] = '\0';

    printf("Enter Payment Information: ");
    fgets(paymentInfo, sizeof(paymentInfo), stdin);
    paymentInfo[strcspn(paymentInfo, "\n")] = '\0';

    /* Generate hashes */
    orderHash = simpleHash(orderInfo);
    paymentHash = simpleHash(paymentInfo);

    /* Combine hashes to create dual signature */
    sprintf(combined, "%lu%lu", orderHash, paymentHash);

    dualHash = simpleHash(combined);

    printf("\n--------------------------------------------\n");
    printf("          INFORMATION DETAILS\n");
    printf("--------------------------------------------\n");

    printf("Order Information   : %s\n", orderInfo);
    printf("Payment Information : %s\n", paymentInfo);

    printf("\nOrder Information Hash   : %lu\n", orderHash);
    printf("Payment Information Hash : %lu\n", paymentHash);

    printf("\n--------------------------------------------\n");
    printf("          DUAL SIGNATURE\n");
    printf("--------------------------------------------\n");

    printf("Dual Signature : %lu\n", dualHash);

    printf("\n--------------------------------------------\n");
    printf("          VERIFICATION\n");
    printf("--------------------------------------------\n");

    /* Verify the dual signature */
    sprintf(combined, "%lu%lu",
            simpleHash(orderInfo),
            simpleHash(paymentInfo));

    if(dualHash == simpleHash(combined))
    {
        printf("Order Information : VERIFIED\n");
        printf("Payment Information: VERIFIED\n");
        printf("Dual Signature     : VALID\n");
        printf("\nTransaction is secure.\n");
    }
    else
    {
        printf("Dual Signature     : INVALID\n");
        printf("Transaction verification failed.\n");
    }

    printf("\n============================================\n");

    return 0;
}
