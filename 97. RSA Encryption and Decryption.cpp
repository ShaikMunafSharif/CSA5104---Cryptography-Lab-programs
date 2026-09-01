#include <stdio.h>

/* Function to calculate GCD */
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

/* Function for modular exponentiation */
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

int main()
{
    int p, q;
    int n, phi;
    int e, d;
    int message;
    long long encrypted, decrypted;

    printf("Enter first prime number (p): ");
    scanf("%d", &p);

    printf("Enter second prime number (q): ");
    scanf("%d", &q);

    /* Calculate n */
    n = p * q;

    /* Calculate Euler's totient */
    phi = (p - 1) * (q - 1);

    /* Select e */
    for(e = 2; e < phi; e++)
    {
        if(gcd(e, phi) == 1)
            break;
    }

    /* Find d */
    d = 1;

    while((d * e) % phi != 1)
    {
        d++;
    }

    printf("\nEnter message as a number: ");
    scanf("%d", &message);

    /* Encryption */
    encrypted = powerMod(message, e, n);

    /* Decryption */
    decrypted = powerMod(encrypted, d, n);

    printf("\n----- RSA RESULT -----\n");

    printf("p              : %d\n", p);
    printf("q              : %d\n", q);
    printf("n              : %d\n", n);
    printf("Phi(n)         : %d\n", phi);

    printf("\nPublic Key     : (%d, %d)\n", e, n);
    printf("Private Key    : (%d, %d)\n", d, n);

    printf("\nOriginal Message: %d\n", message);
    printf("Encrypted       : %lld\n", encrypted);
    printf("Decrypted       : %lld\n", decrypted);

    return 0;
}
