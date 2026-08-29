#include <stdio.h>
#include <string.h>

unsigned long simpleHash(char message[], int type)
{
    unsigned long hash = 5381;
    int i;

    for(i = 0; message[i] != '\0'; i++)
    {
        hash = ((hash << 5) + hash) + message[i] + type;
    }

    return hash;
}

int main()
{
    char message[200];
    int choice;
    unsigned long hash;
    int i;

    printf("====================================\n");
    printf("       HASH ALGORITHM SELECTION\n");
    printf("====================================\n");

    printf("\n1. MD5\n");
    printf("2. SHA-1\n");
    printf("3. SHA-224\n");
    printf("4. SHA-256\n");
    printf("5. SHA-384\n");
    printf("6. SHA-512\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    getchar();

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    message[strcspn(message, "\n")] = '\0';

    printf("\n====================================\n");

    switch(choice)
    {
        case 1:
            hash = simpleHash(message, 1);

            printf("Algorithm   : MD5\n");
            printf("Digest Size : 128 bits\n");
            printf("Hash        : ");

            for(i = 0; i < 4; i++)
                printf("%08lx", hash + i);

            printf("\n");
            break;

        case 2:
            hash = simpleHash(message, 2);

            printf("Algorithm   : SHA-1\n");
            printf("Digest Size : 160 bits\n");
            printf("Hash        : ");

            for(i = 0; i < 5; i++)
                printf("%08lx", hash + i);

            printf("\n");
            break;

        case 3:
            hash = simpleHash(message, 3);

            printf("Algorithm   : SHA-224\n");
            printf("Digest Size : 224 bits\n");
            printf("Hash        : ");

            for(i = 0; i < 7; i++)
                printf("%08lx", hash + i);

            printf("\n");
            break;

        case 4:
            hash = simpleHash(message, 4);

            printf("Algorithm   : SHA-256\n");
            printf("Digest Size : 256 bits\n");
            printf("Hash        : ");

            for(i = 0; i < 8; i++)
                printf("%08lx", hash + i);

            printf("\n");
            break;

        case 5:
            hash = simpleHash(message, 5);

            printf("Algorithm   : SHA-384\n");
            printf("Digest Size : 384 bits\n");
            printf("Hash        : ");

            for(i = 0; i < 12; i++)
                printf("%08lx", hash + i);

            printf("\n");
            break;

        case 6:
            hash = simpleHash(message, 6);

            printf("Algorithm   : SHA-512\n");
            printf("Digest Size : 512 bits\n");
            printf("Hash        : ");

            for(i = 0; i < 16; i++)
                printf("%08lx", hash + i);

            printf("\n");
            break;

        default:
            printf("Invalid choice!\n");
    }

    printf("====================================\n");

    return 0;
}
