
class Solution {
    public void solveSudoku(char[][] board) {
        solve(board, 0, 0);
    }

    public boolean solve(char[][] board, int row, int col) {
        if (row == 9) {
            return true;
        }

        if (col == 9) {
            return solve(board, row + 1, 0);
        }

        if (board[row][col] != '.') {
            return solve(board, row, col + 1);
        }

        for (char num = '1'; num <= '9'; num++) {
            if (isValid(board, row, col, num)) {
                board[row][col] = num;

                if (solve(board, row, col + 1)) {
                    return true;
                }

                board[row][col] = '.';
            }
        }

        return false;
    }

    public boolean isValid(char[][] board, int row, int col, char num) {

        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num) {
                return false;
            }

            if (board[i][col] == num) {
                return false;
            }
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == num) {
                    return false;
                }
            }
        }

        return true;
    }
}
