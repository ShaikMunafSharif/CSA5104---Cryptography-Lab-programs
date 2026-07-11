#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char text[], int key) {
    int i;

    for (i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        if (isupper(ch))
            text[i] = ((ch - 'A' + key) % 26) + 'A';
        else if (islower(ch))
            text[i] = ((ch - 'a' + key) % 26) + 'a';
    }
}

void decrypt(char text[], int key) {
    int i;

    for (i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        if (isupper(ch))
            text[i] = ((ch - 'A' - key + 26) % 26) + 'A';
        else if (islower(ch))
            text[i] = ((ch - 'a' - key + 26) % 26) + 'a';
    }
}

void bruteForce(char text[]) {
    char temp[100];
    int key;

    printf("\nBrute Force Attack:\n");

    for (key = 1; key <= 25; key++) {
        strcpy(temp, text);
        decrypt(temp, key);
        printf("Key %2d : %s\n", key, temp);
    }
}

int main() {
    char text[100], encrypted[100], decrypted[100];
    int key;

    printf("Enter Plain Text: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter Key (1-25): ");
    scanf("%d", &key);

    strcpy(encrypted, text);
    encrypt(encrypted, key);
    printf("\nEncrypted Text : %s", encrypted);

    strcpy(decrypted, encrypted);
    decrypt(decrypted, key);
    printf("Decrypted Text : %s", decrypted);

    bruteForce(encrypted);

    return 0;
}
