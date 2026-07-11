#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char text[], char key[], char cipher[]) {
    int i, j = 0;
    int keyLen = strlen(key);

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char ch = toupper(text[i]);
            char k = toupper(key[j % keyLen]);

            cipher[i] = ((ch - 'A' + k - 'A') % 26) + 'A';
            j++;
        } else {
            cipher[i] = text[i];
        }
    }
    cipher[i] = '\0';
}

void decrypt(char cipher[], char key[], char text[]) {
    int i, j = 0;
    int keyLen = strlen(key);

    for (i = 0; cipher[i] != '\0'; i++) {
        if (isalpha(cipher[i])) {
            char ch = toupper(cipher[i]);
            char k = toupper(key[j % keyLen]);

            text[i] = ((ch - 'A' - (k - 'A') + 26) % 26) + 'A';
            j++;
        } else {
            text[i] = cipher[i];
        }
    }
    text[i] = '\0';
}

void kasiski(char cipher[]) {
    int len = strlen(cipher);

    printf("\nRepeated Sequences:\n");

    for (int i = 0; i < len - 2; i++) {
        char seq[4];
        seq[0] = cipher[i];
        seq[1] = cipher[i + 1];
        seq[2] = cipher[i + 2];
        seq[3] = '\0';

        for (int j = i + 3; j < len - 2; j++) {
            if (cipher[j] == seq[0] &&
                cipher[j + 1] == seq[1] &&
                cipher[j + 2] == seq[2]) {

                printf("%s found at %d and %d\n", seq, i, j);
                printf("Estimated Key Length = %d\n", j - i);
                return;
            }
        }
    }

    printf("No repeated sequence found.\n");
}

int main() {
    char plaintext[200], keyword[50];
    char ciphertext[200], decrypted[200];

    printf("Enter Plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("Enter Keyword: ");
    scanf("%s", keyword);

    encrypt(plaintext, keyword, ciphertext);
    printf("\nEncrypted Text : %s\n", ciphertext);

    decrypt(ciphertext, keyword, decrypted);
    printf("Decrypted Text : %s\n", decrypted);

    kasiski(ciphertext);

    return 0;
}
