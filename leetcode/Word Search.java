//leetcode 第七十九题
//Word Search
/**
给一个二维数组，采用贪吃蛇的方式寻找字母，直到组成所要求的字符串，能够找到则返回true，否则false
**/
//rt:12ms

public class Solution {
    public boolean exist(char[][] board, String word) {
        char[] words = word.toCharArray();
		for(int i=0; i<board.length; i++) {
			for(int j=0; j<board[i].length; j++) {
				if(exist(board, i, j, words, 0))
					return true;
			}
		}
		return false;
    }
    
    public boolean exist(char[][] board, int x, int y, char[] words, int i) {
		if(i == words.length)
			return true;
		if(x<0 || y<0 || x==board.length || y==board[x].length)
			return false;
		if(board[x][y] != words[i])
			return false;
		board[x][y] ^= 256;
		boolean exist = exist(board, x, y+1, words, i+1) ||
				exist(board, x, y-1, words, i+1) ||
				exist(board, x+1, y, words, i+1) ||
				exist(board, x-1, y, words, i+1);
		board[x][y] ^= 256;
		return exist;
	}
}