#include <stdio.h>
#include <string.h>

int main()
{
    char username[20], password[20];

    printf("Username: ");
    scanf("%s", username);

    printf("Password: ");
    scanf("%s", password);

    if(strcmp(username, "admin") == 0 &&
       strcmp(password, "admin123") == 0)
    {
        printf("Login Successful\n");
    }
    else
    {
        printf("Invalid Username or Password\n");
    }

    return 0;
}
