#include <stdio.h>
#include <string.h>

#define NUM_BALLS 12

typedef struct {
    int ballScores[NUM_BALLS];
    char playerName[100];
    int totalScore;
} Player;

int validateScore(int score);

void playGame(Player* player) {
    printf("Enter the scores for %s over %d balls:\n", player->playerName, NUM_BALLS);
    player->totalScore = 0;
    
    for (int i = 0; i < NUM_BALLS; i++) {
        int score;
        printf("Ball %d: ", i + 1);
        scanf("%d", &score);

        if (validateScore(score)) {
            player->ballScores[i] = score;
            player->totalScore += score;
        } else {
            printf("Invalid score! Ball marked as 0.\n");
            player->ballScores[i] = 0;
        }
    }
}

int validateScore(int score) {
    if (score >= 0 && score <= 6) {
        return 1;
    }
    return 0;
}

void findWinner(Player player1, Player player2) {
    if (player1.totalScore > player2.totalScore) {
        printf("%s wins with a score of %d!\n", player1.playerName, player1.totalScore);
    } else if (player2.totalScore > player1.totalScore) {
        printf("%s wins with a score of %d!\n", player2.playerName, player2.totalScore);
    } else {
        printf("It's a tie with both players scoring %d!\n", player1.totalScore);
    }
}

void displayMatchScoreboard(Player player1, Player player2) {
    printf("\nMatch Scoreboard:\n");
    printf("\n%s's Performance:\n", player1.playerName);
    for (int i = 0; i < NUM_BALLS; i++) {
        printf("Ball %d: %d\n", i + 1, player1.ballScores[i]);
    }
    printf("Total Score: %d\n", player1.totalScore);
    printf("Average Score: %.2f\n", player1.totalScore / (float)NUM_BALLS);

    printf("\n%s's Performance:\n", player2.playerName);
    for (int i = 0; i < NUM_BALLS; i++) {
        printf("Ball %d: %d\n", i + 1, player2.ballScores[i]);
    }
    printf("Total Score: %d\n", player2.totalScore);
    printf("Average Score: %.2f\n", player2.totalScore / (float)NUM_BALLS);
}

int main() {
    Player player1, player2;

    printf("Enter Player 1's name: ");
    fgets(player1.playerName, sizeof(player1.playerName), stdin);
    player1.playerName[strcspn(player1.playerName, "\n")] = '\0';

    printf("Enter Player 2's name: ");
    fgets(player2.playerName, sizeof(player2.playerName), stdin);
    player2.playerName[strcspn(player2.playerName, "\n")] = '\0';

    playGame(&player1);
    playGame(&player2);

    displayMatchScoreboard(player1, player2);
    findWinner(player1, player2);

    return 0;
}

