#include <stdio.h>
#include <string.h>

int main()
{
    char subject[100];
    char issuer[100];
    char publicKey[100];
    int validity;

    printf("============================================\n");
    printf("       X.509 CERTIFICATE VERIFICATION\n");
    printf("============================================\n");

    printf("\nEnter Certificate Subject: ");
    fgets(subject, sizeof(subject), stdin);
    subject[strcspn(subject, "\n")] = '\0';

    printf("Enter Certificate Issuer: ");
    fgets(issuer, sizeof(issuer), stdin);
    issuer[strcspn(issuer, "\n")] = '\0';

    printf("Enter Public Key: ");
    fgets(publicKey, sizeof(publicKey), stdin);
    publicKey[strcspn(publicKey, "\n")] = '\0';

    printf("Enter validity status (1 = Valid, 0 = Expired): ");
    scanf("%d", &validity);

    printf("\n--------------------------------------------\n");
    printf("       CERTIFICATE DETAILS\n");
    printf("--------------------------------------------\n");

    printf("Subject    : %s\n", subject);
    printf("Issuer     : %s\n", issuer);
    printf("Public Key : %s\n", publicKey);

    if(validity == 1)
        printf("Validity   : Valid\n");
    else
        printf("Validity   : Expired\n");

    printf("\n--------------------------------------------\n");
    printf("       VERIFICATION RESULTS\n");
    printf("--------------------------------------------\n");

    /* Check issuer */
    if(strlen(issuer) > 0)
        printf("Issuer Check       : PASS\n");
    else
        printf("Issuer Check       : FAIL\n");

    /* Check public key */
    if(strlen(publicKey) > 0)
        printf("Public Key Check   : PASS\n");
    else
        printf("Public Key Check   : FAIL\n");

    /* Check validity */
    if(validity == 1)
        printf("Validity Check     : PASS\n");
    else
        printf("Validity Check     : FAIL\n");

    if(strlen(issuer) > 0 &&
       strlen(publicKey) > 0 &&
       validity == 1)
    {
        printf("\nCertificate Verification: SUCCESSFUL\n");
        printf("Certificate is VALID.\n");
    }
    else
    {
        printf("\nCertificate Verification: FAILED\n");
        printf("Certificate is NOT VALID.\n");
    }

    printf("\n============================================\n");

    return 0;
}
