//leetcode 第一百三十六题
//Single Number
/**
给一组数字，每个数字出现两次，求中间只出现一次的数字
**/
//rt:2ms

public class Solution {
    public int singleNumber(int[] nums) {
        int res = 0;
        for(int num : nums) {
            res ^= num;
        }
        return res;
    }
}