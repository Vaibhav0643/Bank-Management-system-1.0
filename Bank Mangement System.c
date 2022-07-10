// Bank Management System

#include <stdio.h>  //printf(),scanf()
#include <stdlib.h> //exit(0),system()
#include <conio.h>  //getch()
#include <time.h>   //time(),ctime()
char name[20];
int dip_amt, amt = 10000, acc_no, ac, count = 0; // Global variables
int trans_amt;
int with_amt;

void deposit_money();
void withdraw_money();
void transfer_money();
void checkDetail();
void LastDetail();
void transaction_details();
void menu();

void divider()
{
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }
}

//#Driver function
int main()
{
    FILE *ptr = fopen("Account.txt", "w");

    int ch;
    printf("Enter your name : \n");
    gets(name);
    fprintf(ptr, "\nName : %s\n", name);
    printf("Enter your account no. : ");
    scanf("%d", &acc_no);
    fprintf(ptr, "Account no. : %d\n", acc_no);

    fclose(ptr);
    while (1)
    {
        menu();
        printf("\nEnter your choice :\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            system("cls");
            deposit_money();
            break;
        case 2:
            system("cls");
            withdraw_money();
            break;

        case 3:
            system("cls");
            transfer_money();
            break;

        case 4:
            system("cls");
            checkDetail();
            break;

        case 5:
            transaction_details();
            break;

        case 6:
            system("cls");
            LastDetail();
            exit(0);

        default:
            printf("*****Invalid choice*****");
        }
    }

    return 0;
}

void menu()
{

    system("cls");
    divider();
    printf("\n\tMENU\n");

    divider();
    printf("\n1.Deposit Money\n");
    printf("2.Withdraw Money\n");
    printf("3.Transfer Money\n");
    printf("4.Account details\n");
    printf("5.Transaction details\n");
    printf("6.Exit\n");
    divider();
}

//!---------------------------------------------------------
void deposit_money()
{

    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt", "a");
    printf("*****DEPOSITING MONEY*****\n");
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }

    printf("\nEnter the amount you want to deposit\n");
    scanf("%d", &dip_amt);
    amt += dip_amt;
    printf("****Money Deposited****\n");
    printf("Now balance : %d\n", amt);
    fprintf(ptr, "\nRs%d had been deposited to your account \n", dip_amt);
    fprintf(ptr, "Date/Time of transaction :  %s\n", ctime(&tm));
    count++;

    fclose(ptr);
    printf("Press any key....\n");
    getch();
}

//!---------------------------------------------------------

void withdraw_money()
{

    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt", "a");
    printf("*****WITHDRAWING MONEY*****\n");
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }

    printf("\nEnter the amount you want to withdraw\n");
    scanf("%d", &with_amt);

    if (amt < with_amt)
    {
        printf("****Insufficient balance****\n");
    }
    else
    {
        amt = amt - with_amt;
        printf("*****Money withdrawn*****\n");
        printf("Current balance : %d\n", amt);
        fprintf(ptr, "\nRs%d had been withdrawn from your account \n", with_amt);
        fprintf(ptr, "Date/Time of transaction :  %s\n", ctime(&tm));
        count++;
    }
    fclose(ptr);
    printf("Press any key....\n");

    getch();
}

//!---------------------------------------------------------

void transfer_money()
{

    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt", "a");
    printf("*****TRANSFERRING MONEY*****\n");
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }

    printf("\nEnter the account no. in which you want to transfer the money : ");
    scanf("%d", &ac);
    printf("\nEnter the amount you want to transfer\n");
    scanf("%d", &trans_amt);

    if (amt < trans_amt)
    {
        printf("****You have not sufficient balance****\n");
    }
    else
    {
        amt = amt - trans_amt;
        printf("****Money Transferred****\n");
        printf("Current balance : %d\n", amt);
        fprintf(ptr, "\nRs%d had been transferred from your account to %d\n", trans_amt, ac);
        fprintf(ptr, "Date/Time of transaction :  %s\n", ctime(&tm));
        count++;
    }
    fclose(ptr);
    printf("Press any key....\n");
    getch();
}

//!---------------------------------------------------------

void checkDetail()
{
    printf("ACCOUNT DETAILS\n");
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }

    printf("\nName : %s\n", name);
    printf("Account No. : %d\n", acc_no);
    printf("Total balance = %d\n ", amt);
    printf("\n%d transactions have been made from your account \n", count);
    printf("Press any key.....");
    getch();
}

//!---------------------------------------------------------

void transaction_details()
{

    system("cls");

    FILE *ptr;
    ptr = fopen("Account.txt", "r");
    char c = fgetc(ptr);
    if (c == EOF)
    {
        printf("TRANSACTION DETAILS\n");
        divider();
        printf("\n*******NO RECENT TRANSACTION*******\n");
    }
    else
    {
        printf("TRANSACTION DETAILS\n");
        divider();
        printf("\n%d transactions have been made from your account \n", count);
        while (c != EOF) // EOF=End of file
        {
            printf("%c", c);
            c = fgetc(ptr);
        }
    }

    getch();
}

//!---------------------------------------------------------

void LastDetail()
{
    printf("ACCOUNT DETAILS\n");
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }
    printf("\nName : %s\n", name);
    printf("Account No. : %d\n", acc_no);
    printf("Total balance = %d\n ", amt);

    printf("\n\nPress any key to exit.....");
    getch();
}
