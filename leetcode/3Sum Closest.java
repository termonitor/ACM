//leetcode 第十六题
//3Sum Closest
/**
从一个集合中选出三个数字相加和为target的数字集合，如果没有符合的，则反馈离target最近的和
**/
//rt:18ms

public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        if(nums==null || nums.length<=2)
			return 0;
		int min = Integer.MAX_VALUE;
		int val = 0;
		Arrays.sort(nums);
		for(int i=0; i<nums.length-2; i++) {
			int low = i+1;
			int high = nums.length-1;
			while(low < high) {
				int sum = nums[i] + nums[low] + nums[high];
				if(Math.abs(target - sum) < min) {
					min = Math.abs(target - sum);
					val = sum;
				}
				
				if(target == sum)
					return sum;
				else if(target > sum) {
					low++;
				} else {
					high--;
				}
 			}
		}
 		return val;
    }
}