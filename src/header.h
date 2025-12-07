#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Record {
    int id;
    int userId;
    char name[100];
    char country[100];
    int phone;
    char accountType[10];
    int accountNbr;
    double amount;
    struct Date deposit;
};

struct User {
    int id;
    char name[50];
    char password[50];
};

void loginMenu(char a[50], char pass[50]);
void registerMenu(char a[50], char pass[50]);
void mainMenu(struct User u);
void createNewAcc(struct User u);
void checkAllAccounts(struct User u);
void checkAccountDetails(struct User u);
void updateAccount(struct User u);
void makeTransaction(struct User u);
void removeAccount(struct User u);
void transferOwnership(struct User u);

#endif
