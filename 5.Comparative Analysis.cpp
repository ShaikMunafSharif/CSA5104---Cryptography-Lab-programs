#include <stdio.h>
#include <string.h>
#include <time.h>

char monoKey[] = "QWERTYUIOPASDFGHJKLZXCVBNM";

void caesar(char text[], int key)
{
    int i;
    for(i=0;text[i];i++)
    {
        if(text[i]>='A' && text[i]<='Z')
            printf("%c",((text[i]-'A'+key)%26)+'A');
        else
            printf("%c",text[i]);
    }
}

void mono(char text[])
{
    int i;
    for(i=0;text[i];i++)
    {
        if(text[i]>='A'&&text[i]<='Z')
            printf("%c",monoKey[text[i]-'A']);
        else
            printf("%c",text[i]);
    }
}

void vigenere(char text[],char key[])
{
    int i,j=0,len=strlen(key);

    for(i=0;text[i];i++)
    {
        if(text[i]>='A'&&text[i]<='Z')
        {
            printf("%c",((text[i]-'A'+key[j%len]-'A')%26)+'A');
            j++;
        }
        else
            printf("%c",text[i]);
    }
}

void hill(char text[])
{
    int key[2][2]={{3,3},{2,5}};
    int i;

    for(i=0;text[i]&&text[i+1];i+=2)
    {
        int p1=text[i]-'A';
        int p2=text[i+1]-'A';

        printf("%c",(key[0][0]*p1+key[0][1]*p2)%26+'A');
        printf("%c",(key[1][0]*p1+key[1][1]*p2)%26+'A');
    }
}

int main()
{
    char text[100],key[20];
    clock_t start,end;

    printf("Enter Plaintext (Uppercase): ");
    scanf("%s",text);

    printf("Enter Vigenere Key: ");
    scanf("%s",key);

    printf("\n----------------------------------------------\n");
    printf("Cipher\t\tCiphertext\tTime\n");
    printf("----------------------------------------------\n");

    start=clock();
    printf("Caesar\t\t");
    caesar(text,3);
    end=clock();
    printf("\t%.6f",((double)(end-start))/CLOCKS_PER_SEC);

    start=clock();
    printf("\nMono\t\t");
    mono(text);
    end=clock();
    printf("\t%.6f",((double)(end-start))/CLOCKS_PER_SEC);

    start=clock();
    printf("\nVigenere\t");
    vigenere(text,key);
    end=clock();
    printf("\t%.6f",((double)(end-start))/CLOCKS_PER_SEC);

    start=clock();
    printf("\nHill\t\t");
    hill(text);
    end=clock();
    printf("\t%.6f",((double)(end-start))/CLOCKS_PER_SEC);

    printf("\n----------------------------------------------");

    return 0;
}
