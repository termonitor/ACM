//leetcode 第一百三十题
//Surrounded Regions
/**
一个二维数组，里面包含着X和O两种字符，找出所有被X包围的O，并转换为X
**/
//rt:4ms

public class Solution {
    public void solve(char[][] board) {
        int row = board.length;
        if(row == 0)
            return;
        int col = board[0].length;
        for(int i=0; i<row; i++) {
            check(board, i, 0, row, col);
            if(col > 1)
                check(board, i, col-1, row, col);
        }
        for(int i=1; i+1<col; i++) {
            check(board, 0, i, row, col);
            if(row > 1)
                check(board, row-1, i, row, col);
        }
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                if(board[i][j] == '1')
                    board[i][j] = 'O';
    }
    
    private void check(char[][] board, int x, int y, int row, int col) {
        if(board[x][y] == 'O') {
            board[x][y] = '1';
            if(x > 1)
                check(board, x-1, y, row, col);
            if(y > 1)
                check(board, x, y-1, row, col);
            if(x+1 < row)
                check(board, x+1, y, row, col);
            if(y+1 < col)
                check(board, x, y+1, row, col);
        }
    }
}