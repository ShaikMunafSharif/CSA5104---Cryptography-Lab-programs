#include <stdio.h>

int modInverse(int a) {
    a = (a % 26 + 26) % 26;
    for (int i = 1; i < 26; i++) {
        if ((a * i) % 26 == 1)
            return i;
    }
    return -1;
}

int main() {
    int key[2][2], invKey[2][2];
    int det, detInv;
    char plain[5], cipher[5], decrypt[5];
    int p[2], c[2];

    printf("Enter 2x2 Key Matrix:\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &key[i][j]);

    det = (key[0][0] * key[1][1] - key[0][1] * key[1][0]) % 26;
    if (det < 0)
        det += 26;

    detInv = modInverse(det);

    if (detInv == -1) {
        printf("Invalid Key Matrix! Determinant is not relatively prime to 26.\n");
        return 0;
    }

    printf("Enter 4-letter Plaintext (Uppercase): ");
    scanf("%s", plain);

    // Encryption
    for (int i = 0; i < 4; i += 2) {
        p[0] = plain[i] - 'A';
        p[1] = plain[i + 1] - 'A';

        c[0] = (key[0][0] * p[0] + key[0][1] * p[1]) % 26;
        c[1] = (key[1][0] * p[0] + key[1][1] * p[1]) % 26;

        cipher[i] = c[0] + 'A';
        cipher[i + 1] = c[1] + 'A';
    }
    cipher[4] = '\0';

    printf("Encrypted Text: %s\n", cipher);

    // Inverse Matrix
    invKey[0][0] = ( key[1][1] * detInv) % 26;
    invKey[0][1] = ((-key[0][1] + 26) * detInv) % 26;
    invKey[1][0] = ((-key[1][0] + 26) * detInv) % 26;
    invKey[1][1] = ( key[0][0] * detInv) % 26;

    // Decryption
    for (int i = 0; i < 4; i += 2) {
        c[0] = cipher[i] - 'A';
        c[1] = cipher[i + 1] - 'A';

        p[0] = (invKey[0][0] * c[0] + invKey[0][1] * c[1]) % 26;
        p[1] = (invKey[1][0] * c[0] + invKey[1][1] * c[1]) % 26;

        decrypt[i] = p[0] + 'A';
        decrypt[i + 1] = p[1] + 'A';
    }
    decrypt[4] = '\0';

    printf("Decrypted Text: %s\n", decrypt);

    return 0;
}
