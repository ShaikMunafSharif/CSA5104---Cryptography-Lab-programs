#include <stdio.h>
#include <string.h>

int main()
{
    char subject[100];
    char issuer[100];
    char publicKey[100];

    printf("============================================\n");
    printf("       SELF-SIGNED X.509 CERTIFICATE\n");
    printf("============================================\n");

    printf("\nEnter certificate subject: ");
    fgets(subject, sizeof(subject), stdin);

    subject[strcspn(subject, "\n")] = '\0';

    printf("Enter public key: ");
    fgets(publicKey, sizeof(publicKey), stdin);

    publicKey[strcspn(publicKey, "\n")] = '\0';

    /* Self-signed certificate */
    strcpy(issuer, subject);

    printf("\n--------------------------------------------\n");
    printf("       X.509 CERTIFICATE DETAILS\n");
    printf("--------------------------------------------\n");

    printf("Subject       : %s\n", subject);
    printf("Issuer        : %s\n", issuer);
    printf("Public Key    : %s\n", publicKey);
    printf("Certificate   : Self-Signed\n");
    printf("Validity      : Valid\n");
    printf("Signature     : Self-Signed Signature\n");

    printf("\n--------------------------------------------\n");
    printf("       CERTIFICATE VERIFICATION\n");
    printf("--------------------------------------------\n");

    if(strcmp(subject, issuer) == 0)
    {
        printf("Subject and Issuer are the same.\n");
        printf("Self-Signed Certificate: VALID\n");
    }
    else
    {
        printf("Certificate Verification Failed.\n");
    }

    printf("\n--------------------------------------------\n");
    printf("       SECURE COMMUNICATION\n");
    printf("--------------------------------------------\n");

    printf("Certificate installed on server.\n");
    printf("Client can use the certificate for TLS simulation.\n");

    printf("\n============================================\n");
    printf("Certificate Generation Completed.\n");
    printf("============================================\n");

    return 0;
}
