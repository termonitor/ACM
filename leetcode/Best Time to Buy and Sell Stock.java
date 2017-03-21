//leetcode 第一百二十一题
//Best Time to Buy and Sell Stock
/**
买卖股票，只能买一次卖一次，求最佳结果
**/
//rt:1ms

public class Solution {
    public int maxProfit(int[] prices) {
        int len = prices.length;
        if(len == 0)
            return 0;
        int[] diff = new int[len-1];
        for(int i=0; i<diff.length; i++)
            diff[i] = prices[i+1] - prices[i];
        int max = Integer.MIN_VALUE;
        int sum = 0;
        for(int i=0; i<diff.length; i++) {
            sum += diff[i];
            if(sum > max)
                max = sum;
            if(sum < 0)
                sum = 0;
        }
        return max>0?max:0;
    }
}