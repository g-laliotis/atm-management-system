#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <pthread.h>

#define PIPE_PATH "/tmp/atm_notify_"
#define COLOR_RESET "\033[0m"
#define COLOR_GREEN "\033[32m"
#define COLOR_RED "\033[31m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BLUE "\033[34m"
#define COLOR_CYAN "\033[36m"

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

void encryptDecrypt(char *str);
void loginMenu(char a[50], char pass[50]);
void registerMenu(char a[50], char pass[50]);
void mainMenu(struct User u);
void *notificationListener(void *arg);
void sendNotification(int userId, char *message);
void clearScreen();
void printHeader(char *title);
void createNewAcc(struct User u);
void checkAllAccounts(struct User u);
void checkAccountDetails(struct User u);
void updateAccount(struct User u);
void makeTransaction(struct User u);
void removeAccount(struct User u);
void transferOwnership(struct User u);
int initDatabase();
void closeDatabase();

#endif
