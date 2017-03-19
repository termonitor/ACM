//leetcode 第三十三题
//Search in Rotated Sorted Array
/**
给一个无序不重复的数组，找出其中一个数字的位置。。。
**/
//rt:15ms

public class Solution {
    public int search(int[] nums, int target) {
        
        for(int i=0; i<nums.length; i++) {
    		if(nums[i] == target)
    			return i;
    	}
        return -1;
    }
}