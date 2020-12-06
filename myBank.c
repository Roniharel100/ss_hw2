#include <stdio.h>
#include "myBank.h"
#include <stdbool.h>

float bankAccounts[50][2] = {0};

// This function get an amount and opening an account.
// prints the account number.
// This action is only allowed if there is less of 50 open accounts.
void O(float amount)
{
    for (int i = 0; i < 50; i++)
    {
        if (bankAccounts[i][1] == 0)
        {
            bankAccounts[i][0] = amount;
            bankAccounts[i][1] = 1;
            i = i + 901;
            printf(" New account number is: %d.\n", i);
            return;
        }
    }
    printf(" The bank is full, you can't open a new account\n");
}

// This function get an account number, and prints his balance.
// This action allowed if this account is open.
void B(int account_number)
{
    float num;
    if (bankAccounts[account_number - 901][1] == 1)
    {
        num = bankAccounts[account_number - 901][0];
        printf(" The balance of account number %d is: %0.2f\n", account_number, num);
    }
    else
        printf(" This account is closed\n");
}

// This function get an account number and an amount and
// add the amount to the balance. (deposit)
// Prints the new balance.
// This action allowed if this account is open.
void D(int account_number)
{
    float num;
    if (bankAccounts[account_number - 901][1] == 0)
    {
        printf(" This account is closed\n");
    }
    else
    {
        printf("Please enter the amount to deposit:");
        float amount2;
        if (scanf("%f", &amount2) == 0)
            printf(" Failed to read the amount\n");
        else if (amount2 <= 0)
            printf(" Cannot deposit a negative amount\n");
        else
        {
            bankAccounts[account_number - 901][0] =
                bankAccounts[account_number - 901][0] + amount2;
            num = bankAccounts[account_number - 901][0];
            printf(" The new account balance is: %0.2f\n", num);
        }
    }
}

// This function get an account number and an amount and
// removes the amount from the balance. (withdrawal)
// unction that accepts a withdrawal amount and account number and
// Print the new balance.
// This action allowed if this account is open and
// there is enough money to withdraw.
void W(int account_number)
{
    float num;
    if (bankAccounts[account_number - 901][1] == 0)
        printf(" This account is closed\n");
    else
    {
        printf(" Please enter the amount to withdraw:");
        float amount3;
        if (scanf("%f", &amount3) == 0)
            printf(" Failed to read the amount\n");
        else if (bankAccounts[account_number - 901][0] <= amount3)
            printf(" Cannot withdraw more than the balance\n");
        else
        {
            bankAccounts[account_number - 901][0] =
                bankAccounts[account_number - 901][0] - amount3;
            num = bankAccounts[account_number - 901][0];
            printf(" The new balance is: %0.2f\n", num);
        }
    }
}

//This function get an account number and close it.
// This action allowed if this account is open.
void C(int account_number)
{
    if (bankAccounts[account_number - 901][1] == 1)
    {
        bankAccounts[account_number - 901][1] = 0;
        printf(" Closed account number %d\n",account_number);
    }
    else
    {
        printf(" The account is already closed\n");
    }
}

//This function get an interest rate.
// Add the interest rate to all the open accounts.
void I(int interest_rate)
{
    for (int i = 0; i < 50; i++)
        if (bankAccounts[i][1] == 1)
            bankAccounts[i][0] = bankAccounts[i][0] * (1 + interest_rate / 100);
}

//Print all open accounts and their balance.
void P()
{
    int account;
    float amount;
    for (int i = 0; i < 50; i++)
    {
        if (bankAccounts[i][1] == 1)
        {
            account = i + 901;
            amount = bankAccounts[i][0];
            printf(" The balance of account number %d is: %0.2f\n", account, amount);
        }
    }
}

//Close all accounts and exit the program.
void E()
{
    for (int i = 0; i < 50; i++)
    {
        if (bankAccounts[i][1] == 1)
        {
            bankAccounts[i][1] = 0;
        }
    }
}
