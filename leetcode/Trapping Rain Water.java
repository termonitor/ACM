//leetcode 第四十二题
//Trapping Rain Water
/**
给一个数组，表示立体的一个积木，求能够积水的面积。。比较难说，看图很容易明白
链接：https://leetcode.com/problems/trapping-rain-water/?tab=Description
解题思路：分别从两边开始找最大的边界，并据此向内计算。
**/
//rt:26ms

public class Solution {
    public int trap(int[] height) {
        if(height.length < 3)
			return 0;
		int ans = 0;
		int l=0, r=height.length-1;
		while(l<r && height[l]<=height[l+1])
			l++;
		while(l<r && height[r]<=height[r-1])
			r--;
		while(l < r) {
			int left = height[l];
			int right = height[r];
			if(left <= right) {
				while(l<r && left>=height[++l])
					ans += left-height[l];
			} else {
				while(l<r && right>=height[--r])
					ans += right-height[r];
			}
		}
		return ans;
    }
}