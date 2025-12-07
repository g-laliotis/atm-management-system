#include "header.h"

void mainMenu(struct User u) {
    int option;
    printf("\n\n\t\t======= ATM =======\n\n");
    printf("\n\t\t-->> Feel free to choose one of the options below <<--\n");
    printf("\n\t\t[1]- Create a new account\n");
    printf("\n\t\t[2]- Update account information\n");
    printf("\n\t\t[3]- Check accounts\n");
    printf("\n\t\t[4]- Check list of owned accounts\n");
    printf("\n\t\t[5]- Make Transaction\n");
    printf("\n\t\t[6]- Remove existing account\n");
    printf("\n\t\t[7]- Transfer ownership\n");
    printf("\n\t\t[8]- Exit\n");
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
            exit(0);
        default:
            printf("Invalid operation!\n");
            mainMenu(u);
    }
}

int main() {
    char userName[50];
    char password[50];
    int r = 0;

    printf("\n\n\t\t======= ATM =======\n");
    printf("\n\t\t-->> Feel free to login / register :\n");
    printf("\n\t\t[1]- login\n");
    printf("\n\t\t[2]- register\n");
    printf("\n\t\t[3]- exit\n");

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
                exit(0);
            default:
                printf("Insert a valid operation!\n");
                r = 0;
        }
    }
    return 0;
}
