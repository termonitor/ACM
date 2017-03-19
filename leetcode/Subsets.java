//leetcode 第七十八题
//Subsets
/**
给一个数组，求出该数组中各个数字的组合
**/
//rt:2ms

public class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> list = new ArrayList<>();
		backtrack(list, new ArrayList<Integer>(), nums, 0);
		return list;
    }
    
    public void backtrack(List<List<Integer>> list, List<Integer> tempList, int[] nums, int i) {
		list.add(new ArrayList<>(tempList));
		for(; i<nums.length; i++) {
			tempList.add(nums[i]);
			backtrack(list, tempList, nums, i+1);
			tempList.remove(tempList.size()-1);
		}
	}
}