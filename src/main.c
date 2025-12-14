#include "header.h"

static pthread_t notifyThread;

void mainMenu(struct User u) {
    int option;
    static int firstRun = 1;
    
    if (firstRun) {
        pthread_create(&notifyThread, NULL, notificationListener, &u);
        pthread_detach(notifyThread);
        firstRun = 0;
    }
    
    clearScreen();
    printHeader("ATM MANAGEMENT SYSTEM");
    printf("\n%sWelcome, %s!%s\n", COLOR_GREEN, u.name, COLOR_RESET);
    printf("\n%s┌────────────────────────────────────────┐%s\n", COLOR_BLUE, COLOR_RESET);
    printf("%s│  [1]%s Create a new account           %s│%s\n", COLOR_BLUE, COLOR_RESET, COLOR_BLUE, COLOR_RESET);
    printf("%s│  [2]%s Update account information     %s│%s\n", COLOR_BLUE, COLOR_RESET, COLOR_BLUE, COLOR_RESET);
    printf("%s│  [3]%s Check account details          %s│%s\n", COLOR_BLUE, COLOR_RESET, COLOR_BLUE, COLOR_RESET);
    printf("%s│  [4]%s Check list of owned accounts   %s│%s\n", COLOR_BLUE, COLOR_RESET, COLOR_BLUE, COLOR_RESET);
    printf("%s│  [5]%s Make Transaction               %s│%s\n", COLOR_BLUE, COLOR_RESET, COLOR_BLUE, COLOR_RESET);
    printf("%s│  [6]%s Remove existing account        %s│%s\n", COLOR_BLUE, COLOR_RESET, COLOR_BLUE, COLOR_RESET);
    printf("%s│  [7]%s Transfer ownership             %s│%s\n", COLOR_BLUE, COLOR_RESET, COLOR_BLUE, COLOR_RESET);
    printf("%s│  [8]%s Exit                           %s│%s\n", COLOR_BLUE, COLOR_RESET, COLOR_BLUE, COLOR_RESET);
    printf("%s└────────────────────────────────────────┘%s\n", COLOR_BLUE, COLOR_RESET);
    printf("\n%sChoice:%s ", COLOR_CYAN, COLOR_RESET);
    scanf("%d", &option);

    switch (option) {
        case 1:
            createNewAcc(u);
            break;
        case 2:
            updateAccount(u);
            break;
        case 3:
            checkAccountDetails(u);
            break;
        case 4:
            checkAllAccounts(u);
            break;
        case 5:
            makeTransaction(u);
            break;
        case 6:
            removeAccount(u);
            break;
        case 7:
            transferOwnership(u);
            break;
        case 8:
            printf("\n%sGoodbye!%s\n", COLOR_GREEN, COLOR_RESET);
            closeDatabase();
            exit(0);
        default:
            printf("%s\nInvalid operation!%s\n", COLOR_RED, COLOR_RESET);
            mainMenu(u);
    }
}

int main() {
    char userName[50];
    char password[50];
    int r = 0;

    initDatabase();
    clearScreen();
    printHeader("ATM MANAGEMENT SYSTEM");
    printf("\n%s┌────────────────────────────────────────┐%s\n", COLOR_BLUE, COLOR_RESET);
    printf("%s│  [1]%s Login                          %s│%s\n", COLOR_BLUE, COLOR_RESET, COLOR_BLUE, COLOR_RESET);
    printf("%s│  [2]%s Register                       %s│%s\n", COLOR_BLUE, COLOR_RESET, COLOR_BLUE, COLOR_RESET);
    printf("%s│  [3]%s Exit                           %s│%s\n", COLOR_BLUE, COLOR_RESET, COLOR_BLUE, COLOR_RESET);
    printf("%s└────────────────────────────────────────┘%s\n", COLOR_BLUE, COLOR_RESET);
    printf("\n%sChoice:%s ", COLOR_CYAN, COLOR_RESET);

    while (!r) {
        scanf("%d", &r);
        switch (r) {
            case 1:
                loginMenu(userName, password);
                break;
            case 2:
                registerMenu(userName, password);
                break;
            case 3:
                printf("\n%sGoodbye!%s\n", COLOR_GREEN, COLOR_RESET);
                closeDatabase();
                exit(0);
            default:
                printf("%s\nInsert a valid operation!%s\n", COLOR_RED, COLOR_RESET);
                r = 0;
        }
    }
    return 0;
}
