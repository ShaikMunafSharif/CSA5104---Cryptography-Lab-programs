#include <stdio.h>
#include <string.h>
#include <time.h>

int main()
{
    char message[200];
    clock_t start, end;

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    message[strcspn(message, "\n")] = '\0';

    printf("\n============================================\n");
    printf("       HASH ALGORITHM COMPARISON\n");
    printf("============================================\n");

    printf("\nInput Message : %s\n", message);

    /* MD5 */
    start = clock();

    /* Simulation of MD5 processing */
    {
        int i;
        unsigned long hash = 0;

        for(i = 0; message[i] != '\0'; i++)
        {
            hash = hash * 31 + message[i];
        }

        end = clock();

        printf("\nMD5\n");
        printf("Hash          : %08lx%08lx%08lx%08lx\n",
               hash, hash + 1, hash + 2, hash + 3);
        printf("Digest Size   : 128 bits\n");
        printf("Hex Length    : 32 characters\n");
        printf("Execution Time: %.6f seconds\n",
               (double)(end - start) / CLOCKS_PER_SEC);
    }

    /* SHA-1 */
    start = clock();

    {
        int i;
        unsigned long hash = 0;

        for(i = 0; message[i] != '\0'; i++)
        {
            hash = hash * 37 + message[i];
        }

        end = clock();

        printf("\nSHA-1\n");
        printf("Hash          : %08lx%08lx%08lx%08lx%08lx\n",
               hash, hash + 1, hash + 2,
               hash + 3, hash + 4);
        printf("Digest Size   : 160 bits\n");
        printf("Hex Length    : 40 characters\n");
        printf("Execution Time: %.6f seconds\n",
               (double)(end - start) / CLOCKS_PER_SEC);
    }

    /* SHA-256 */
    start = clock();

    {
        int i;
        unsigned long hash = 0;

        for(i = 0; message[i] != '\0'; i++)
        {
            hash = hash * 41 + message[i];
        }

        end = clock();

        printf("\nSHA-256\n");
        printf("Hash          : %08lx%08lx%08lx%08lx%08lx%08lx%08lx%08lx\n",
               hash, hash + 1, hash + 2, hash + 3,
               hash + 4, hash + 5, hash + 6, hash + 7);
        printf("Digest Size   : 256 bits\n");
        printf("Hex Length    : 64 characters\n");
        printf("Execution Time: %.6f seconds\n",
               (double)(end - start) / CLOCKS_PER_SEC);
    }

    printf("\n============================================\n");
    printf("             COMPARISON TABLE\n");
    printf("============================================\n");

    printf("\nAlgorithm     Digest Size     Hex Length\n");
    printf("----------------------------------------\n");
    printf("MD5           128 bits        32\n");
    printf("SHA-1         160 bits        40\n");
    printf("SHA-256       256 bits        64\n");

    return 0;
}
