#include <SFML/Graphics.hpp>
#include <iostream>
#include "gg.h"


int main() {
    initBoard();
    bool isMoving = false;
    int fromX, fromY;
    bool hasCaptured = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i pos = getMousePositionOnBoard();
                if (pos.x >= 0 && pos.x < size && pos.y >= 0 && pos.y < size) {
                    if (!isMoving && board[pos.y][pos.x] != EMPTY) {
                        if ((currentTurn == WHITE_TURN && (board[pos.y][pos.x] == WHITE || board[pos.y][pos.x] == WHITE_KING)) ||
                            (currentTurn == BLACK_TURN && (board[pos.y][pos.x] == BLACK || board[pos.y][pos.x] == BLACK_KING))) {
                            isMoving = true;
                            fromX = pos.x;
                            fromY = pos.y;
                            hasCaptured = false;
                        }
                    }
                    else if (isMoving) {
                        sf::Vector2i newPos = getMousePositionOnBoard();
                        bool isCapture = false;
                        if (isValidMove(fromX, fromY, newPos.x, newPos.y, isCapture)) {
                            makeMove(fromX, fromY, newPos.x, newPos.y, isCapture);
                            isMoving = false;
                            if (isCapture) {
                                if (canCapture(newPos.x, newPos.y)) {
                                    fromX = newPos.x;
                                    fromY = newPos.y;
                                    isMoving = true;
                                    hasCaptured = true;
                                }
                                else {
                                    hasCaptured = false;
                                }
                            }
                            if (!hasCaptured) {
                                currentTurn = (currentTurn == WHITE_TURN) ? BLACK_TURN : WHITE_TURN;
                            }
                        }
                        else {
                            isMoving = false;
                        }
                    }
                }
            }
        }

        window.clear();
        drawBoard(isMoving ? fromX : -1, isMoving ? fromY : -1);
        window.display();
    }

    return 0;
}
