//leetcode 第六十三题
//Unique Paths II
/**
假设有一个二维数组，左上角是起点，右下角是重点，求有多少种独一无二的路径，与上一题不同的是这次中间加了障碍。
**/
//rt:1ms

public class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if(obstacleGrid[0][0] == 1)
			return 0;
        int m = obstacleGrid.length;
		int n = obstacleGrid[0].length;
		if(obstacleGrid[m-1][n-1] == 1)
			return 0;
		int[][] dp = new int[m][n];
		dp[0][0] = 1;
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				if(obstacleGrid[i][j] == 1)
					dp[i][j] = -1;
			}
		}
		boolean flag = false;
		for(int i=1; i<n; i++) {
			if(dp[0][i] == -1 || flag) {
				dp[0][i] = 0;
				flag = true;
				continue;
			}
			dp[0][i] = 1;
		}
		flag = false;
		for(int i=1; i<m; i++) {
			if(dp[i][0] == -1 || flag) {
				dp[i][0] = 0;
				flag = true;
				continue;
			}
			dp[i][0] = 1;
		}
		for(int i=1; i<m; i++) {
			for(int j=1; j<n; j++) {
				if(dp[i][j] == -1) {
					dp[i][j] = 0;
					continue;
				}
				dp[i][j] = dp[i][j-1] + dp[i-1][j];
					
			}
		}
		return dp[m-1][n-1];
    }
}



//一种更简单的dp方式
//rt:1ms

public class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int width = obstacleGrid[0].length;
		int[] dp = new int[width];
		dp[0] = 1;
		for(int[] row : obstacleGrid) {
			for(int i=0; i<width; i++) {
				if(row[i] == 1)
					dp[i] = 0;
				else if(i > 0)
					dp[i] += dp[i-1];
			}
		}
		return dp[width-1];
    }
}