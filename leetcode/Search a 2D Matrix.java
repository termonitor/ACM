//leetcode 第七十四题
//Search a 2D Matrix
/**
在一个有规律的二维数组，以最快的方式查找某一个数
两种解法，一样的结果
**/
//rt:1ms

public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix.length == 0)
			return false;
		int i=0, j=matrix[0].length-1;
		while(i<matrix.length && j>=0) {
			if(matrix[i][j] == target) 
				return true;
			else if(matrix[i][j] > target)
				j--;
			else
				i++;
		}
		return false;
    }
}


public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int rows = matrix.length;
        if(rows == 0)
			return false;
		int cols = matrix[0].length;
		if(cols == 0)
			return false;
		int i;
		for(i=0; i<rows; i++) {
			if(matrix[i][0] > target)
				break;
		}
		if(i == 0)
			return false;
		for(int j=0; j<cols; j++) {
			if(matrix[i-1][j] == target)
				return true;
			if(matrix[i-1][j] > target)
				return false;
		}
		return false;
    }
}