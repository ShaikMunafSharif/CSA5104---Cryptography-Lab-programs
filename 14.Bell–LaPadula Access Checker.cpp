#include <stdio.h>
#include <string.h>

int level(char s[])
{
    if(strcmp(s,"Public")==0) return 1;
    if(strcmp(s,"Confidential")==0) return 2;
    if(strcmp(s,"Secret")==0) return 3;
    if(strcmp(s,"TopSecret")==0) return 4;
    return 0;
}

int main()
{
    char user[20], file[20], op[10];

    printf("User Level (Public/Confidential/Secret/TopSecret): ");
    scanf("%s", user);

    printf("File Level: ");
    scanf("%s", file);

    printf("Operation (Read/Write): ");
    scanf("%s", op);

    int u = level(user);
    int f = level(file);

    if(strcmp(op,"Read")==0)
    {
        if(u >= f)
            printf("Access Allowed\n");
        else
            printf("Access Denied\nReason: No Read Up\n");
    }
    else if(strcmp(op,"Write")==0)
    {
        if(u <= f)
            printf("Access Allowed\n");
        else
            printf("Access Denied\nReason: No Write Down\n");
    }
    else
    {
        printf("Invalid Operation\n");
    }

    return 0;
}
