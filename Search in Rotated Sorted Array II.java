//leetcode 第八十一题
//Search in Rotated Sorted Array II
/**
在一个循环数组中查找某一个目标字符，找到就返回true，否则false
**/
//rt:1ms

public class Solution {
    public boolean search(int[] nums, int target) {
        for(int i=0; i<nums.length; i++) {
            if(nums[i] == target)
                return true;
        }
        return false;
    }
}