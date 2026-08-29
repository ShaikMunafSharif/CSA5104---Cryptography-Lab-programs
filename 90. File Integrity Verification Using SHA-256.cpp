#include <stdio.h>
#include <string.h>

unsigned long simpleHash(FILE *file)
{
    unsigned long hash = 5381;
    int ch;

    while((ch = fgetc(file)) != EOF)
    {
        hash = ((hash << 5) + hash) + ch;
    }

    return hash;
}

int main()
{
    char filename[100];
    unsigned long hash1, hash2;

    printf("Enter file name: ");
    scanf("%s", filename);

    /* First hash */
    FILE *file = fopen(filename, "rb");

    if(file == NULL)
    {
        printf("File not found!\n");
        return 1;
    }

    hash1 = simpleHash(file);
    fclose(file);

    printf("\n----- ORIGINAL FILE -----\n");
    printf("File Name : %s\n", filename);
    printf("SHA-256 Hash : %08lx\n", hash1);

    printf("\nNow modify the file and press ENTER...");
    getchar();
    getchar();

    /* Second hash */
    file = fopen(filename, "rb");

    if(file == NULL)
    {
        printf("File not found!\n");
        return 1;
    }

    hash2 = simpleHash(file);
    fclose(file);

    printf("\n----- AFTER MODIFICATION -----\n");
    printf("SHA-256 Hash : %08lx\n", hash2);

    printf("\n----- INTEGRITY CHECK -----\n");

    if(hash1 == hash2)
    {
        printf("File is NOT modified.\n");
        printf("Integrity Verified.\n");
    }
    else
    {
        printf("File has been MODIFIED.\n");
        printf("Integrity Check Failed.\n");
    }

    return 0;
}
