//leetcode 第三十七题
//Valid Sudoku
/**
解数独
**/
//rt:20ms

//两种解法，第一种较快，用的是递归的方法
public class Solution {
    private Set<Character> set = new HashSet<Character>();
    
    public void solveSudoku(char[][] board) {
        sudokuRecursion(board, 0, 0, 0);
    }
    
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
    
    public boolean sudokuRecursion(char[][] board, int x, int y, int depth) {
    	if (depth == 81) {
    		if (isValidSudoku(board))
    			return true;
    		else {
    		    set.clear();
    			return false;
    		}
    	}
    	//如果填过了，直接下一个
    	if(board[x][y] != '.') {
    		depth++;
    		boolean result = sudokuRecursion(board, depth/9, depth%9, depth);
    		depth--;
    		if(result)
    			return true;
    		return false;
    	}
    	depth++;
    	for (char c='1'; c<='9'; c++) {
    		//这里先判断是否合适，再填进去，比直接填进去试错大大提高了效率，也算是剪枝的一种方式吧
    		if(isValid(board, x, y, c)) {
	    		board[x][y] = c;
	    		boolean result = sudokuRecursion(board, depth/9, depth%9, depth);
	    		if(result)
	    			return true;
	    		else
	    		    board[x][y] = '.';
    		}
    	}
    	depth--;
    	return false;
    }
    
    public boolean isValid(char[][] board, int row, int col, char c) {
    	for (int i=0; i<9; i++) {
    		if (board[i][col] != '.' && board[i][col] == c) return false;
    		if (board[row][i] != '.' && board[row][i] == c) return false;
    		if (board[3*(row/3)+i/3][3*(col/3)+i%3] != '.' && board[3*(row/3)+i/3][3*(col/3)+i%3] == c) return false;
    	}
    	return true;
    }
}


//rt:26ms
//第二种本质上也是一种递归，只不过方式不同，但是时间效率上有一些差别
public class Solution {
    private Set<Character> set = new HashSet<Character>();
    
    public void solveSudoku(char[][] board) {
        sudokuRecursion(board, 0, 0, 0);
    }
    
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
    
    public boolean sudokuRecursion(char[][] board, int x, int y, int depth) {
    	if (depth == 81) {
    		if (isValidSudoku(board))
    			return true;
    		else {
    		    set.clear();
    			return false;
    		}
    	}
    	//如果填过了，直接下一个
    	if(board[x][y] != '.') {
    		depth++;
    		boolean result = sudokuRecursion(board, depth/9, depth%9, depth);
    		depth--;
    		if(result)
    			return true;
    		return false;
    	}
    	depth++;
    	for (char c='1'; c<='9'; c++) {
    		//这里先判断是否合适，再填进去，比直接填进去试错大大提高了效率，也算是剪枝的一种方式吧
    		if(isValid(board, x, y, c)) {
	    		board[x][y] = c;
	    		boolean result = sudokuRecursion(board, depth/9, depth%9, depth);
	    		if(result)
	    			return true;
	    		else
	    		    board[x][y] = '.';
    		}
    	}
    	depth--;
    	return false;
    }
    
    public boolean isValid(char[][] board, int row, int col, char c) {
    	for (int i=0; i<9; i++) {
    		if (board[i][col] != '.' && board[i][col] == c) return false;
    		if (board[row][i] != '.' && board[row][i] == c) return false;
    		if (board[3*(row/3)+i/3][3*(col/3)+i%3] != '.' && board[3*(row/3)+i/3][3*(col/3)+i%3] == c) return false;
    	}
    	return true;
    }
}