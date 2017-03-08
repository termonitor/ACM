//leetcode 第七十三题
//Set Matrix Zeroes
/**
给一个M*N大小的二维数组，如果其中某一个位置上的数字为0，则另该行该列整个变为0
实现的方式有很多，求最小额外空间大小的方式，最佳方式的空间复杂度为O(1)
**/
//rt:1ms

public class Solution {
    public void setZeroes(int[][] matrix) {
        int col0 = 1;
		int rows = matrix.length;
		int cols = matrix[0].length;
		for(int i=0; i<rows; i++) {
			if(matrix[i][0] == 0)
				col0 = 0;
			for(int j=1; j<cols; j++) {
				if(matrix[i][j] == 0)
					matrix[i][0] = matrix[0][j] = 0;
			}
		}
		for(int i=rows-1; i>=0; i--) {
			for(int j=cols-1; j>=1; j--) {
				if(matrix[i][0]==0 || matrix[0][j]==0)
					matrix[i][j] = 0;
			}
			if(col0 == 0)
				matrix[i][0] = 0;
		}
    }
}