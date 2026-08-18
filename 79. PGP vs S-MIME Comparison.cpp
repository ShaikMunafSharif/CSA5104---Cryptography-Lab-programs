#include <stdio.h>

int main()
{
    printf("====================================================\n");
    printf("             PGP vs S/MIME COMPARISON\n");
    printf("====================================================\n");

    printf("\nFeature              PGP              S/MIME\n");
    printf("----------------------------------------------------\n");

    printf("Encryption           Yes              Yes\n");
    printf("Authentication       Yes              Yes\n");
    printf("Digital Signature    Yes              Yes\n");
    printf("Certificate          Optional         Required\n");
    printf("Key Management       User managed     CA managed\n");
    printf("Trust Model          Web of Trust     Certificate Authority\n");

    printf("\n====================================================\n");

    printf("\nPGP:\n");
    printf("1. Uses public and private keys.\n");
    printf("2. Users can manage their own keys.\n");
    printf("3. Uses a Web of Trust model.\n");

    printf("\nS/MIME:\n");
    printf("1. Uses public and private keys.\n");
    printf("2. Uses digital certificates.\n");
    printf("3. Certificates are generally issued by a CA.\n");

    printf("\n====================================================\n");
    printf("Comparison Completed Successfully.\n");

    return 0;
}
