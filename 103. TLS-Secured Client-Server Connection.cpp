#include <stdio.h>
#include <string.h>

int main()
{
    char clientName[50];
    char serverName[50];

    printf("========================================\n");
    printf("       TLS SECURED CONNECTION\n");
    printf("========================================\n");

    printf("\nEnter Client Name: ");
    scanf("%s", clientName);

    printf("Enter Server Name: ");
    scanf("%s", serverName);

    printf("\n----- TLS HANDSHAKE -----\n");

    printf("\n1. ClientHello\n");
    printf("Client sends supported TLS versions and algorithms.\n");

    printf("\n2. ServerHello\n");
    printf("Server selects TLS version and encryption algorithm.\n");

    printf("\n3. Certificate\n");
    printf("Server sends its digital certificate.\n");

    printf("\n4. Certificate Verification\n");
    printf("Client verifies the server certificate.\n");

    printf("\n5. Key Exchange\n");
    printf("Client and server establish a shared session key.\n");

    printf("\n6. Finished\n");
    printf("Both sides confirm the handshake.\n");

    printf("\n----- CERTIFICATE CHECK -----\n");

    printf("Certificate Issuer : Demo Certificate Authority\n");
    printf("Certificate Owner  : %s\n", serverName);
    printf("Validity            : Valid\n");
    printf("Public Key          : Available\n");

    printf("\nCertificate Verification: SUCCESSFUL\n");

    printf("\n----- SECURE CONNECTION -----\n");

    printf("Client : %s\n", clientName);
    printf("Server : %s\n", serverName);

    printf("Session Key: Established\n");
    printf("Connection : TLS Secured\n");

    printf("\nClient can now securely communicate with Server.\n");

    printf("\n========================================\n");

    return 0;
}
