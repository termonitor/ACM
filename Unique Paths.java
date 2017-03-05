//leetcode 第六十二题
//Unique Paths
/**
假设有一个二维数组，左上角是起点，右下角是重点，求有多少种独一无二的路径
**/
//rt:1ms

public class Solution {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];
		dp[0][0] = 1;
		for(int i=1; i<n; i++)
			dp[0][i] = 1;
		for(int i=1; i<m; i++)
			dp[i][0] = 1;
		for(int i=1; i<m; i++) {
			for(int j=1; j<n; j++) {
				dp[i][j] = dp[i][j-1] + dp[i-1][j];
			}
		}
		return dp[m-1][n-1];
    }
}



//数学公式解法，论数学的威力
//rt:1ms以内
public class Solution {
    public int uniquePaths(int m, int n) {
        int N = n + m - 2;
		int k = m - 1;
		double res = 1;
		for(int i=1; i<=k; i++) {
			res = res*(N-k+i)/i;
		}
		return (int)res;
    }
}