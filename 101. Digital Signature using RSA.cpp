#include <stdio.h>
#include <string.h>

int gcd(int a, int b)
{
    while(b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long powerMod(long long base, long long exp, long long mod)
{
    long long result = 1;

    while(exp > 0)
    {
        result = (result * base) % mod;
        exp--;
    }

    return result;
}

unsigned long simpleHash(char message[])
{
    unsigned long hash = 5381;
    int i;

    for(i = 0; message[i] != '\0'; i++)
        hash = ((hash << 5) + hash) ^ message[i];

    return hash;
}

int main()
{
    int p, q, n, phi;
    int e, d;
    char message[200];

    unsigned long hash;
    long long signature;
    long long verifiedHash;

    printf("Enter first prime number: ");
    scanf("%d", &p);

    printf("Enter second prime number: ");
    scanf("%d", &q);

    getchar();

    n = p * q;
    phi = (p - 1) * (q - 1);

    /* Find public key e */
    for(e = 2; e < phi; e++)
    {
        if(gcd(e, phi) == 1)
            break;
    }

    /* Find private key d */
    d = 1;

    while((d * e) % phi != 1)
        d++;

    printf("\nEnter message: ");
    fgets(message, sizeof(message), stdin);

    message[strcspn(message, "\n")] = '\0';

    /* Create hash */
    hash = simpleHash(message);

    /* Make hash suitable for RSA */
    hash = hash % n;

    /* Sign using private key */
    signature = powerMod(hash, d, n);

    /* Verify using public key */
    verifiedHash = powerMod(signature, e, n);

    printf("\n========== DIGITAL SIGNATURE ==========\n");

    printf("Message       : %s\n", message);
    printf("Hash          : %lu\n", hash);

    printf("\nPublic Key    : (%d, %d)\n", e, n);
    printf("Private Key   : (%d, %d)\n", d, n);

    printf("\nDigital Signature : %lld\n", signature);
    printf("Verified Hash     : %lld\n", verifiedHash);

    if(hash == verifiedHash)
        printf("\nSignature Verification: SUCCESSFUL\n");
    else
        printf("\nSignature Verification: FAILED\n");

    return 0;
}
