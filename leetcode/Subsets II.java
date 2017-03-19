//leetcode 第九十题
//Subsets II
/**
给一个数组，求出该数组中各个数字的组合，数组中可能存在重复数字
**/
//rt:3ms

public class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        Arrays.sort(nums);
        backtrack(list, new ArrayList<Integer>(), nums, 0);
        return list;
    }
    
    public void backtrack(List<List<Integer>> list, List<Integer> tempList, int[] nums, int begin) {
        list.add(new ArrayList<Integer>(tempList));
        for(int i=begin; i<nums.length; i++) {
            if(i==begin || nums[i]!=nums[i-1]) {
                tempList.add(nums[i]);
                backtrack(list, tempList, nums, i + 1);
                tempList.remove(tempList.size() - 1);
            }
        }
    }
}