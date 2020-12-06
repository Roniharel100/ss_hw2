#include <stdio.h>
#include "myBank.h"
#include <stdbool.h>

int main()
{
    bool Continue = true;
    while (Continue)
    {
        char choice;
        printf("\nPlease choose a transaction type:\n");
        printf(" O-Open Account\n");
        printf(" B-Balance Inquiry\n");
        printf(" D-Deposit\n");
        printf(" W-Withdrawal\n");
        printf(" C-Close Account\n");
        printf(" I-Interest\n");
        printf(" P-Print\n");
        printf(" E-Exit\n");
        scanf(" %c", &choice);

        switch (choice)
        {

        case 'O':
            printf("Please enter amount for deposit:");
            float amount;
            if (scanf("%f", &amount) == 0)
                printf(" Failed to read the amount\n");
            else if (amount < 0)
                printf(" Invalid Amount\n");
            else
                O(amount);
            break;

        case 'B':
            printf("Please enter account number:");
            int accountNumber1;
            if (scanf("%d", &accountNumber1) == 0 ||
                accountNumber1 < 901 || accountNumber1 > 950)
            {
                printf(" Failed to read the account number\n");
                break;
            }
            B(accountNumber1);
            break;

        case 'D':
            printf("Please enter account number:");
            int accountNumber2;
            if (scanf("%d", &accountNumber2) == 0)
                printf(" Failed to read the account number\n");
            else if (accountNumber2 < 901 || accountNumber2 > 950)
                printf(" Invalid account number\n");
            else
                D(accountNumber2);
            break;

        case 'W':
            printf("Please enter account number:");
            int accountNumber3;
            if (scanf("%d", &accountNumber3) == 0)
                printf(" Failed to read the account number\n");
            else if (accountNumber3 < 901 || accountNumber3 > 950)
                printf(" Invalid account number\n");
            else
                W(accountNumber3);
            break;

        case 'C':
            printf("Please enter account number:");
            int accountNumber4;
            if (scanf("%d", &accountNumber4) == 0 ||
                accountNumber4 < 901 || accountNumber4 > 950)

            {
                printf(" Failed to read the account number\n");
                break;
            }
            C(accountNumber4);
            break;

        case 'I':
            printf("Please enter interest rate:");
            int interest;
            if (scanf("%d", &interest) == 0)
                printf(" Failed to read the interest rate\n");
            else if (interest <= 0)
                printf(" invalid interest rate\n");
            else
                I(interest);
            break;

        case 'P':
            P();
            break;

        case 'E':
            E();
            Continue = false;
            break;

        default:
            printf(" Invalid transaction type\n");
        }
    }
}