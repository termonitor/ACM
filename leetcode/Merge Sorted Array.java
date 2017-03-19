//leetcode 第八十八题
//Merge Sorted Array
/**
将两个有序的A和B两个数字合并，将B合并到A中去
**/
//rt:0ms

public class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(i>=0 && j>=0) {
            if(nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
        while(j >= 0)
            nums1[k--] = nums2[j--];
    }
}