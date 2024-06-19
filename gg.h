/**
 * \file gg.h
 * \brief ��������� ��� ���� � ����� � �������������� ���������� SFML.
 */

#include <SFML/Graphics.hpp>
#include <iostream>

const int size = 8; ///< ������ ����� 8x8
const int cellSize = 100; ///< ������ ����� ������

/// ���� ����������
sf::RenderWindow window(sf::VideoMode(size* cellSize, size* cellSize), "Checkers");

/// ���� ����� �� �����.
enum Piece {
    EMPTY, ///< ������ ������
    BLACK, ///< ������ �����
    WHITE, ///< ����� �����
    BLACK_KING, ///< ������ ����� (�����)
    WHITE_KING ///< ����� ����� (�����)
};
Piece board[size][size]; ///< ������� �����

/// ����������� �����.
enum Turn {
    BLACK_TURN, ///< ��� ������
    WHITE_TURN ///< ��� �����
};
Turn currentTurn = WHITE_TURN; ///< ������� ������� ����

/**
 * \brief ������������� ���������� ��������� �����.
 */
void initBoard() {
    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            if (y < 3 && (x + y) % 2 == 1) {
                board[y][x] = BLACK;
            }
            else if (y > 4 && (x + y) % 2 == 1) {
                board[y][x] = WHITE;
            }
            else {
                board[y][x] = EMPTY;
            }
        }
    }
}

/**
 * \brief ��������� ������� ����� � �����.
 * \param selectedX ���������� X ��������� ������ (�� ��������� -1)
 * \param selectedY ���������� Y ��������� ������ (�� ��������� -1)
 */
void drawBoard(int selectedX = -1, int selectedY = -1) {
    sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            cell.setFillColor((x + y) % 2 == 0 ? sf::Color::White : sf::Color::Black);
            cell.setPosition(x * cellSize, y * cellSize);
            window.draw(cell);

            if (x == selectedX && y == selectedY) {
                sf::RectangleShape highlight(sf::Vector2f(cellSize - 3, cellSize - 3));
                highlight.setFillColor(sf::Color::Transparent);
                highlight.setOutlineColor(sf::Color::Red);
                highlight.setOutlineThickness(3);
                highlight.setPosition(x * cellSize, y * cellSize);
                window.draw(highlight);
            }

            if (board[y][x] != EMPTY) {
                sf::CircleShape piece(cellSize / 2 - 10);
                piece.setPosition(x * cellSize + 10, y * cellSize + 10);
                switch (board[y][x]) {
                case BLACK:
                    piece.setFillColor(sf::Color::Yellow);
                    break;
                case WHITE:
                    piece.setFillColor(sf::Color::White);
                    break;
                case BLACK_KING:
                    piece.setFillColor(sf::Color::Yellow);
                    piece.setOutlineColor(sf::Color::Blue);
                    piece.setOutlineThickness(5);
                    break;
                case WHITE_KING:
                    piece.setFillColor(sf::Color::White);
                    piece.setOutlineColor(sf::Color::Blue);
                    piece.setOutlineThickness(5);
                    break;
                default:
                    break;
                }
                window.draw(piece);
            }
        }
    }
}

/**
 * \brief �������� ���������� ���� ������������ ������� �����.
 * \return ���������� ������ � ������� sf::Vector2i.
 */
sf::Vector2i getMousePositionOnBoard() {
    sf::Vector2i pos = sf::Mouse::getPosition(window);
    return sf::Vector2i(pos.x / cellSize, pos.y / cellSize);
}

/**
 * \brief ���������, �������� �� ��� ��������.
 * \param fromX ���������� X ��������� ������
 * \param fromY ���������� Y ��������� ������
 * \param toX ���������� X �������� ������
 * \param toY ���������� Y �������� ������
 * \param isCapture ������ �� ����������, �����������, �������� �� ��� ��������
 * \return true, ���� ��� ��������, ����� false.
 */
