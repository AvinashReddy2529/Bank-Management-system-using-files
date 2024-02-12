#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void new_customer();
void customer_login();
void account_transaction();
void account_withdrawal();
void account_deposit();
void account_loan();
void account_homeloan();
void account_vechileloan();
void account_agricultureloan();
void account_personalloan();
void account_goldloan();
struct Account
{
    char name[50], gender[1];
    int age;
    long int account_number, tenure_fd;
    float deposit_amt, balance;
    long int mobile_num, aadhar_num;
} account;
int main()
{
    int choice_1;
    printf("\nBANK MANAGEMENT SYSTEM\n");
    printf("\nCustomer Services\n");
    printf("Enter\n");
    printf("1-For new user\n");
    printf("2-For existing user\n");
    scanf("%d", &choice_1);

    switch (choice_1)
    {
    case 1:
        new_customer();
        break;
    case 2:
        customer_login();
        break;
    default:
        printf("\nInvalid choice.Please try again./n");
        break;
    }
}
void new_customer()
{
    FILE *fp = fopen("input.txt", "r+");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
    }
    printf("Enter the name of the account holder: ");
    scanf("%s", account.name);
    fputs(account.name, fp);
    printf("Enter age of account holder: ");
    scanf("%d", &account.age);
    printf("Enter gender: ");
    scanf("%s", account.gender);
    fprintf(fp, "%c", account.gender);
    printf("Enter mobile number for holder: ");
    scanf("%.ld", &account.mobile_num);
    printf("Enter aadhar number of the holder: ");
    scanf("%ld", &account.aadhar_num);
    printf("Enter amount deposited in the account :");
    scanf("%f", &account.deposit_amt);
    float balance = account.deposit_amt;
    printf("Enter the account number: ");
    scanf("%ld", &account.account_number);
    fprintf(fp, "\n%d\n%ld\n%ld\n%ld\n%f", account.age, account.account_number, account.mobile_num, account.aadhar_num, account.deposit_amt);
    printf("Account succeefully created.\n");
    fclose(fp);
}
void customer_login()
{
    float random;
    printf("Enter the account Number\n");
    scanf("%f", &random);
    printf("The details of account are\n");
    FILE *fp1 = NULL;
    fp1 = fopen("myfile.txt", "r+");
    char str[50];
    while (!feof(fp1))
    {
        fgets(str, 20, fp1);
        fscanf(fp1, "%d", &account.age);
        fscanf(fp1, "%.0f", &account.mobile_num);
        fscanf(fp1, "%.0f", &account.aadhar_num);
        fscanf(fp1, "%f", &account.balance);
    }
    printf("\nThe Name of The Account Holder:%s", str);
    printf("\nAge of the Account Holder:%d", account.age);
    printf("\nMobile number of the Account Holder:%.0f", account.mobile_num);
    printf("\nAadhar number of the Account Holder:%.0f", account.aadhar_num);
    printf("\nBalance Amount in the Account:%f", account.balance);
    fclose(fp1);
    printf("/nEnter the choice of service you need\n");
    printf("\n1-Transaction");
    printf("\n2-Apply for Loan\n");
    int choice_3;
    scanf("%d", &choice_3);
    switch (choice_3)
    {
    case 1:
        account_transaction();
        break;
    case 2:
        account_loan();
        break;
    default:
        printf("\nInvalid choice.Please try again./n");
        break;
    }
    // fclose(fp);
}
void account_transaction()
{
    int choice_4;
    /*if(fp==NULL)
    {
        printf("Error oprning file.\n");
        return;
    }*/
    printf("\n Enter the choice of transaction you need\n");
    printf("\n1-Withdrawal");
    printf("\n2-Deposit");
    scanf("%d", &choice_4);
    switch (choice_4)
    {
    case 1:
    {
        account_withdrawal();
        break;
    }
    case 2:
    {
        account_deposit();
        break;
    }
    default:
        printf("Invalid Input");
        break;
    }
}
void account_withdrawal()
{
    float amount_1;
    /*if(fp==NULL)
    {
        printf("Error oprning file.\n");
    }*/
    printf("Enter amount to withdrawal");
    scanf("%f", &amount_1);
    float balance_4;
    printf("Enter the Balance");
    scanf("%f", &balance_4);
    if (amount_1 > balance_4)
    {
        printf("Insufficent balance");
    }
    else
    {
        balance_4 = balance_4 - amount_1;
    }
    printf("Balance amount after the transaction is %.2f", balance_4);
}
void account_deposit()
{
    float amount_2;
    struct Account account;

    /*if(fp==NULL)
    {
        printf("Error oprning file.\n");
    }*/
    printf("Enter amount to deposited");
    scanf("%f", &amount_2);
    float balance_2 = balance_2 + amount_2;
    printf("Balance amount after the transaction is %.2f", balance_2);
}
void account_loan()
{
    int credit_score;
    int choice_5;
    printf("\nEnter your credit score :");
    scanf("\n%d", &credit_score);

    if (credit_score < 70)

        printf("Your not elgible take loan");

    else if (credit_score >= 70)
    {
        printf("Select your choice of loan needed");
        printf("\n1-Home loan\n2-Vechile loan\n3-Gold loan\n4-Agiculture loan\n5-Personal loan\n");
    }
    scanf("%d", &choice_5);
    switch (choice_5)
    {
    case 1:
        account_homeloan();
        break;
    case 2:
        account_vechileloan();
        break;
    case 3:
        account_goldloan();
        break;
    case 4:
        account_agricultureloan();
        break;
    case 5:
        account_personalloan();
        break;
    default:
        printf("");
        break;
    }
}
void account_homeloan()
{
    int tenure;
    float loan_amt1, intrest, loan_amt2;
    printf("Enter the loan amount needed: ");
    scanf("\n%f", &loan_amt1);
    printf("\nEnter the tenure you would pay it back to the bank: ");
    scanf("\n%d", &tenure);
    printf("\nYour intrest rate will be 6.80 per year");
    intrest = (loan_amt1 * 6.80 * tenure) / 100;
    loan_amt2 = loan_amt1 + intrest;
    printf("\n You have to pay %f amount by end", loan_amt2);
    printf("\n Your montly EMI will be %f", (loan_amt2 / (tenure * 12)));
}
void account_vechileloan()
{
    int tenure;
    float loan_amt = 0;
    printf("Enter the loan amount needed: ");
    scanf("\n%f", &loan_amt);
    printf("\nEnter the tenure you would pay it back to the bank: ");
    scanf("\n%d", &tenure);
    printf("\nYour intrest rate will be 7.65 per year");
    loan_amt = (loan_amt * 7.65 * tenure) / 100;
    printf("\n You have to pay %f amount by end", loan_amt);
    printf("\n Your montly EMI will be %f", (loan_amt / (tenure * 12)));
}
void account_agricultureloan()
{
    float loan_amt = 0, acers;
    printf("Enter number of acers you have: ");
    scanf("\n%f", &acers);
    loan_amt = acers * 50000;
    printf("You will get %f amount for this loan", loan_amt);
    printf("\nYour intrest rate will be 3.50 per year");
    loan_amt = (loan_amt * 3.5) / 100;
    printf("\n You have to pay %f amount after the selling the product", loan_amt);
}
void account_personalloan()
{
    int tenure;
    float loan_amt = 0;
    printf("Enter the loan amount needed: ");
    scanf("\n%f", &loan_amt);
    printf("\nEnter the tenure you would pay it back to the bank: ");
    scanf("\n%d", &tenure);
    printf("\nYour intrest rate will be 12.90 per year");
    loan_amt = (loan_amt * 12.90 * tenure) / 100;
    printf("\n You have to pay %f amount by end", loan_amt);
    printf("\n Your montly EMI will be %f", (loan_amt / (tenure * 12)));
}
void account_goldloan()
{
    float wg_gold, loan_amt = 0;
    printf("Enter the weight of the gold(in gms) you are keeping as collatrel");
    scanf("%f", &wg_gold);
    loan_amt = (wg_gold / 10) * 35000;
    printf("\nYou will get %f loan amount: ", loan_amt);
    loan_amt = (loan_amt * 9.20) / 100;
    printf("You have to pay back %f amount by 1 year", loan_amt);
}
