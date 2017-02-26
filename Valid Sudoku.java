//leetcode 第三十六题
//Valid Sudoku
/**
证明一个数独当前的状态是合法的。
**/
//rt:49ms

public class Solution {
    private Set<Character> set = new HashSet<Character>(); 
    
    public boolean check(char word) {
    	if (word == '.')
    		return true;
    	else if (word>='1' && word<='9') {
    		if(set.contains(word))
    			return false;
    		else {
    			set.add(word);
    			return true;
    		}
    	}
    	return false;
    }
    
    public boolean isValidSudoku(char[][] board) {
        for (int i=0; i<9; i++) {
    		for (int j=0; j<9; j++) {
    			if (!check(board[i][j]))
    				return false;
    		}
    		set.clear();
    	}
    	for (int i=0; i<9; i++) {
    		for (int j=0; j<9; j++) {
    			if (!check(board[j][i]))
    				return false;
    		}
    		set.clear();
    	}
    	for (int i=0; i<9; i++) {
    		for (int j=0; j<9; j++) {
    			if (!check(board[i/3*3+j/3][i%3*3+j%3]))
    				return false;
    		}
    		set.clear();
    	}
    	return true;
    }
}