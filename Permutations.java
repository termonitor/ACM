//leetcode 第四十六题
//Permutations
/**
输入一个数组，输出所给数组中所有数字组成的所有字典序
解题思路：递归，固定的结构
**/
//rt:9ms

public class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> list = new ArrayList<>();
		backtrack(list, new ArrayList<>(), nums);
		return list;
    }
    
    public void backtrack(List<List<Integer>> list, List<Integer> tempList, int[] nums) {
        if(tempList.size() == nums.length)
			list.add(new ArrayList(tempList));
		else {
			for(int i=0; i<nums.length; i++) {
				if(tempList.contains(nums[i]))
					continue;
				tempList.add(nums[i]);
				backtrack(list, tempList, nums);
				tempList.remove(tempList.size()-1);
			}
		}   
    }
}