bool isValidMove(int fromX, int fromY, int toX, int toY, bool& isCapture) {
    isCapture = false;
    if (toX < 0 || toX >= size || toY < 0 || toY >= size) return false;
    if (board[toY][toX] != EMPTY) return false;

    Piece piece = board[fromY][fromX];
    int dx = toX - fromX;
    int dy = toY - fromY;

    if (piece == BLACK || piece == WHITE) {
        if (abs(dx) == 1 && abs(dy) == 1) {
            if ((piece == BLACK && dy == 1) || (piece == WHITE && dy == -1)) {
                return true;
            }
        }
        else if (abs(dx) == 2 && abs(dy) == 2) {
            int midX = (fromX + toX) / 2;
            int midY = (fromY + toY) / 2;
            if (board[midY][midX] != EMPTY && board[midY][midX] != piece && board[midY][midX] != (piece == BLACK ? BLACK_KING : WHITE_KING)) {
                isCapture = true;
                return true;
            }
        }
    }
    else if (piece == BLACK_KING || piece == WHITE_KING) {
        if (abs(dx) == abs(dy)) {
            bool captureFound = false;
            int capturedPieces = 0;
            for (int i = 1; i < abs(dx); ++i) {
                int midX = fromX + i * (dx / abs(dx));
                int midY = fromY + i * (dy / abs(dy));
                if (board[midY][midX] != EMPTY) {
                    if (!captureFound && ((piece == BLACK_KING && (board[midY][midX] == WHITE || board[midY][midX] == WHITE_KING)) ||
                        (piece == WHITE_KING && (board[midY][midX] == BLACK || board[midY][midX] == BLACK_KING)))) {
                        captureFound = true;
                        ++capturedPieces;
                    }
                    else {
                        return false;
                    }
                }
            }
            isCapture = captureFound && capturedPieces == 1;
            return true;
        }
    }
    return false;
}

/**
 * \brief ���������, ����� �� ������ ��������� ������ ������.
 * \param x ���������� X ������
 * \param y ���������� Y ������
 * \return true, ���� ������ ����� ���������, ����� false.
 */
bool canCapture(int x, int y) {
    Piece piece = board[y][x];
    for (int dx = -2; dx <= 2; dx += 4) {
        for (int dy = -2; dy <= 2; dy += 4) {
            bool isCapture;
            if (isValidMove(x, y, x + dx, y + dy, isCapture) && isCapture) {
                return true;
            }
        }
    }
    return false;
}

/**
 * \brief ���������, ���������� �� ������.
 * \return true, ���� ������ ����������, ����� false.
 */
bool mustCapture() {
    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            if ((currentTurn == WHITE_TURN && (board[y][x] == WHITE || board[y][x] == WHITE_KING)) ||
                (currentTurn == BLACK_TURN && (board[y][x] == BLACK || board[y][x] == BLACK_KING))) {
                if (canCapture(x, y)) {
                    return true;
                }
            }
        }
    }
    return false;
}

/**
 * \brief ��������� ��� ������.
 * \param fromX ���������� X ��������� ������
 * \param fromY ���������� Y ��������� ������
 * \param toX ���������� X �������� ������
 * \param toY ���������� Y �������� ������
 * \param isCapture ���������, �������� �� ��� ��������
 */
void makeMove(int fromX, int fromY, int toX, int toY, bool isCapture) {
    Piece piece = board[fromY][fromX];
    board[toY][toX] = piece;
    board[fromY][fromX] = EMPTY;

    if (isCapture) {
        int dx = (toX - fromX) / abs(toX - fromX);
        int dy = (toY - fromY) / abs(toY - fromY);
        for (int i = 1; i < abs(toX - fromX); ++i) {
            int midX = fromX + i * dx;
            int midY = fromY + i * dy;
            if (board[midY][midX] != EMPTY) {
                board[midY][midX] = EMPTY;
            }
        }
    }

    if (piece == BLACK && toY == size - 1) {
        board[toY][toX] = BLACK_KING;
    }
    else if (piece == WHITE && toY == 0) {
        board[toY][toX] = WHITE_KING;
    }
}
