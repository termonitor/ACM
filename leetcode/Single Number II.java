//leetcode 第一百三十七题
//Single Number II
/**
给一组数字，每个数字出现三次，求中间只出现一次的数字
**/
//rt:1ms

public class Solution {
    public int singleNumber(int[] nums) {
        int ones = 0, twos = 0;
        for(int num : nums) {
            ones = (ones^num) & ~twos;
            twos = (twos^num) & ~ones;
        }
        return ones;
    }
}