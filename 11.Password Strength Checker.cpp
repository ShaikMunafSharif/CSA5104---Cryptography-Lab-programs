#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[100];
    int upper = 0, lower = 0, digit = 0, i;

    printf("Enter Password: ");
    scanf("%s", password);

    for(i = 0; password[i] != '\0'; i++)
    {
        if(isupper(password[i]))
            upper = 1;
        else if(islower(password[i]))
            lower = 1;
        else if(isdigit(password[i]))
            digit = 1;
    }

    if(strlen(password) >= 8 && upper && lower && digit)
        printf("Password is Strong.\n");
    else
        printf("Password is Weak.\n");

    return 0;
}
