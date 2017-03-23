//leetcode 第一百二十二题
//Best Time to Buy and Sell Stock II
/**
买卖股票，可以多次交易，求最佳结果
**/
//rt:1ms

public class Solution {
    public int maxProfit(int[] prices) {
        int total = 0;
        for(int i=0; i<prices.length-1; i++)
            if(prices[i+1] > prices[i])
                total += prices[i+1] - prices[i];
        return total;
    }
}