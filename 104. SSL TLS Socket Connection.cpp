#include <stdio.h>
#include <string.h>

int main()
{
    char clientMessage[200];
    char serverReply[200];

    printf("========================================\n");
    printf("       SSL/TLS SOCKET SIMULATION\n");
    printf("========================================\n");

    /* Client */
    printf("\n----- CLIENT -----\n");

    printf("Enter message to Server: ");
    fgets(clientMessage, sizeof(clientMessage), stdin);

    clientMessage[strcspn(clientMessage, "\n")] = '\0';

    printf("\nClient: Connecting to Server...\n");

    /* Connection */
    printf("Client: TCP connection established.\n");
    printf("Client: Starting SSL/TLS handshake...\n");

    /* TLS Handshake */
    printf("\n----- TLS HANDSHAKE -----\n");

    printf("Client -> Server : ClientHello\n");
    printf("Server -> Client : ServerHello\n");
    printf("Server -> Client : Certificate\n");
    printf("Client            : Certificate Verified\n");
    printf("Client <-> Server : Key Exchange\n");
    printf("Client <-> Server : Finished\n");

    printf("\nTLS Handshake Successful!\n");
    printf("Secure Socket Established.\n");

    /* Send message */
    printf("\n----- SECURE COMMUNICATION -----\n");

    printf("Client sends: %s\n", clientMessage);

    /* Server receives message */
    printf("Server received: %s\n", clientMessage);

    /* Server reply */
    strcpy(serverReply, "Message received securely!");

    printf("\nServer sends: %s\n", serverReply);

    printf("Client received: %s\n", serverReply);

    printf("\n========================================\n");
    printf("Secure SSL/TLS Communication Completed.\n");
    printf("========================================\n");

    return 0;
}
