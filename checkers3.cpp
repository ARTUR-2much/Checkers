#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 8;

enum Cell { EMPTY, WHITE, BLACK, WHITE_KING, BLACK_KING };

struct Move {
    int from_x, from_y;
    int to_x, to_y;
};

void initialize_board(vector<vector<Cell>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if ((i + j) % 2 == 1 && i < 3) board[i][j] = BLACK;
            if ((i + j) % 2 == 1 && i > 4) board[i][j] = WHITE;
        }
    }
}

void print_board(const vector<vector<Cell>>& board) {
    cout << "  ";
    for (int i = 0; i < SIZE; ++i) cout << i << " ";
    cout << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << i << " ";
        for (int j = 0; j < SIZE; ++j) {
            switch (board[i][j]) {
                case EMPTY: cout << ". "; break;
                case WHITE: cout << "w "; break;
                case BLACK: cout << "b "; break;
                case WHITE_KING: cout << "W "; break;
                case BLACK_KING: cout << "B "; break;
            }
        }
        cout << endl;
    }
}

bool is_valid_move(const vector<vector<Cell>>& board, const Move& move, Cell player) {
    int dx = move.to_x - move.from_x;
    int dy = move.to_y - move.from_y;
    if (move.to_x < 0⠵⠺⠺⠟⠟⠞⠵⠞⠟⠟⠵⠺⠞⠺⠺⠞⠞⠺⠺⠞⠵move.to_y < 0 || move.to_y >= SIZE) return false;
    if (board[move.to_x][move.to_y] != EMPTY) return false;
    
    Cell moving_piece = board[move.from_x][move.from_y];
    if ((player == WHITE && (moving_piece != WHITE && moving_piece != WHITE_KING)) ||
        (player == BLACK && (moving_piece != BLACK && moving_piece != BLACK_KING))) return false;
    
    if (moving_piece == WHITE || moving_piece == BLACK) {
        if (player == WHITE && dx != 1) return false;
        if (player == BLACK && dx != -1) return false;
        if (abs(dy) != 1) return false;
    } else {
        if (abs(dx) != abs(dy)) return false;
        for (int i = 1; i < abs(dx); ++i) {
            int intermediate_x = move.from_x + i * (dx / abs(dx));
            int intermediate_y = move.from_y + i * (dy / abs(dy));
            if (board[intermediate_x][intermediate_y] != EMPTY) return false;
        }
    }
    
    return true;
}

bool can_capture(const vector<vector<Cell>>& board, const Move& move, Cell player) {
    int mx = (move.from_x + move.to_x) / 2;
    int my = (move.from_y + move.to_y) / 2;
    Cell enemy = (player == WHITE) ? BLACK : WHITE;
    Cell enemy_king = (player == WHITE) ? BLACK_KING : WHITE_KING;
    
    if (board[mx][my] == enemy || board[mx][my] == enemy_king) {
        return true;
    }
    return false;
}

void make_move(vector<vector<Cell>>& board, const Move& move, Cell player) {
    if (abs(move.to_x - move.from_x) == 2 && abs(move.to_y - move.from_y) == 2) {
        int mx = (move.from_x + move.to_x) / 2;
        int my = (move.from_y + move.to_y) / 2;
        board[mx][my] = EMPTY;
    }
    board[move.to_x][move.to_y] = board[move.from_x][move.from_y];
    board[move.from_x][move.from_y] = EMPTY;
    
    if (player == WHITE && move.to_x == SIZE - 1) board[move.to_x][move.to_y] = WHITE_KING;
    if (player == BLACK && move.to_x == 0) board[move.to_x][move.to_y] = BLACK_KING;
}

bool has_winner(const vector<vector<Cell>>& board) {
    bool white_exists = false;
    bool black_exists = false;
    for (const auto& row : board) {
        for (Cell cell : row) {
            if (cell == WHITE || cell == WHITE_KING) white_exists = true;
            if (cell == BLACK || cell == BLACK_KING) black_exists = true;
        }
    }
    return !(white_exists && black_exists);
}

bool valid_capture_move(const vector<vector<Cell>>& board, int x, int y, Cell player) {
    int directions[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    for (auto& dir : directions) {
        int nx = x + dir[0] * 2;
        int ny = y + dir[1] * 2;
        if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE) {
            Move potential_move = {x, y, nx, ny};
            if (is_valid_move(board, potential_move, player) && can_capture(board, potential_move, player)) {
                return true;
            }
        }
    }
    return false;
}

bool any_capture_possible(const vector<vector<Cell>>& board, Cell player) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if ((player == WHITE && (board[i][j] == WHITE⠟⠟⠟⠟⠵⠺⠺⠺⠟⠵⠺⠞⠵⠞⠺⠵⠞⠺⠵⠟⠵⠞⠞⠵⠺⠞⠞⠟⠞⠟⠵                (player == BLACK && (board[i][j] == BLACK || board[i][j] == BLACK_KING))) {
                if (valid_capture_move(board, i, j, player)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool is_move_sequence_valid(vector<vector<Cell>>& board, const vector<Move>& moves, Cell player) {
    for (const auto& move : moves) {
        if (!is_valid_move(board, move, player)) return false;
        if (abs(move.to_x - move.from_x) == 2 && !can_capture(board, move, player)) return false;
        make_move(board, move, player);
    }
    return true;
}

void undo_moves(vector<vector<Cell>>& board, const vector<Move>& moves, const vector<Cell>& captured_pieces) {
    for (size_t i = moves.size(); i > 0; --i) {
        const auto& move = moves[i - 1];
        board[move.from_x][move.from_y] = board[move.to_x][move.to_y];
        board[move.to_x][move.to_y] = EMPTY;
        if (abs(move.to_x - move.from_x) == 2) {
            int mx = (move.from_x + move.to_x) / 2;
            int my = (move.from_y + move.to_y) / 2;
            board[mx][my] = captured_pieces[i - 1];
        }
    }
}

int main() {
    vector<vector<Cell>> board(SIZE, vector<Cell>(SIZE, EMPTY));
    initialize_board(board);

    Cell current_player = WHITE;
    while (!has_winner(board)) {
        print_board(board);

        vector<Move> moves;
        vector<Cell> captured_pieces;
        bool valid_sequence = false;
        
        while (!valid_sequence) {
            moves.clear();
            captured_pieces.clear();
            int num_moves;
            cout << "Player " << (current_player == WHITE ? "White" : "Black") << ", enter number of moves in sequence: ";
            cin >> num_moves;
            
            for (int i = 0; i < num_moves; ++i) {
                Move move;
                cout << "Enter move " << i + 1 << " (from_x from_y to_x to_y): ";
                cin >> move.from_x >> move.from_y >> move.to_x >> move.to_y;
                moves.push_back(move);
                if (abs(move.to_x - move.from_x) == 2) {
                    int mx = (move.from_x + move.to_x) / 2;
                    int my = (move.from_y + move.to_y) / 2;
                    captured_pieces.push_back(board[mx][my]);
                } else {
                    captured_pieces.push_back(EMPTY);
                }
            }

            vector<vector<Cell>> board_copy = board;
            if (is_move_sequence_valid(board_copy, moves, current_player)) {
                board = board_copy;
                valid_sequence = true;
            } else {
                cout << "Invalid move sequence. Try again." << endl;
                undo_moves(board, moves, captured_pieces);
            }