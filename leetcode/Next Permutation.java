//leetcode 第三十一题
//Next Permutation
/**
给一串数字，求出该串数字的下一个字典序列
**/
//rt:22ms

public class Solution {
    public void nextPermutation(int[] nums) {
        if (nums == null || nums.length == 0 || nums.length == 1)
            return;
        //从后向前找到第一个不满足逆序的元素
        int i = nums.length - 2;
        for (; i>=0 && nums[i]>=nums[i+1]; i--);
        if(i >= 0) {
            //从i+1位置开始，向后查找比nums[i]大的最小元素
            int j = i + 1;
            for(; j<nums.length && nums[j]>nums[i]; j++);
            swap(nums, i, j-1);
        }
        //将i之后的元素逆置(这里包含一种特殊情况，若该排列已经是字典序中的最大了，则下一个序列应该是最小字典序，因此，直接在这里逆置即可)
        int k = nums.length - 1;
        i++;
        for (; i<k; i++, k--)
            swap(nums, i, k);
    }
    
    public void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}
