#include <stdio.h>
#include <string.h>

int main()
{
    char issuer[50];
    char ca[50];
    int validDays;
    int trusted;

    printf("Enter Certificate Issuer: ");
    scanf("%s", issuer);

    printf("Enter Certificate Authority (CA): ");
    scanf("%s", ca);

    printf("Enter Certificate Validity (days remaining): ");
    scanf("%d", &validDays);

    printf("Is CA Trusted? (1 = Yes, 0 = No): ");
    scanf("%d", &trusted);

    printf("\n----- S/MIME Certificate Validation -----\n");

    printf("Certificate Issuer : %s\n", issuer);
    printf("Certificate CA     : %s\n", ca);
    printf("Days Remaining     : %d\n", validDays);

    if(validDays > 0 && trusted == 1)
    {
        printf("\nCertificate Status : VALID\n");
        printf("S/MIME Email       : Trusted\n");
    }
    else if(validDays <= 0)
    {
        printf("\nCertificate Status : EXPIRED\n");
        printf("S/MIME Email       : Not Trusted\n");
    }
    else
    {
        printf("\nCertificate Status : INVALID\n");
        printf("Reason             : CA is not trusted\n");
    }

    return 0;
}
