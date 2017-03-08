//leetcode 第七十题
//Climbing Stairs
/**
有一个楼梯，每次能向上走一步到两步，总共有n阶，求总共有多少种走法
**/
//rt:0ms

public class Solution {
    public int climbStairs(int n) {
        int[] dp = new int[n+1];
		dp[0] = 1;
		dp[1] = 1;
		for(int i=2; i<=n; i++) {
			dp[i] = dp[i-1] + dp[i-2];
		}
		return dp[n];
    }
}