#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<int> board; // board[row] = column index of queen
int solutionCount = 0;

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void solve(int row) {
    if (row == n) {
        // Print the solution
        cout << "Solution " << ++solutionCount << ":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i] == j) cout << "Q ";
                else cout << ". ";
            }
            cout << "\n";
        }
        cout << "\n";
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solve(row + 1);
            // backtrack happens automatically by overwriting board[row] in the next loop
        }
    }
}

int main() {
    cout << "Enter number of queens (n): ";
    cin >> n;

    board.resize(n);
    solve(0);

    if (solutionCount == 0) {
        cout << "No solutions found.\n";
    } else {
        cout << "Total solutions: " << solutionCount << "\n";
    }

    return 0;
}

