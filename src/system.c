#include "header.h"

void createNewAcc(struct User u) {
    struct Record r;
    FILE *fp;
    int lastId = -1;

    fp = fopen("./data/records.txt", "r");
    if (fp != NULL) {
        while (fscanf(fp, "%d %d %s %d %d/%d/%d %s %lld %lf %s",
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
    scanf("%lld", &r.phone);
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

    fprintf(fp, "%d %d %s %d %02d/%02d/%d %s %lld %.2lf %s\n",
            r.id, r.userId, r.name, r.accountNbr,
            r.deposit.day, r.deposit.month, r.deposit.year,
            r.country, r.phone, r.amount, r.accountType);
    fclose(fp);

    printf("\n%s✓ Account created successfully!%s\n", COLOR_GREEN, COLOR_RESET);
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
    while (fscanf(fp, "%d %d %s %d %d/%d/%d %s %lld %lf %s",
                  &r.id, &r.userId, r.name, &r.accountNbr,
                  &r.deposit.day, &r.deposit.month, &r.deposit.year,
                  r.country, &r.phone, &r.amount, r.accountType) != EOF) {
        if (r.userId == u.id) {
            printf("Account ID: %d\n", r.id);
            printf("Account Number: %d\n", r.accountNbr);
            printf("Deposit Date: %02d/%02d/%d\n", r.deposit.day, r.deposit.month, r.deposit.year);
            printf("Country: %s\n", r.country);
            printf("Phone: %lld\n", r.phone);
            printf("Amount: $%.2lf\n", r.amount);
            printf("Type: %s\n\n", r.accountType);
            found = 1;
        }
    }
    fclose(fp);

    if (!found) {
        printf("No accounts found!\n");
    }
    
    printf("\n%sPress Enter to continue...%s", COLOR_YELLOW, COLOR_RESET);
    getchar(); // consume newline from previous input
    getchar(); // wait for user input
    
    mainMenu(u);
}

void checkAccountDetails(struct User u) {
    struct Record r;
    FILE *fp;
    int accountId, found = 0;
    double interest, monthlyInterest;

    printf("\nEnter account ID: ");
    scanf("%d", &accountId);

    fp = fopen("./data/records.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        mainMenu(u);
        return;
    }

    while (fscanf(fp, "%d %d %s %d %d/%d/%d %s %lld %lf %s",
                  &r.id, &r.userId, r.name, &r.accountNbr,
                  &r.deposit.day, &r.deposit.month, &r.deposit.year,
                  r.country, &r.phone, &r.amount, r.accountType) != EOF) {
        if (r.id == accountId && r.userId == u.id) {
            printf("\nAccount ID: %d\n", r.id);
            printf("Account Number: %d\n", r.accountNbr);
            printf("Deposit Date: %02d/%02d/%d\n", r.deposit.day, r.deposit.month, r.deposit.year);
            printf("Country: %s\n", r.country);
            printf("Phone: %lld\n", r.phone);
            printf("Amount: $%.2lf\n", r.amount);
            printf("Type: %s\n", r.accountType);

            if (strcmp(r.accountType, "savings") == 0 || strcmp(r.accountType, "saving") == 0) {
                monthlyInterest = r.amount * 0.07 / 12;
                printf("\nYou will get $%.2lf as interest on day %d of every month\n", monthlyInterest, r.deposit.day);
            } else if (strcmp(r.accountType, "fixed01") == 0) {
                interest = r.amount * 0.04;
                printf("\nYou will get $%.2lf as interest on %02d/%02d/%d\n", interest, r.deposit.day, r.deposit.month, r.deposit.year + 1);
            } else if (strcmp(r.accountType, "fixed02") == 0) {
                interest = r.amount * 0.05;
                printf("\nYou will get $%.2lf as interest on %02d/%02d/%d\n", interest, r.deposit.day, r.deposit.month, r.deposit.year + 2);
            } else if (strcmp(r.accountType, "fixed03") == 0) {
                interest = r.amount * 0.08;
                printf("\nYou will get $%.2lf as interest on %02d/%02d/%d\n", interest, r.deposit.day, r.deposit.month, r.deposit.year + 3);
            } else if (strcmp(r.accountType, "current") == 0) {
                printf("\nYou will not get interests because the account is of type current\n");
            }
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found) {
        printf("\nAccount not found or you don't have permission!\n");
    }
    
    printf("\n%sPress Enter to continue...%s", COLOR_YELLOW, COLOR_RESET);
    getchar(); // consume newline from previous input
    getchar(); // wait for user input
    
    mainMenu(u);
}

void updateAccount(struct User u) {
    struct Record records[100];
    FILE *fp;
    int accountId, count = 0, found = 0, choice;

    printf("\nEnter account ID to update: ");
    scanf("%d", &accountId);

    fp = fopen("./data/records.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        mainMenu(u);
        return;
    }

    while (fscanf(fp, "%d %d %s %d %d/%d/%d %s %lld %lf %s",
                  &records[count].id, &records[count].userId, records[count].name,
                  &records[count].accountNbr, &records[count].deposit.day,
                  &records[count].deposit.month, &records[count].deposit.year,
                  records[count].country, &records[count].phone,
                  &records[count].amount, records[count].accountType) != EOF) {
        if (records[count].id == accountId && records[count].userId == u.id) {
            found = 1;
            printf("\nWhat do you want to update?\n");
            printf("[1] Country\n");
            printf("[2] Phone number\n");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("Enter new country: ");
                scanf("%s", records[count].country);
            } else if (choice == 2) {
                printf("Enter new phone number: ");
                scanf("%lld", &records[count].phone);
            } else {
                printf("Invalid choice!\n");
                fclose(fp);
                mainMenu(u);
                return;
            }
        }
        count++;
    }
    fclose(fp);

    if (!found) {
        printf("\nAccount not found or you don't have permission!\n");
        mainMenu(u);
        return;
    }

    fp = fopen("./data/records.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d %d %s %d %02d/%02d/%d %s %lld %.2lf %s\n",
                records[i].id, records[i].userId, records[i].name,
                records[i].accountNbr, records[i].deposit.day,
                records[i].deposit.month, records[i].deposit.year,
                records[i].country, records[i].phone,
                records[i].amount, records[i].accountType);
    }
    fclose(fp);

    printf("\n%s✓ Account updated successfully!%s\n", COLOR_GREEN, COLOR_RESET);
    mainMenu(u);
}

void makeTransaction(struct User u) {
    struct Record records[100];
    FILE *fp;
    int accountId, count = 0, found = 0, choice;
    double amount;

    printf("\nEnter account ID: ");
    scanf("%d", &accountId);

    fp = fopen("./data/records.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        mainMenu(u);
        return;
    }

    while (fscanf(fp, "%d %d %s %d %d/%d/%d %s %lld %lf %s",
                  &records[count].id, &records[count].userId, records[count].name,
                  &records[count].accountNbr, &records[count].deposit.day,
                  &records[count].deposit.month, &records[count].deposit.year,
                  records[count].country, &records[count].phone,
                  &records[count].amount, records[count].accountType) != EOF) {
        if (records[count].id == accountId && records[count].userId == u.id) {
            found = 1;
            if (strcmp(records[count].accountType, "fixed01") == 0 ||
                strcmp(records[count].accountType, "fixed02") == 0 ||
                strcmp(records[count].accountType, "fixed03") == 0) {
                printf("\n%s✗ Error: Transactions not allowed for fixed accounts!%s\n", COLOR_RED, COLOR_RESET);
                fclose(fp);
                mainMenu(u);
                return;
            }

            printf("\n[1] Deposit\n");
            printf("[2] Withdraw\n");
            scanf("%d", &choice);
            printf("Enter amount: ");
            scanf("%lf", &amount);

            if (choice == 1) {
                records[count].amount += amount;
                printf("\n%s✓ Deposit successful!%s\n", COLOR_GREEN, COLOR_RESET);
            } else if (choice == 2) {
                if (records[count].amount >= amount) {
                    records[count].amount -= amount;
                    printf("\n%s✓ Withdrawal successful!%s\n", COLOR_GREEN, COLOR_RESET);
                } else {
                    printf("\n%s✗ Insufficient funds!%s\n", COLOR_RED, COLOR_RESET);
                    fclose(fp);
                    mainMenu(u);
                    return;
                }
            } else {
                printf("Invalid choice!\n");
                fclose(fp);
                mainMenu(u);
                return;
            }
        }
        count++;
    }
    fclose(fp);

    if (!found) {
        printf("\nAccount not found or you don't have permission!\n");
        mainMenu(u);
        return;
    }

    fp = fopen("./data/records.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d %d %s %d %02d/%02d/%d %s %lld %.2lf %s\n",
                records[i].id, records[i].userId, records[i].name,
                records[i].accountNbr, records[i].deposit.day,
                records[i].deposit.month, records[i].deposit.year,
                records[i].country, records[i].phone,
                records[i].amount, records[i].accountType);
    }
    fclose(fp);

    mainMenu(u);
}

void removeAccount(struct User u) {
    struct Record records[100];
    FILE *fp;
    int accountId, count = 0, found = 0;

    printf("\nEnter account ID to remove: ");
    scanf("%d", &accountId);

    fp = fopen("./data/records.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        mainMenu(u);
        return;
    }

    while (fscanf(fp, "%d %d %s %d %d/%d/%d %s %lld %lf %s",
                  &records[count].id, &records[count].userId, records[count].name,
                  &records[count].accountNbr, &records[count].deposit.day,
                  &records[count].deposit.month, &records[count].deposit.year,
                  records[count].country, &records[count].phone,
                  &records[count].amount, records[count].accountType) != EOF) {
        if (records[count].id == accountId && records[count].userId == u.id) {
            found = 1;
        } else {
            count++;
        }
    }
    fclose(fp);

    if (!found) {
        printf("\nAccount not found or you don't have permission!\n");
        mainMenu(u);
        return;
    }

    fp = fopen("./data/records.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d %d %s %d %02d/%02d/%d %s %lld %.2lf %s\n",
                records[i].id, records[i].userId, records[i].name,
                records[i].accountNbr, records[i].deposit.day,
                records[i].deposit.month, records[i].deposit.year,
                records[i].country, records[i].phone,
                records[i].amount, records[i].accountType);
    }
    fclose(fp);

    printf("\n%s✓ Account removed successfully!%s\n", COLOR_GREEN, COLOR_RESET);
    mainMenu(u);
}

