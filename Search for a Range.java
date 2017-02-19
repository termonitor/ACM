//leetcode 第三十四题
//Search for a Range
/**
给一个无须但是存在重复数字的数组，返回要查找的数字的所有位置。
**/
//rt:9ms

public class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] result = new int[]{-1, -1};
    	if(nums.length == 0)
    		return result;
    	//限制在O(log n)时间内，采用二分查找
    	int left = 0, right = nums.length-1;
    	while(left <= right) {
    		int mid = (left + right)/2;
    		if(nums[mid] > target) {
    			right = mid - 1;
    		} else if(nums[mid] < target) {
    			left = mid + 1;
    		} else {
    			result[0] = result[1] = mid;
    			int tmp = mid;
    			while(--tmp >=0 && nums[tmp] == target) {
    				result[0] = tmp;
    			}
    			tmp = mid;
    			while(++tmp < nums.length && nums[tmp] == target) {
    				result[1] = tmp;
    			}
    			/*
    			if(mid-1 >= 0 && nums[mid-1] == target) {
    				result[0] = mid-1;
    				result[1] = mid;
    			} else if(mid+1 < nums.length && nums[mid+1] == target) {
    				result[0] = mid;
    				result[1] = mid+1;
    			}
    			*/
    			break;
    		}
    	}
    	return result;
    }
}