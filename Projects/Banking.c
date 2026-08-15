#include <stdio.h>

struct Account
{
    int accountNo;
    char name[50];
    float balance;
};

void createAccount()
{
    struct Account a;
    FILE *fp;

    fp = fopen("bank.txt", "a");

    printf("\nEnter Account Number: ");
    scanf("%d", &a.accountNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", a.name);

    printf("Enter Initial Balance: ");
    scanf("%f", &a.balance);

    fprintf(fp, "%d %s %.2f\n",
            a.accountNo, a.name, a.balance);

    fclose(fp);

    printf("\nAccount created successfully.\n");
}

void deposit()
{
    struct Account a;
    FILE *fp;
    FILE *temp;

    int accountNo;
    float amount;
    int found = 0;

    fp = fopen("bank.txt", "r");
    temp = fopen("temp.txt", "w");

    printf("\nEnter Account Number: ");
    scanf("%d", &accountNo);

    while(fscanf(fp, "%d %s %f",
                 &a.accountNo, a.name,
                 &a.balance) != EOF)
    {
        if(a.accountNo == accountNo)
        {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);

            a.balance = a.balance + amount;

            found = 1;
        }

        fprintf(temp, "%d %s %.2f\n",
                a.accountNo, a.name, a.balance);
    }

    fclose(fp);
    fclose(temp);

    remove("bank.txt");
    rename("temp.txt", "bank.txt");

    if(found == 1)
    {
        printf("\nMoney deposited successfully.\n");
    }
    else
    {
        printf("\nAccount not found.\n");
    }
}

void withdraw()
{
    struct Account a;
    FILE *fp;
    FILE *temp;

    int accountNo;
    float amount;
    int found = 0;

    fp = fopen("bank.txt", "r");
    temp = fopen("temp.txt", "w");

    printf("\nEnter Account Number: ");
    scanf("%d", &accountNo);

    while(fscanf(fp, "%d %s %f",
                 &a.accountNo, a.name,
                 &a.balance) != EOF)
    {
        if(a.accountNo == accountNo)
        {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if(amount <= a.balance)
            {
                a.balance = a.balance - amount;
                printf("\nMoney withdrawn successfully.\n");
                found = 1;
            }
            else
            {
                printf("\nNot enough balance.\n");
                found = 1;
            }
        }

        fprintf(temp, "%d %s %.2f\n",
                a.accountNo, a.name, a.balance);
    }

    fclose(fp);
    fclose(temp);

    remove("bank.txt");
    rename("temp.txt", "bank.txt");

    if(found == 0)
    {
        printf("\nAccount not found.\n");
    }
}

void balance()
{
    struct Account a;
    FILE *fp;

    int accountNo;
    int found = 0;

    fp = fopen("bank.txt", "r");

    if(fp == NULL)
    {
        printf("\nNo accounts found.\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%d", &accountNo);

    while(fscanf(fp, "%d %s %f",
                 &a.accountNo, a.name,
                 &a.balance) != EOF)
    {
        if(a.accountNo == accountNo)
        {
            printf("\nAccount Number: %d", a.accountNo);
            printf("\nName: %s", a.name);
            printf("\nBalance: %.2f\n", a.balance);

            found = 1;
            break;
        }
    }

    fclose(fp);

    if(found == 0)
    {
        printf("\nAccount not found.\n");
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n\n===== BANKING SYSTEM =====\n");

        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Balance Enquiry\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                createAccount();
                break;

            case 2:
                deposit();
                break;

            case 3:
                withdraw();
                break;

            case 4:
                balance();
                break;

            case 5:
                return 0;

            default:
                printf("\nInvalid choice.\n");
        }
    }
}