#include "header.h"

void loginMenu(char a[50], char pass[50]) {
    struct User userChecker;
    FILE *fp;
    
    printf("\nEnter your username: ");
    scanf("%s", a);
    printf("Enter your password: ");
    scanf("%s", pass);

    fp = fopen("./data/users.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while (fscanf(fp, "%d %s %s", &userChecker.id, userChecker.name, userChecker.password) != EOF) {
        if (strcmp(userChecker.name, a) == 0 && strcmp(userChecker.password, pass) == 0) {
            printf("\n\nPassword Match!");
            fclose(fp);
            mainMenu(userChecker);
            return;
        }
    }
    fclose(fp);
    printf("\nWrong password or username!\n");
    exit(1);
}

void registerMenu(char a[50], char pass[50]) {
    struct User newUser;
    FILE *fp;
    int lastId = -1;

    printf("\nEnter your username: ");
    scanf("%s", a);

    fp = fopen("./data/users.txt", "r");
    if (fp != NULL) {
        while (fscanf(fp, "%d %s %s", &newUser.id, newUser.name, newUser.password) != EOF) {
            if (strcmp(newUser.name, a) == 0) {
                printf("\nUsername already exists! Please choose a different username.\n");
                fclose(fp);
                exit(1);
            }
            lastId = newUser.id;
        }
        fclose(fp);
    }

    printf("Enter your password: ");
    scanf("%s", pass);

    newUser.id = lastId + 1;
    strcpy(newUser.name, a);
    strcpy(newUser.password, pass);

    fp = fopen("./data/users.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(fp, "%d %s %s\n", newUser.id, newUser.name, newUser.password);
    fclose(fp);

    printf("\nRegistration successful! Please login.\n");
    loginMenu(a, pass);
}
