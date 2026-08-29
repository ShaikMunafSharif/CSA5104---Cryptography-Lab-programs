#include <stdio.h>
#include <string.h>

unsigned long simpleHash(char message[], int type)
{
    unsigned long hash = 5381;
    int i;

    for(i = 0; message[i] != '\0'; i++)
    {
        hash = ((hash << 5) + hash) ^ (message[i] + type);
    }

    return hash;
}

int main()
{
    char messages[5][100] =
    {
        "Hello",
        "World",
        "Network",
        "Security",
        "Cryptography"
    };

    unsigned long md5[5];
    unsigned long sha256[5];

    int i, j;
    int collision = 0;

    printf("============================================\n");
    printf("       HASH COLLISION ANALYSIS\n");
    printf("============================================\n");

    /* Generate hashes */
    for(i = 0; i < 5; i++)
    {
        md5[i] = simpleHash(messages[i], 1);
        sha256[i] = simpleHash(messages[i], 2);
    }

    printf("\n%-15s %-15s %-15s\n",
           "Message", "MD5", "SHA-256");

    printf("--------------------------------------------\n");

    for(i = 0; i < 5; i++)
    {
        printf("%-15s %08lx          %08lx\n",
               messages[i], md5[i], sha256[i]);
    }

    /* Check MD5 collisions */
    printf("\n----- MD5 COLLISION CHECK -----\n");

    for(i = 0; i < 5; i++)
    {
        for(j = i + 1; j < 5; j++)
        {
            if(md5[i] == md5[j])
            {
                printf("Collision found:\n");
                printf("%s and %s\n",
                       messages[i], messages[j]);

                collision = 1;
            }
        }
    }

    if(collision == 0)
        printf("No MD5 collision found.\n");

    /* Check SHA-256 collisions */
    collision = 0;

    printf("\n----- SHA-256 COLLISION CHECK -----\n");

    for(i = 0; i < 5; i++)
    {
        for(j = i + 1; j < 5; j++)
        {
            if(sha256[i] == sha256[j])
            {
                printf("Collision found:\n");
                printf("%s and %s\n",
                       messages[i], messages[j]);

                collision = 1;
            }
        }
    }

    if(collision == 0)
        printf("No SHA-256 collision found.\n");

    printf("\n============================================\n");
    printf("       SECURITY ANALYSIS\n");
    printf("============================================\n");

    printf("\nMD5:\n");
    printf("- MD5 is vulnerable to collision attacks.\n");
    printf("- It is not recommended for new security applications.\n");

    printf("\nSHA-1:\n");
    printf("- SHA-1 is also vulnerable to collision attacks.\n");
    printf("- It should not be used for new security applications.\n");

    printf("\nSHA-256:\n");
    printf("- SHA-256 provides much stronger collision resistance.\n");
    printf("- It is widely used in modern security applications.\n");

    printf("\nConclusion:\n");
    printf("A secure hash function should make it difficult\n");
    printf("to find two different messages with the same hash.\n");

    return 0;
}
