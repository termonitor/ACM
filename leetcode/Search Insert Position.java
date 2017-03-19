//leetcode 第三十五题
//Search Insert Position
/**
给一个不带重复数字升序的数组，然后查找一个数字，如果存在该数字，则返回它的位置，如果不存在，则按顺序插入，返回插入的顺序
**/
//rt:8ms

public class Solution {
    public int searchInsert(int[] nums, int target) {
        //二分查找
    	if(nums.length == 0)
    		return 0;
    	int left = 0, right = nums.length-1;
    	while(left <= right) {
    		int mid = (left + right)/2;
    		if(nums[mid] > target)
    			right = mid-1;
    		else if(nums[mid] < target)
    			left = mid + 1;
    		else {
    			return mid;
    		}
    	}
    	if(left < nums.length && nums[left] > target)
    		return left;
    	if(right >=0 && nums[right] < target)
    		return right+1;
    	return -1;
    }
}