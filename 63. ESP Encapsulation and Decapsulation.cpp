#include <stdio.h>
#include <string.h>

void encrypt(char data[], char key[], char encrypted[])
{
    int i;

    for(i = 0; data[i] != '\0'; i++)
    {
        encrypted[i] = data[i] ^ key[i % strlen(key)];
    }

    encrypted[i] = '\0';
}

void decrypt(char encrypted[], char key[], char decrypted[])
{
    int i;

    for(i = 0; encrypted[i] != '\0'; i++)
    {
        decrypted[i] = encrypted[i] ^ key[i % strlen(key)];
    }

    decrypted[i] = '\0';
}

int main()
{
    char packet[100];
    char key[20];
    char encrypted[100];
    char decrypted[100];
    int i;

    printf("Enter IP Packet Data: ");
    scanf("%s", packet);

    printf("Enter ESP Key: ");
    scanf("%s", key);

    /* ESP Encapsulation */
    encrypt(packet, key, encrypted);

    printf("\n----- ESP Encapsulation -----\n");

    printf("Original Packet : %s\n", packet);
    printf("ESP Header      : Added\n");

    printf("Encrypted Data  : ");

    for(i = 0; encrypted[i] != '\0'; i++)
    {
        printf("%02X ", (unsigned char)encrypted[i]);
    }

    printf("\nESP Packet Sent Successfully\n");

    /* ESP Decapsulation */
    decrypt(encrypted, key, decrypted);

    printf("\n----- ESP Decapsulation -----\n");

    printf("ESP Header      : Removed\n");
    printf("Decrypted Data  : %s\n", decrypted);
    printf("Original Packet Recovered Successfully\n");

    return 0;
}
