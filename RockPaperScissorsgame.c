#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printChoices() {
    printf("\nChoose:\n");
    printf("1. Rock\n");
    printf("2. Paper\n");
    printf("3. Scissors\n");
    printf("Enter your choice (1-3): ");
}

const char* getChoiceName(int choice) {
    switch (choice) {
        case 1: return "Rock";
        case 2: return "Paper";
        case 3: return "Scissors";
        default: return "Invalid";
    }
}

void determineWinner(int user, int computer) {
    printf("\nYou chose: %s", getChoiceName(user));
    printf("\nComputer chose: %s\n", getChoiceName(computer));

    if (user == computer) {
        printf("🎯 It's a draw!\n");
    } else if ((user == 1 && computer == 3) ||
               (user == 2 && computer == 1) ||
               (user == 3 && computer == 2)) {
        printf("✅ You win!\n");
    } else {
        printf("❌ Computer wins!\n");
    }
}

int main() {
    int userChoice, computerChoice;
    char playAgain;

    srand(time(NULL)); // Seed random number

    printf("===== Rock Paper Scissors Game =====\n");

    do {
        printChoices();
        scanf("%d", &userChoice);

        if (userChoice < 1 || userChoice > 3) {
            printf("Invalid input! Please enter 1, 2 or 3.\n");
            continue;
        }

        computerChoice = (rand() % 3) + 1;

        determineWinner(userChoice, computerChoice);

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing! ✌️\n");

    return 0;
}


