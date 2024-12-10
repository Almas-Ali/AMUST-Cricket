#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void playInnings(const char *batting, int *totalRuns) {
    int userInput, computerInput;
    *totalRuns = 0;

    printf("\n--- %s is batting ---\n", batting);
    for (int i = 1; i <= 6; i++) { // 6 balls (1 over)
        if (strcmp(batting, "User") == 0) {
            // User batting
            printf("Enter your run (1-6): ");
            scanf("%d", &userInput);

            if (userInput < 1 || userInput > 6) {
                printf("Invalid input! Try again.\n");
                i--; // Retry the same ball
                continue;
            }

            computerInput = rand() % 6 + 1; // Computer guesses
            printf("Computer guessed: %d\n", computerInput);

            if (userInput == computerInput) {
                printf("OUT! You are dismissed.\n");
                break;
            } else {
                *totalRuns += userInput; // Add user's run
                printf("Not out! Runs so far: %d\n", *totalRuns);
            }
        } else {
            // Computer batting
            computerInput = rand() % 6 + 1; // Computer's run

            printf("Guess the computer's run (1-6): ");
            scanf("%d", &userInput);
            printf("Computer guessed: %d\n", computerInput);

            if (userInput < 1 || userInput > 6) {
                printf("Invalid input! Try again.\n");
                i--; // Retry the same ball
                continue;
            }

            if (userInput == computerInput) {
                printf("OUT! Computer is dismissed.\n");
                break;
            } else {
                *totalRuns += computerInput; // Add computer's run
                printf("Computer not out! Runs so far: %d\n", *totalRuns);
            }
        }
    }
}

int main() {
    srand(time(0)); // Initialize random number generator

    int toss, tossResult, userRuns = 0, computerRuns = 0;
    char choice[5];

       printf("Welcome to the Cricket Game!\n");

    // Toss selection
    printf("Choose Toss (1 for Heads, 2 for Tails): ");
    while (1) {
        scanf("%d", &toss);
        if (toss == 1 || toss == 2) break;
        printf("Invalid input! Please choose 1 for Heads or 2 for Tails: ");
    }

    tossResult = rand() % 2 + 1; // Toss result (1 or 2)
    printf("Toss result: %s\n", tossResult == 1 ? "Heads" : "Tails");

    int userChoice;
    if (toss == tossResult) {
        printf("You won the toss! Choose to (1) Bat or (2) Bowl: ");
        while (1) {
            scanf("%d", &userChoice);
            if (userChoice == 1 || userChoice == 2) {
                if (userChoice == 1) {
                    strcpy(choice, "bat");
                } else {
                    strcpy(choice, "ball");
                }
                break;
            }
            printf("Invalid input! Please choose 1 to bat or 2 to bowl: ");
        }
    } else {
        printf("Computer won the toss.\n");
        if (rand() % 2 == 0) {
            strcpy(choice, "bat");
            printf("Computer chose to bowl first.\n");
        } else {
            strcpy(choice, "ball");
            printf("Computer chose to bat first.\n");
        }
    }


    if (strcmp(choice, "bat") == 0) {
        playInnings("User", &userRuns); // User bats first
        playInnings("Computer", &computerRuns); // Computer bats second
    } else {
        playInnings("Computer", &computerRuns); // Computer bats first
        playInnings("User", &userRuns); // User bats second
    }

    printf("\nMatch Over!\n");
    printf("User's Total Runs: %d\n", userRuns);
    printf("Computer's Total Runs: %d\n", computerRuns);

    if (userRuns > computerRuns) {
        printf("Congratulations! You win the match!\n");
    } else if (userRuns < computerRuns) {
        printf("Computer wins the match! Better luck next time.\n");
    } else {
        printf("The match is tied!\n");
    }

    return 0;
}
