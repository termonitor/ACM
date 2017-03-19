//leetcode 第六十四题
//Minimum Path Sum
/**
给一个m*n大小的非负数组，计算从左上角到右下角的最短路径
**/
//rt:4ms

public class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
		int n = grid[0].length;
		int[][] dp = new int[m][n];
		dp[0][0] = grid[0][0];
		for(int i=1; i<n; i++) {
			dp[0][i] = dp[0][i-1] + grid[0][i];
		}
		for(int i=1; i<m; i++) {
			dp[i][0] = dp[i-1][0] + grid[i][0];
		}
		for(int i=1; i<m; i++) {
			for(int j=1; j<n; j++) {
				dp[i][j] = Math.min(dp[i][j-1], dp[i-1][j]) + grid[i][j];
			}
		}
		return dp[m-1][n-1];
    }
}