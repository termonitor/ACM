//leetcode 第七十二题
//Edit Distance
/**
https://leetcode.com/problems/edit-distance/?tab=Description
给两个字符串，有三种方式可以调整其中一个字符串，(1)插入一个字符。(2)删除一个字符。(3)替换一个字符。求问总共有多少种方式使得两个字符串变的相等
dp问题
**/
//rt:11ms

public class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length();
		int n = word2.length();
		int[][] dp = new int[m+1][n+1];
		for(int i=1; i<=m; i++)
			dp[i][0] = i;
		for(int j=1; j<=n; j++)
			dp[0][j] = j;
		for(int i=1; i<=m; i++) {
			for(int j=1; j<=n; j++) {
				if(word1.charAt(i-1) == word2.charAt(j-1))
					dp[i][j] = dp[i-1][j-1];
				else
					dp[i][j] = Math.min(dp[i-1][j-1]+1, Math.min(dp[i-1][j]+1, dp[i][j-1]+1));
			}
		}
		return dp[m][n];
    }
}