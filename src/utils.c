#include "../include/header.h"

void clearScreen() {
    printf("\033[2J\033[H");
}

void printHeader(char *title) {
    printf("\n%s", COLOR_CYAN);
    printf("╔════════════════════════════════════════════════════════╗\n");
    printf("║           %-40s     ║\n", title);
    printf("╚════════════════════════════════════════════════════════╝\n");
    printf("%s", COLOR_RESET);
}

void *notificationListener(void *arg) {
    struct User *u = (struct User *)arg;
    char pipePath[100];
    char buffer[256];
    int fd;
    
    sprintf(pipePath, "%s%d", PIPE_PATH, u->id);
    mkfifo(pipePath, 0666);
    
    while (1) {
        fd = open(pipePath, O_RDONLY);
        if (fd > 0) {
            if (read(fd, buffer, sizeof(buffer)) > 0) {
                printf("\n%s\n🔔 NOTIFICATION: %s%s\n", COLOR_YELLOW, buffer, COLOR_RESET);
                printf("\nPress Enter to continue...");
                fflush(stdout);
            }
            close(fd);
        }
    }
    return NULL;
}

void sendNotification(int userId, char *message) {
    char pipePath[100];
    int fd;
    
    sprintf(pipePath, "%s%d", PIPE_PATH, userId);
    fd = open(pipePath, O_WRONLY | O_NONBLOCK);
    if (fd > 0) {
        write(fd, message, strlen(message) + 1);
        close(fd);
    }
}
