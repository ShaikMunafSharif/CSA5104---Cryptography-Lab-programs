#include <stdio.h>
#include <string.h>

int main()
{
    char role[20];

    printf("Enter Role: ");
    scanf("%s", role);

    if(strcmp(role, "Admin") == 0)
    {
        printf("Permissions:\n");
        printf("Read\nWrite\nDelete\n");
    }
    else if(strcmp(role, "Faculty") == 0)
    {
        printf("Permissions:\n");
        printf("Read\nWrite\n");
    }
    else if(strcmp(role, "Student") == 0)
    {
        printf("Permissions:\n");
        printf("Read Only\n");
    }
    else
    {
        printf("Invalid Role\n");
    }

    return 0;
}
