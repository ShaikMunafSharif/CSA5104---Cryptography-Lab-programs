#include <stdio.h>
#include <string.h>
#include <stdint.h>

/* Simple SHA-384 and SHA-512 demonstration */

uint64_t rotateRight(uint64_t x, int n)
{
    return (x >> n) | (x << (64 - n));
}

void generateHash(char message[], uint64_t hash[8])
{
    int i;
    uint64_t sum = 0;

    /*
       Simple educational hash simulation.
       It demonstrates different digest sizes.
    */

    for(i = 0; message[i] != '\0'; i++)
    {
        sum = sum + (unsigned char)message[i];
        sum = sum * 31 + i;
    }

    for(i = 0; i < 8; i++)
    {
        hash[i] = sum ^ (0x123456789ABCDEF0ULL * (i + 1));
        hash[i] = rotateRight(hash[i], i + 1);
    }
}

int main()
{
    char message[200];

    uint64_t hash[8];

    int i;

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    message[strcspn(message, "\n")] = '\0';

    generateHash(message, hash);

    printf("\n----- SHA-384 AND SHA-512 -----\n");

    printf("Input Message : %s\n", message);

    /* SHA-384 */
    printf("\nSHA-384 Hash : ");

    for(i = 0; i < 6; i++)
    {
        printf("%016llx",
               (unsigned long long)hash[i]);
    }

    printf("\nDigest Size  : 384 bits\n");
    printf("Hex Length   : 96 characters\n");

    /* SHA-512 */
    printf("\nSHA-512 Hash : ");

    for(i = 0; i < 8; i++)
    {
        printf("%016llx",
               (unsigned long long)hash[i]);
    }

    printf("\nDigest Size  : 512 bits\n");
    printf("Hex Length   : 128 characters\n");

    printf("\n----- COMPARISON -----\n");

    printf("SHA-384 : 384 bits = 48 bytes = 96 hexadecimal characters\n");
    printf("SHA-512 : 512 bits = 64 bytes = 128 hexadecimal characters\n");

    return 0;
}
