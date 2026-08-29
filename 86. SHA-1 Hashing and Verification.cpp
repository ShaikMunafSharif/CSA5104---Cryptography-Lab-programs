#include <stdio.h>
#include <string.h>
#include <stdint.h>

uint32_t rotateLeft(uint32_t x, int n)
{
    return (x << n) | (x >> (32 - n));
}

void sha1(char message[], char output[])
{
    unsigned char data[128];
    uint32_t h0 = 0x67452301;
    uint32_t h1 = 0xEFCDAB89;
    uint32_t h2 = 0x98BADCFE;
    uint32_t h3 = 0x10325476;
    uint32_t h4 = 0xC3D2E1F0;

    uint32_t w[80];
    uint32_t a, b, c, d, e, f, k, temp;
    unsigned long long bitLength;
    int len, newLen;
    int i;

    len = strlen(message);

    /* Copy message */
    for(i = 0; i < len; i++)
        data[i] = message[i];

    /* Add padding */
    data[len] = 0x80;
    newLen = len + 1;

    while(newLen % 64 != 56)
    {
        data[newLen] = 0;
        newLen++;
    }

    /* Message length in bits */
    bitLength = (unsigned long long)len * 8;

    for(i = 0; i < 8; i++)
    {
        data[newLen + 7 - i] = bitLength & 0xff;
        bitLength >>= 8;
    }

    newLen += 8;

    /* Prepare 512-bit block */
    for(i = 0; i < 16; i++)
    {
        w[i] = ((uint32_t)data[i * 4] << 24) |
               ((uint32_t)data[i * 4 + 1] << 16) |
               ((uint32_t)data[i * 4 + 2] << 8) |
               data[i * 4 + 3];
    }

    for(i = 16; i < 80; i++)
    {
        w[i] = rotateLeft(
            w[i - 3] ^ w[i - 8] ^
            w[i - 14] ^ w[i - 16], 1);
    }

    a = h0;
    b = h1;
    c = h2;
    d = h3;
    e = h4;

    /* SHA-1 processing */
    for(i = 0; i < 80; i++)
    {
        if(i < 20)
        {
            f = (b & c) | ((~b) & d);
            k = 0x5A827999;
        }
        else if(i < 40)
        {
            f = b ^ c ^ d;
            k = 0x6ED9EBA1;
        }
        else if(i < 60)
        {
            f = (b & c) | (b & d) | (c & d);
            k = 0x8F1BBCDC;
        }
        else
        {
            f = b ^ c ^ d;
            k = 0xCA62C1D6;
        }

        temp = rotateLeft(a, 5) + f + e + k + w[i];

        e = d;
        d = c;
        c = rotateLeft(b, 30);
        b = a;
        a = temp;
    }

    h0 += a;
    h1 += b;
    h2 += c;
    h3 += d;
    h4 += e;

    sprintf(output,
            "%08x%08x%08x%08x%08x",
            h0, h1, h2, h3, h4);
}

int main()
{
    char message1[100];
    char message2[100];
    char hash1[41];
    char hash2[41];

    printf("Enter original message: ");
    fgets(message1, sizeof(message1), stdin);

    message1[strcspn(message1, "\n")] = '\0';

    sha1(message1, hash1);

    printf("\n----- ORIGINAL MESSAGE -----\n");
    printf("Message : %s\n", message1);
    printf("SHA-1   : %s\n", hash1);

    printf("\nEnter modified message: ");
    fgets(message2, sizeof(message2), stdin);

    message2[strcspn(message2, "\n")] = '\0';

    sha1(message2, hash2);

    printf("\n----- MODIFIED MESSAGE -----\n");
    printf("Message : %s\n", message2);
    printf("SHA-1   : %s\n", hash2);

    printf("\n----- VERIFICATION -----\n");

    if(strcmp(hash1, hash2) == 0)
    {
        printf("Hash values are SAME.\n");
        printf("Message is unchanged.\n");
    }
    else
    {
        printf("Hash values are DIFFERENT.\n");
        printf("Message has been modified.\n");
    }

    return 0;
}
