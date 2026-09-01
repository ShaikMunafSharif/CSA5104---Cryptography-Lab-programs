#include <stdio.h>

int main()
{
    printf("============================================\n");
    printf("        SSL/TLS HANDSHAKE ANALYSIS\n");
    printf("============================================\n");

    printf("\nClient and Server start communication...\n");

    printf("\n--------------------------------------------\n");
    printf("1. CLIENT HELLO\n");
    printf("--------------------------------------------\n");

    printf("Client sends:\n");
    printf("- Supported TLS versions\n");
    printf("- Supported cipher suites\n");
    printf("- Random value\n");

    printf("\n--------------------------------------------\n");
    printf("2. SERVER HELLO\n");
    printf("--------------------------------------------\n");

    printf("Server sends:\n");
    printf("- Selected TLS version\n");
    printf("- Selected cipher suite\n");
    printf("- Random value\n");

    printf("\n--------------------------------------------\n");
    printf("3. CERTIFICATE\n");
    printf("--------------------------------------------\n");

    printf("Server sends its digital certificate.\n");
    printf("Client verifies the certificate.\n");

    printf("\nCertificate Status: VALID\n");

    printf("\n--------------------------------------------\n");
    printf("4. KEY EXCHANGE\n");
    printf("--------------------------------------------\n");

    printf("Client and Server exchange key information.\n");
    printf("A secure session key is established.\n");

    printf("\nSession Key Status: ESTABLISHED\n");

    printf("\n--------------------------------------------\n");
    printf("5. FINISHED\n");
    printf("--------------------------------------------\n");

    printf("Client sends Finished message.\n");
    printf("Server sends Finished message.\n");
    printf("Both sides verify the handshake.\n");

    printf("\n--------------------------------------------\n");
    printf("TLS HANDSHAKE COMPLETED SUCCESSFULLY\n");
    printf("--------------------------------------------\n");

    printf("\nSecure communication can now begin.\n");

    printf("\n============================================\n");

    return 0;
}
