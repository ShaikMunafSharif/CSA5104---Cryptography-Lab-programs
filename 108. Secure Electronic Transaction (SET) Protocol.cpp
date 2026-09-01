#include <stdio.h>
#include <string.h>

int main()
{
    char customer[50];
    char merchant[50];
    char product[100];
    float amount;

    printf("============================================\n");
    printf("       SECURE ELECTRONIC TRANSACTION\n");
    printf("                 (SET)\n");
    printf("============================================\n");

    printf("\nEnter Customer Name: ");
    fgets(customer, sizeof(customer), stdin);
    customer[strcspn(customer, "\n")] = '\0';

    printf("Enter Merchant Name: ");
    fgets(merchant, sizeof(merchant), stdin);
    merchant[strcspn(merchant, "\n")] = '\0';

    printf("Enter Product Name: ");
    fgets(product, sizeof(product), stdin);
    product[strcspn(product, "\n")] = '\0';

    printf("Enter Amount: ");
    scanf("%f", &amount);

    printf("\n============================================\n");
    printf("          SET TRANSACTION PROCESS\n");
    printf("============================================\n");

    /* Certificate Authority */
    printf("\n1. CERTIFICATE AUTHORITY\n");
    printf("Certificate Authority verifies Customer and Merchant.\n");
    printf("Customer Certificate : VALID\n");
    printf("Merchant Certificate : VALID\n");

    /* Customer */
    printf("\n2. CUSTOMER\n");
    printf("Customer: %s\n", customer);
    printf("Product : %s\n", product);
    printf("Amount  : %.2f\n", amount);
    printf("Customer sends secure order to Merchant.\n");

    /* Merchant */
    printf("\n3. MERCHANT\n");
    printf("Merchant: %s\n", merchant);
    printf("Merchant verifies Customer Certificate.\n");
    printf("Merchant verifies the transaction information.\n");

    /* Payment Gateway */
    printf("\n4. PAYMENT GATEWAY\n");
    printf("Payment Gateway receives payment information.\n");
    printf("Payment details are verified.\n");
    printf("Payment Authorization: APPROVED\n");

    /* Confirmation */
    printf("\n5. TRANSACTION CONFIRMATION\n");
    printf("Merchant receives payment confirmation.\n");
    printf("Order is accepted.\n");

    printf("\n============================================\n");
    printf("          SET TRANSACTION SUCCESSFUL\n");
    printf("============================================\n");

    printf("\nCustomer : %s\n", customer);
    printf("Merchant : %s\n", merchant);
    printf("Product  : %s\n", product);
    printf("Amount   : %.2f\n", amount);
    printf("Status   : PAYMENT SUCCESSFUL\n");

    return 0;
}
