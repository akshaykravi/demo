//Matrix animation

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define MAX_FALLEN_LETTERS 100

typedef struct {
    int x;
    int y;
    char symbol;
    int speed;
} FallenLetter;

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape sequence to clear the screen
}

void initializeFallenLetters(FallenLetter* fallenLetters) {
    int i;
    srand(time(NULL));

    for (i = 0; i < MAX_FALLEN_LETTERS; i++) {
        fallenLetters[i].x = rand() % SCREEN_WIDTH;
        fallenLetters[i].y = -1 * (rand() % SCREEN_HEIGHT);
        fallenLetters[i].symbol = (char)(rand() % 94 + 33); // ASCII printable characters range
        fallenLetters[i].speed = rand() % 5 + 1;
    }
}

void updateFallenLetters(FallenLetter* fallenLetters) {
    int i;

    for (i = 0; i < MAX_FALLEN_LETTERS; i++) {
        fallenLetters[i].y += fallenLetters[i].speed;

        if (fallenLetters[i].y >= SCREEN_HEIGHT) {
            fallenLetters[i].y = -1 * (rand() % SCREEN_HEIGHT);
            fallenLetters[i].symbol = (char)(rand() % 94 + 33);
            fallenLetters[i].speed = rand() % 5 + 1;
        }
    }
}

void drawFallenLetters(FallenLetter* fallenLetters) {
    int i;

    clearScreen();

    for (i = 0; i < MAX_FALLEN_LETTERS; i++) {
        printf("\033[%d;%dH%c", fallenLetters[i].y, fallenLetters[i].x, fallenLetters[i].symbol);
        fflush(stdout);
    }
}

int main() {
    FallenLetter fallenLetters[MAX_FALLEN_LETTERS];

    initializeFallenLetters(fallenLetters);

    while (1) {
        updateFallenLetters(fallenLetters);
        drawFallenLetters(fallenLetters);
        usleep(50000); // Pause for 50 milliseconds
    }

    return 0;
}
