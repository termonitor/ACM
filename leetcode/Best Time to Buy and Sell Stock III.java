//leetcode 第一百二十一题
//Best Time to Buy and Sell Stock III
/**
买卖股票，可以多次交易，求最佳结果，只允许交易两次
**/
//rt:6ms

public class Solution {
    public int maxProfit(int[] prices) {
        int hold1 = Integer.MIN_VALUE, hold2 = Integer.MIN_VALUE;
        int release1 = 0, release2 = 0;
        for(int i : prices) {
            release2 = Math.max(release2, hold2+i);
            hold2 = Math.max(hold2, release1-i);
            release1 = Math.max(release1, hold1+i);
            hold1 = Math.max(hold1, -i);
        }
        return release2;
    }
}