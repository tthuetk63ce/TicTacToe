#include "AI.h"

int AI::win(const int* board) {
    unsigned wins[8][3] = { {0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6} };
    int i;
    for (i = 0; i < 8; ++i) {
        if (board[wins[i][0]] != 0 &&
            board[wins[i][0]] == board[wins[i][1]] && board[wins[i][1]] == board[wins[i][2]])
            return board[wins[i][2]];
    }
    return 0;
}
int AI::minimax(int* board, int isCheck) {
    int winner = win(board);

    if (winner != 0)
        return winner * isCheck;

    int move = -1;
    int score = -2;

    for (int i = 0; i < 9; i++) {

        if (board[i] == 0) {

            board[i] = isCheck;
            int thisScore = - AI::minimax(board, isCheck * -1);

            if (thisScore > score) {
                score = thisScore;
                move = i;
            }
            board[i] = 0;
        }
    }
    if (move == -1)
        return 0;

    return score;
}
int AI::computerMove(int* board) {
    int move = -1;
    int score = -2;

    for (int i = 0; i < 9; ++i) {

        if (board[i] == 0) {
            board[i] = 1;
            int tempScore = - AI::minimax(board, -1);
            board[i] = 0;

            if (tempScore > score) {
                score = tempScore;
                move = i;
            }
        }
    }
    return move;
}