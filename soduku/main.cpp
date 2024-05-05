#include <bits/stdc++.h>
using namespace std;

bool is_valid(vector<vector<int>>& grid, int r, int c, int k) {
    bool not_in_row = true;
    bool not_in_column = true;
    bool not_in_box = true;

    for (int i = 0; i < 9; ++i) {
        if (grid[r][i] == k) {
            not_in_row = false;
            break;
        }
    }

    for (int i = 0; i < 9; ++i) {
        if (grid[i][c] == k) {
            not_in_column = false;
            break;
        }
    }



    for (int i = r / 3 * 3; i < r / 3 * 3 + 3; ++i) {
        for (int j = c / 3 * 3; j < c / 3 * 3 + 3; ++j) {
            if (grid[i][j] == k) {
                not_in_box = false;
                break;
            }
        }
    }

    return not_in_row && not_in_column && not_in_box;
}


bool solve(vector<vector<int>>& grid, int r = 0, int c = 0) {

    if (r == 9) {
        return true;
    } else if (c == 9) {
        return solve(grid, r + 1, 0);
    } else if (grid[r][c] != 0) {
        return solve(grid, r, c + 1);
    } else {
        for (int k = 1; k <= 9; ++k) {
            if (is_valid(grid, r, c, k)) {
                grid[r][c] = k;
                if (solve(grid, r, c + 1)) {
                    return true;
                }
                grid[r][c] = 0;
            }
        }
        return false;
    }
}

void print_grid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

int main() {

    vector<vector<int>> sudoku_grid = {
            {0, 0, 4, 0, 5, 0, 0, 0, 0},
            {9, 0, 0, 7, 3, 4, 6, 0, 0},
            {0, 0, 3, 0, 2, 1, 0, 4, 9},
            {0, 3, 5, 0, 9, 0, 4, 8, 0},
            {0, 9, 0, 0, 0, 0, 0, 3, 0},
            {0, 7, 6, 0, 1, 0, 9, 2, 0},
            {3, 1, 0, 9, 7, 0, 2, 0, 0},
            {0, 0, 9, 1, 8, 2, 0, 0, 3},
            {0, 0, 0, 0, 6, 0, 1, 0, 0}
    };

    if (solve(sudoku_grid)) {
        cout << "Sudoku puzzle solved successfully:" << endl;
        print_grid(sudoku_grid);
    } else {
        cout << "No solution found for the Sudoku puzzle." << endl;
    }



    return 0;
}
