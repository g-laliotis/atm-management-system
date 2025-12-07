#include "../include/header.h"

void encryptDecrypt(char *str) {
    int key = 0x5A;
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] ^= key;
    }
}

void loginMenu(char a[50], char pass[50]) {
    struct User userChecker;
    FILE *fp;
    char encPass[50];
    
    printf("\n%sEnter your username:%s ", COLOR_CYAN, COLOR_RESET);
    scanf("%s", a);
    printf("%sEnter your password:%s ", COLOR_CYAN, COLOR_RESET);
    scanf("%s", pass);
    
    strcpy(encPass, pass);
    encryptDecrypt(encPass);

    fp = fopen("./data/users.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while (fscanf(fp, "%d %s %s", &userChecker.id, userChecker.name, userChecker.password) != EOF) {
        if (strcmp(userChecker.name, a) == 0 && strcmp(userChecker.password, encPass) == 0) {
            printf("\n%s✓ Login successful!%s\n", COLOR_GREEN, COLOR_RESET);
            fclose(fp);
            mainMenu(userChecker);
            return;
        }
    }
    fclose(fp);
    printf("\n%s✗ Wrong password or username!%s\n", COLOR_RED, COLOR_RESET);
    exit(1);
}

void registerMenu(char a[50], char pass[50]) {
    struct User newUser;
    FILE *fp;
    int lastId = -1;

    printf("\n%sEnter your username:%s ", COLOR_CYAN, COLOR_RESET);
    scanf("%s", a);

    fp = fopen("./data/users.txt", "r");
    if (fp != NULL) {
        while (fscanf(fp, "%d %s %s", &newUser.id, newUser.name, newUser.password) != EOF) {
            if (strcmp(newUser.name, a) == 0) {
                printf("\n%s✗ Username already exists! Please choose a different username.%s\n", COLOR_RED, COLOR_RESET);
                fclose(fp);
                exit(1);
            }
            lastId = newUser.id;
        }
        fclose(fp);
    }

    printf("%sEnter your password:%s ", COLOR_CYAN, COLOR_RESET);
    scanf("%s", pass);

    newUser.id = lastId + 1;
    strcpy(newUser.name, a);
    strcpy(newUser.password, pass);
    encryptDecrypt(newUser.password);

    fp = fopen("./data/users.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(fp, "%d %s %s\n", newUser.id, newUser.name, newUser.password);
    fclose(fp);

    printf("\n%s✓ Registration successful! Logging you in...%s\n", COLOR_GREEN, COLOR_RESET);
    loginMenu(a, pass);
}
