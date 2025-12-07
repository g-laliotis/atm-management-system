#include "header.h"

void createNewAcc(struct User u) {
    struct Record r;
    FILE *fp;
    int lastId = -1;

    fp = fopen("./data/records.txt", "r");
    if (fp != NULL) {
        while (fscanf(fp, "%d %d %s %d %d/%d/%d %s %d %lf %s",
                      &r.id, &r.userId, r.name, &r.accountNbr,
                      &r.deposit.day, &r.deposit.month, &r.deposit.year,
                      r.country, &r.phone, &r.amount, r.accountType) != EOF) {
            lastId = r.id;
        }
        fclose(fp);
    }

    r.id = lastId + 1;
    r.userId = u.id;
    strcpy(r.name, u.name);

    printf("\nEnter account number: ");
    scanf("%d", &r.accountNbr);
    printf("Enter deposit date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &r.deposit.day, &r.deposit.month, &r.deposit.year);
    printf("Enter country: ");
    scanf("%s", r.country);
    printf("Enter phone number: ");
    scanf("%d", &r.phone);
    printf("Enter amount: ");
    scanf("%lf", &r.amount);
    printf("Choose account type (savings/current/fixed01/fixed02/fixed03): ");
    scanf("%s", r.accountType);

    fp = fopen("./data/records.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        mainMenu(u);
        return;
    }

    fprintf(fp, "%d %d %s %d %02d/%02d/%d %s %d %.2lf %s\n",
            r.id, r.userId, r.name, r.accountNbr,
            r.deposit.day, r.deposit.month, r.deposit.year,
            r.country, r.phone, r.amount, r.accountType);
    fclose(fp);

    printf("\nAccount created successfully!\n");
    mainMenu(u);
}

void checkAllAccounts(struct User u) {
    struct Record r;
    FILE *fp;
    int found = 0;

    fp = fopen("./data/records.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        mainMenu(u);
        return;
    }

    printf("\n\t\t====== All accounts from user %s =====\n\n", u.name);
    while (fscanf(fp, "%d %d %s %d %d/%d/%d %s %d %lf %s",
                  &r.id, &r.userId, r.name, &r.accountNbr,
                  &r.deposit.day, &r.deposit.month, &r.deposit.year,
                  r.country, &r.phone, &r.amount, r.accountType) != EOF) {
        if (r.userId == u.id) {
            printf("Account ID: %d\n", r.id);
            printf("Account Number: %d\n", r.accountNbr);
            printf("Deposit Date: %02d/%02d/%d\n", r.deposit.day, r.deposit.month, r.deposit.year);
            printf("Country: %s\n", r.country);
            printf("Phone: %d\n", r.phone);
            printf("Amount: $%.2lf\n", r.amount);
            printf("Type: %s\n\n", r.accountType);
            found = 1;
        }
    }
    fclose(fp);

    if (!found) {
        printf("No accounts found!\n");
    }
    mainMenu(u);
}

void checkAccountDetails(struct User u) {
    printf("Feature not implemented yet\n");
    mainMenu(u);
}

void updateAccount(struct User u) {
    printf("Feature not implemented yet\n");
    mainMenu(u);
}

void makeTransaction(struct User u) {
    printf("Feature not implemented yet\n");
    mainMenu(u);
}

void removeAccount(struct User u) {
    printf("Feature not implemented yet\n");
    mainMenu(u);
}

void transferOwnership(struct User u) {
    printf("Feature not implemented yet\n");
    mainMenu(u);
}
