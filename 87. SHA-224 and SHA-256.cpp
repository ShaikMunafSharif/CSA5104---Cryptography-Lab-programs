#include <stdio.h>
#include <string.h>
#include <stdint.h>

/* Right rotation */
uint32_t rotr(uint32_t x, int n)
{
    return (x >> n) | (x << (32 - n));
}

/* SHA-256 constants */
uint32_t K[64] =
{
    0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,
    0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,
    0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,
    0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,
    0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,
    0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
    0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,
    0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,
    0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,
    0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,
    0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,
    0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
    0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,
    0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,
    0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,
    0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2
};

void sha256(char message[], uint32_t hash[8])
{
    unsigned char data[128];
    uint32_t w[64];

    uint32_t h[8] =
    {
        0x6a09e667, 0xbb67ae85,
        0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c,
        0x1f83d9ab, 0x5be0cd19
    };

    uint32_t a,b,c,d,e,f,g,hh;
    uint32_t S1,S0,ch,maj,temp1,temp2;

    int len = strlen(message);
    int newLen;
    int i;

    for(i = 0; i < len; i++)
        data[i] = message[i];

    data[len] = 0x80;
    newLen = len + 1;

    while(newLen % 64 != 56)
    {
        data[newLen] = 0;
        newLen++;
    }

    unsigned long long bitLength = (unsigned long long)len * 8;

    for(i = 0; i < 8; i++)
    {
        data[newLen + 7 - i] = bitLength & 0xff;
        bitLength >>= 8;
    }

    for(i = 0; i < 16; i++)
    {
        w[i] =
            ((uint32_t)data[i*4] << 24) |
            ((uint32_t)data[i*4+1] << 16) |
            ((uint32_t)data[i*4+2] << 8) |
            data[i*4+3];
    }

    for(i = 16; i < 64; i++)
    {
        S0 = rotr(w[i-15],7) ^
             rotr(w[i-15],18) ^
             (w[i-15] >> 3);

        S1 = rotr(w[i-2],17) ^
             rotr(w[i-2],19) ^
             (w[i-2] >> 10);

        w[i] = w[i-16] + S0 + w[i-7] + S1;
    }

    a=h[0];
    b=h[1];
    c=h[2];
    d=h[3];
    e=h[4];
    f=h[5];
    g=h[6];
    hh=h[7];

    for(i = 0; i < 64; i++)
    {
        S1 = rotr(e,6) ^ rotr(e,11) ^ rotr(e,25);

        ch = (e & f) ^ ((~e) & g);

        temp1 = hh + S1 + ch + K[i] + w[i];

        S0 = rotr(a,2) ^ rotr(a,13) ^ rotr(a,22);

        maj = (a & b) ^ (a & c) ^ (b & c);

        temp2 = S0 + maj;

        hh = g;
        g = f;
        f = e;
        e = d + temp1;
        d = c;
        c = b;
        b = a;
        a = temp1 + temp2;
    }

    hash[0] = h[0] + a;
    hash[1] = h[1] + b;
    hash[2] = h[2] + c;
    hash[3] = h[3] + d;
    hash[4] = h[4] + e;
    hash[5] = h[5] + f;
    hash[6] = h[6] + g;
    hash[7] = h[7] + hh;
}

int main()
{
    char message[200];

    uint32_t hash[8];

    int i;

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    message[strcspn(message, "\n")] = '\0';

    sha256(message, hash);

    printf("\n----- HASH RESULTS -----\n");

    printf("Input Message : %s\n", message);

    printf("\nSHA-224 Hash  : ");

    /* SHA-224 uses the first 7 words */
    for(i = 0; i < 7; i++)
    {
        printf("%08x", hash[i]);
    }

    printf("\nDigest Size   : 224 bits\n");

    printf("\nSHA-256 Hash  : ");

    for(i = 0; i < 8; i++)
    {
        printf("%08x", hash[i]);
    }

    printf("\nDigest Size   : 256 bits\n");

    return 0;
}
