//leetcode 第四十一题
//First Missing Positive
/**
给一个数组，求第一个不存在的正整数。
思路：假设数组对应下标存放对应的正整数，也就是说a[0]=1,a[1]=2，这样进行交换，从头到尾遍历一遍即可知道第一个不存在的数字是啥。
**/
//rt:13ms

public class Solution {
    public int firstMissingPositive(int[] nums) {
        int i = 0;
        while(i < nums.length) {
            if(nums[i]==i+1 || nums[i]<=0 || nums[i]>nums.length)
                i++;
            else if(nums[nums[i]-1] != nums[i])
                swap(nums, i, nums[i]-1);
            else
                i++;
        }
        i = 0;
        while(i<nums.length && nums[i]==i+1)
            i++;
        return i+1;
    }
    
    public void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}