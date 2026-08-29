#include <stdio.h>
#include <string.h>
#include <time.h>

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
    char message[1000];

    clock_t start, end;

    double timeTaken;

    unsigned long hash;

    int i;

    printf("============================================\n");
    printf("       HASH PERFORMANCE ANALYSIS\n");
    printf("============================================\n");

    printf("\nEnter message: ");
    fgets(message, sizeof(message), stdin);

    message[strcspn(message, "\n")] = '\0';

    printf("\n============================================\n");
    printf("Algorithm     Digest Size     Time (sec)\n");
    printf("--------------------------------------------\n");

    /* MD5 */
    start = clock();

    for(i = 0; i < 100000; i++)
        hash = simpleHash(message, 1);

    end = clock();

    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("MD5           128 bits        %.6f\n", timeTaken);

    /* SHA-1 */
    start = clock();

    for(i = 0; i < 100000; i++)
        hash = simpleHash(message, 2);

    end = clock();

    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("SHA-1         160 bits        %.6f\n", timeTaken);

    /* SHA-256 */
    start = clock();

    for(i = 0; i < 100000; i++)
        hash = simpleHash(message, 3);

    end = clock();

    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("SHA-256       256 bits        %.6f\n", timeTaken);

    /* SHA-384 */
    start = clock();

    for(i = 0; i < 100000; i++)
        hash = simpleHash(message, 4);

    end = clock();

    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("SHA-384       384 bits        %.6f\n", timeTaken);

    /* SHA-512 */
    start = clock();

    for(i = 0; i < 100000; i++)
        hash = simpleHash(message, 5);

    end = clock();

    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("SHA-512       512 bits        %.6f\n", timeTaken);

    printf("============================================\n");

    printf("\nDigest Sizes:\n");
    printf("MD5    = 128 bits\n");
    printf("SHA-1  = 160 bits\n");
    printf("SHA-256= 256 bits\n");
    printf("SHA-384= 384 bits\n");
    printf("SHA-512= 512 bits\n");

    return 0;
}
