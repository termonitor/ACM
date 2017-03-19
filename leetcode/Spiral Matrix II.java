//leetcode 第五十九题
//Spiral Matrix II
/**
给一个数字n，以螺旋的方式输出n*n的数字的数组
**/
//rt:3ms

public class Solution {
    public int[][] generateMatrix(int n) {
        int[][] matrix = new int[n][n];
		int rowBegin = 0;
		int rowEnd = n-1;
		int colBegin = 0;
		int colEnd = n-1;
		int num = 1;
		while(rowBegin<=rowEnd && colBegin<=colEnd) {
			//Traverse Right
			for(int i=colBegin; i<=colEnd; i++) {
				matrix[rowBegin][i] = num;
				num++;
			}
			rowBegin++;
			
			//Traverse Down
			for(int i=rowBegin; i<=rowEnd; i++) {
				matrix[i][colEnd] = num;
				num++;
			}
			colEnd--;
			
			//Traverse Left
			if(rowBegin <= rowEnd) {
				for(int i=colEnd; i>=colBegin; i--) {
					matrix[rowEnd][i] = num;
					num++;
				}
			}
			rowEnd--;
			
			//Traverse Up
			if(colBegin <= colEnd) {
				for(int i=rowEnd; i>=rowBegin; i--) {
					matrix[i][colBegin] = num;
					num++;
				}
			}
			colBegin++;
			
		}
		return matrix;
    }
}