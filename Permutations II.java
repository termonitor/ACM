//leetcode 第四十七题
//Permutations II
/**
输入一个数组，输出所给数组中所有数字组成的所有字典序，与上一题不同的是，这次数组中存在重复的数字，因此会有不同的字典序
解题思路：递归，固定的结构
**/
//rt:8ms

public class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> list = new ArrayList<>();
        Arrays.sort(nums);
		backtrack(list, new ArrayList<>(), nums, new boolean[nums.length]);
		return list;
    }
    
    public void backtrack(List<List<Integer>> list, List<Integer> tempList, int[] nums, boolean[] used) {
		if(tempList.size() == nums.length)
			list.add(new ArrayList(tempList));
		else {
			for(int i=0; i<nums.length; i++) {
				if(used[i] || i>0&&nums[i]==nums[i-1]&&!used[i-1])
					continue;
				tempList.add(nums[i]);
				used[i] = true;
				backtrack(list, tempList, nums, used);
				used[i] = false;
				tempList.remove(tempList.size()-1);
			}
		}
	}
}