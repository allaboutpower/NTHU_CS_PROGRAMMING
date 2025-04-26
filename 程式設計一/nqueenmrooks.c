#include <stdio.h>
#define size n+m 
int board[14][14];
int n, m; // n queens, m rooks, size = board size
int ans;

int ok(int row, int col) {
    return board[row][col] == 0;
}

void mark(int row, int col, int diff, int isQueen) {
    for (int i = 0; i < size; i++) board[i][col] += diff; // same column
    if (isQueen) {
        for (int i = 0; row + i < size && col + i < size; i++) board[row + i][col + i] += diff;
        for (int i = 0; row + i < size && col - i >= 0; i++) board[row + i][col - i] += diff;
    }
}

void solve(int row, int qcnt, int rcnt) {
    if (row == size) {
        if (qcnt == n && rcnt == m) ans++;
        return;
    }

    for (int col = 0; col < size; col++) {
        if (ok(row, col)) {
            // Try place Queen
            if (qcnt < n) {
                mark(row, col, 1, 1);
                solve(row + 1, qcnt + 1, rcnt);
                mark(row, col, -1, 1);
            }
            // Try place Rook
            if (rcnt < m) {
                mark(row, col, 1, 0);
                solve(row + 1, qcnt, rcnt + 1);
                mark(row, col, -1, 0);
            }
        }
    }
    // Also try skipping this row (optional if total N + M < size)
}

int main() {
    scanf("%d %d", &size, &n, &m); // size of board, n queens, m rooks
    ans = 0;
    solve(0, 0, 0);
    printf("%d\n", ans);
    return 0;
}