void transferOwnership(struct User u) {
    struct Record records[100];
    struct User targetUser;
    FILE *fp, *userFp;
    int accountId, count = 0, found = 0, userFound = 0;
    char targetUsername[50];

    printf("\nEnter account ID to transfer: ");
    scanf("%d", &accountId);
    printf("Enter username to transfer to: ");
    scanf("%s", targetUsername);

    userFp = fopen("./data/users.txt", "r");
    if (userFp == NULL) {
        printf("Error opening users file!\n");
        mainMenu(u);
        return;
    }

    while (fscanf(userFp, "%d %s %s", &targetUser.id, targetUser.name, targetUser.password) != EOF) {
        if (strcmp(targetUser.name, targetUsername) == 0) {
            userFound = 1;
            break;
        }
    }
    fclose(userFp);

    if (!userFound) {
        printf("\nTarget user not found!\n");
        mainMenu(u);
        return;
    }

    fp = fopen("./data/records.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        mainMenu(u);
        return;
    }

    while (fscanf(fp, "%d %d %s %d %d/%d/%d %s %lld %lf %s",
                  &records[count].id, &records[count].userId, records[count].name,
                  &records[count].accountNbr, &records[count].deposit.day,
                  &records[count].deposit.month, &records[count].deposit.year,
                  records[count].country, &records[count].phone,
                  &records[count].amount, records[count].accountType) != EOF) {
        if (records[count].id == accountId && records[count].userId == u.id) {
            found = 1;
            records[count].userId = targetUser.id;
            strcpy(records[count].name, targetUser.name);
        }
        count++;
    }
    fclose(fp);

    if (!found) {
        printf("\nAccount not found or you don't have permission!\n");
        mainMenu(u);
        return;
    }

    fp = fopen("./data/records.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d %d %s %d %02d/%02d/%d %s %lld %.2lf %s\n",
                records[i].id, records[i].userId, records[i].name,
                records[i].accountNbr, records[i].deposit.day,
                records[i].deposit.month, records[i].deposit.year,
                records[i].country, records[i].phone,
                records[i].amount, records[i].accountType);
    }
    fclose(fp);

    char notifyMsg[256];
    sprintf(notifyMsg, "You received account #%d from %s", accountId, u.name);
    sendNotification(targetUser.id, notifyMsg);
    
    printf("\n%s✓ Ownership transferred successfully to %s!%s\n", COLOR_GREEN, targetUsername, COLOR_RESET);
    mainMenu(u);
}
