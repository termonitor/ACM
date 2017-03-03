//leetcode 第四十八题
//Rotate Image
/**
将数组顺时针旋转90度，模拟大法好
**/
//rt:3ms

public class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
		int[][] temp = new int[n][n];
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				temp[i][j] = matrix[i][j];
		int loc = 0;
		for(int j=0; j<n; j++) {
			for(int i=n-1; i>=0; i--) {
				matrix[loc/n][loc%n] = temp[i][j];
				loc++;
			}
		}
    }
}