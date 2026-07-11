#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char plaintext[500], ciphertext[500];
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";   // Substitution Key
    int freq[26] = {0};
    int i, j;

    printf("Enter a paragraph:\n");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Encryption
    for (i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];

        if (isupper(ch))
            ciphertext[i] = key[ch - 'A'];
        else if (islower(ch))
            ciphertext[i] = tolower(key[ch - 'a']);
        else
            ciphertext[i] = ch;
    }
    ciphertext[i] = '\0';

    printf("\nCiphertext:\n%s\n", ciphertext);

    // Frequency Count
    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char ch = toupper(ciphertext[i]);
            freq[ch - 'A']++;
        }
    }

    printf("\nLetter Frequencies:\n");
    for (i = 0; i < 26; i++) {
        if (freq[i] > 0)
            printf("%c = %d\n", 'A' + i, freq[i]);
    }

    // Top 3 Frequent Letters
    printf("\nTop 3 Most Frequent Letters:\n");

    for (i = 0; i < 3; i++) {
        int max = -1, index = -1;

        for (j = 0; j < 26; j++) {
            if (freq[j] > max) {
                max = freq[j];
                index = j;
            }
        }

        printf("%c = %d times\n", 'A' + index, max);
        freq[index] = -1;   // Mark as used
    }

    return 0;
}
