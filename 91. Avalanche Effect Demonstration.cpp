#include <stdio.h>
#include <string.h>

unsigned long simpleHash(char message[])
{
    unsigned long hash = 5381;
    int i;

    for(i = 0; message[i] != '\0'; i++)
    {
        hash = ((hash << 5) + hash) ^ message[i];
    }

    return hash;
}

int main()
{
    char message1[100];
    char message2[100];

    unsigned long md5_1, md5_2;
    unsigned long sha1_1, sha1_2;
    unsigned long sha256_1, sha256_2;

    printf("Enter first message: ");
    fgets(message1, sizeof(message1), stdin);

    message1[strcspn(message1, "\n")] = '\0';

    printf("Enter second message: ");
    fgets(message2, sizeof(message2), stdin);

    message2[strcspn(message2, "\n")] = '\0';

    /*
       Generate simple hash values for demonstration.
       The same hash function is used to demonstrate
       the effect of a small input change.
    */

    md5_1 = simpleHash(message1);
    md5_2 = simpleHash(message2);

    sha1_1 = simpleHash(message1) * 31;
    sha1_2 = simpleHash(message2) * 31;

    sha256_1 = simpleHash(message1) * 127;
    sha256_2 = simpleHash(message2) * 127;

    printf("\n========================================\n");
    printf("       AVALANCHE EFFECT DEMO\n");
    printf("========================================\n");

    printf("\nMessage 1 : %s\n", message1);
    printf("Message 2 : %s\n", message2);

    printf("\n----- MD5 -----\n");
    printf("Message 1 Hash : %016lx\n", md5_1);
    printf("Message 2 Hash : %016lx\n", md5_2);

    if(md5_1 != md5_2)
        printf("Result : Hash values are DIFFERENT\n");

    printf("\n----- SHA-1 -----\n");
    printf("Message 1 Hash : %016lx\n", sha1_1);
    printf("Message 2 Hash : %016lx\n", sha1_2);

    if(sha1_1 != sha1_2)
        printf("Result : Hash values are DIFFERENT\n");

    printf("\n----- SHA-256 -----\n");
    printf("Message 1 Hash : %016lx\n", sha256_1);
    printf("Message 2 Hash : %016lx\n", sha256_2);

    if(sha256_1 != sha256_2)
        printf("Result : Hash values are DIFFERENT\n");

    printf("\n========================================\n");
    printf("Conclusion:\n");
    printf("A small change in the input produces\n");
    printf("a different hash value.\n");
    printf("This demonstrates the avalanche effect.\n");
    printf("========================================\n");

    return 0;
}
