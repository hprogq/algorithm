#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 5;

void flip(vector<vector<int> >& board, int x, int y) {
    const int dx[5] = {0, 1, 0, -1, 0};
    const int dy[5] = {0, 0, 1, 0, -1};
    for (int i = 0; i < 5; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE) {
            board[nx][ny] ^= 1;
        }
    }
}

bool isSolved(const vector<vector<int> >& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool solve(vector<vector<int> > board, int row, int col) {
    if (row == SIZE) {
        return isSolved(board);
    }

    int nextRow = (col == SIZE - 1) ? row + 1 : row;
    int nextCol = (col == SIZE - 1) ? 0 : col + 1;

    if (solve(board, nextRow, nextCol)) {
        return true;
    }

    flip(board, row, col);
    if (solve(board, nextRow, nextCol)) {
        cout << "Flip at (" << row << ", " << col << ")" << endl;
        return true;
    }

    return false;
}

int main() {
    vector<vector<int> > board(SIZE);

    // Initialize the board
    int init[SIZE][SIZE] = {
        {0, 1, 0, 1, 1},
        {1, 0, 1, 1, 0},
        {1, 0, 1, 0, 0},
        {0, 0, 0, 1, 1},
        {1, 1, 0, 1, 1}
    };

    for (int i = 0; i < SIZE; ++i) {
        board[i] = vector<int>(init[i], init[i] + SIZE);
    }

    if (!solve(board, 0, 0)) {
        cout << "No solution found." << endl;
    }

    return 0;
}
