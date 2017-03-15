//leetcode 第九十一题
//Decode Ways
/**
每个字母可以解析为对应的1-26个数字，12有可能解析为AB，也有可能解析为L(12)，给一串数字，求有多少种解析方式
dp问题
**/
//rt:5ms

public class Solution {
    public int numDecodings(String s) {
        int n = s.length();
        if(n == 0)
            return 0;
        int[] memo = new int[n+1];
        memo[n] = 1;
        memo[n-1] = s.charAt(n-1)!='0'?1:0;
        for(int i=n-2; i>=0; i--) {
            if(s.charAt(i) == '0')
                continue;
            else
                memo[i] = (Integer.parseInt(s.substring(i, i+2))<=26)?memo[i+1]+memo[i+2]:memo[i+1];
        }
        return memo[0];
    }
}