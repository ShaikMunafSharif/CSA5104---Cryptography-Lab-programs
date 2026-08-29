#include <stdio.h>
#include <string.h>
#include <openssl/md5.h>

int main()
{
    char message[200];
    unsigned char digest[MD5_DIGEST_LENGTH];
    int i;

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    /* Remove newline */
    message[strcspn(message, "\n")] = '\0';

    /* Generate MD5 hash */
    MD5((unsigned char *)message, strlen(message), digest);

    printf("\n----- MD5 HASH -----\n");
    printf("Input Message : %s\n", message);
    printf("Message Length: %lu bytes\n", strlen(message));

    printf("MD5 Hash      : ");

    for(i = 0; i < MD5_DIGEST_LENGTH; i++)
    {
        printf("%02x", digest[i]);
    }

    printf("\n");
    printf("Digest Size   : 128 bits\n");

    return 0;
}
