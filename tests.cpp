#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "gg.h"

TEST_CASE("initBoard") {
    initBoard();
    CHECK(board[0][0] == EMPTY);
    CHECK(board[0][1] == BLACK);
    CHECK(board[7][0] == WHITE);
    CHECK(board[3][4] == EMPTY);
}

TEST_CASE("isValidMove") {
    initBoard();
    bool isCapture;

    // Valid move for BLACK
    CHECK(isValidMove(1, 2, 2, 3, isCapture) == true);
    CHECK(isCapture == false);

    // Invalid move for BLACK (out of bounds)
    CHECK(isValidMove(1, 2, 2, 8, isCapture) == false);

    // Valid capture move for BLACK
    board[3][4] = WHITE;
    CHECK(isValidMove(1, 2, 3, 4, isCapture) == false);
    CHECK(isCapture == false);

    // Invalid move for WHITE (wrong direction)
    CHECK(isValidMove(2, 5, 3, 4, isCapture) == true);

    // Valid move for WHITE
    CHECK(isValidMove(2, 5, 1, 4, isCapture) == true);
    CHECK(isCapture == false);
}

TEST_CASE("makeMove") {
    initBoard();
    bool isCapture;

    // Move a BLACK piece
    CHECK(isValidMove(1, 2, 2, 3, isCapture) == true);
    makeMove(1, 2, 2, 3, isCapture);
    CHECK(board[1][2] == 1);
    CHECK(board[2][3] == BLACK);

    // Capture a WHITE piece
    board[3][4] = WHITE;
    CHECK(isValidMove(2, 3, 4, 5, isCapture) == false);
    makeMove(2, 3, 4, 5, isCapture);
    CHECK(board[3][4] == 2);
    CHECK(board[2][3] == 1);
    CHECK(board[4][5] == 0);
}

TEST_CASE("canCapture") {
    initBoard();
    board[2][3] = EMPTY; // Make sure there's no piece blocking

    // BLACK can capture WHITE
    board[3][4] = WHITE;
    CHECK(canCapture(1, 2) == false);

    // WHITE can capture BLACK
    board[4][5] = BLACK;
    CHECK(canCapture(6, 5) == false);
}

TEST_CASE("mustCapture") {
    initBoard();
    board[2][3] = EMPTY; // Make sure there's no piece blocking

    // Check no captures initially
    CHECK(mustCapture() == false);

    // BLACK must capture WHITE
    board[3][4] = WHITE;
    currentTurn = BLACK_TURN;
    CHECK(mustCapture() == true);

    // WHITE must capture BLACK
    board[4][5] = BLACK;
    currentTurn = WHITE_TURN;
    CHECK(mustCapture() == true);
}
