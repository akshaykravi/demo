//Matrix animation

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define MAX_FALLEN_NUMBERS 100

typedef struct {
    int x;
    int y;
    int number;
    int speed;
} FallenNumber;

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape sequence to clear the screen
}

void initializeFallenNumbers(FallenNumber* fallenNumbers) {
    int i;
    srand(time(NULL));

    for (i = 0; i < MAX_FALLEN_NUMBERS; i++) {
        fallenNumbers[i].x = rand() % SCREEN_WIDTH;
        fallenNumbers[i].y = -1 * (rand() % SCREEN_HEIGHT);
        fallenNumbers[i].number = rand() % 10; // Numbers range from 0 to 9
        fallenNumbers[i].speed = rand() % 5 + 1;
    }
}

void updateFallenNumbers(FallenNumber* fallenNumbers) {
    int i;

    for (i = 0; i < MAX_FALLEN_NUMBERS; i++) {
        fallenNumbers[i].y += fallenNumbers[i].speed;

        if (fallenNumbers[i].y >= SCREEN_HEIGHT) {
            fallenNumbers[i].y = -1 * (rand() % SCREEN_HEIGHT);
            fallenNumbers[i].number = rand() % 10;
            fallenNumbers[i].speed = rand() % 5 + 1;
        }
    }
}

void drawFallenNumbers(FallenNumber* fallenNumbers) {
    int i;

    clearScreen();

    for (i = 0; i < MAX_FALLEN_NUMBERS; i++) {
        printf("\033[%d;%dH%d", fallenNumbers[i].y, fallenNumbers[i].x, fallenNumbers[i].number);
        fflush(stdout);
    }
}

int main() {
    FallenNumber fallenNumbers[MAX_FALLEN_NUMBERS];

    initializeFallenNumbers(fallenNumbers);

    while (1) {
        updateFallenNumbers(fallenNumbers);
        drawFallenNumbers(fallenNumbers);
        usleep(50000); // Pause for 50 milliseconds
    }

    return 0;
}
