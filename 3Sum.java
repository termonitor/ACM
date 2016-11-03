//leetcode 第十五题
//3Sum
/**
从一个集合中选出三个数字相加和为0的数字集合
**/
//rt:32ms

public class Solution {
    private List<List<Integer>> ret = new ArrayList<>();
    
    public List<List<Integer>> threeSum(int[] nums) {
        if(nums==null || nums.length<=2)
			return ret;
		Arrays.sort(nums);
		int len = nums.length;
		for(int i=0; i<len-2; i++) {
			if(i>0 && nums[i-1]==nums[i])
				continue;
			findSumEqualZero(nums, i+1, len-1, nums[i]);
		}
		return ret;
    }
    
    public void findSumEqualZero(int[] nums, int left, int right, int target) {
		while(left < right) {
			if(nums[left] + nums[right] + target == 0) {
				List<Integer> ans = new ArrayList<>();
				ans.add(target);
				ans.add(nums[left]);
				ans.add(nums[right]);
				ret.add(ans);
				while(left<right && nums[left]==nums[left+1])
					left++;
				while(left<right && nums[right]==nums[right-1])
					right--;
				left++;
				right--;
			} else if(nums[left] + nums[right] + target < 0) {
				left++;
			} else {
				right--;
			}
		}
	}
}