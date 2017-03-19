//leetcode 第四十题
//Combination Sum II
/**
给一个数组，给一个目标值，求出所有拿数组中的值相加能够得到目标值的组合。与29题的差别在于这次会有重复的数字，且每个数字仅可使用一次。采用递归的方式
**/
//rt:23ms

public class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> list = new ArrayList<>();
		//先排序
		Arrays.sort(candidates);
		backtrace(list, new ArrayList(), candidates, target, 0);
		return list;
    }
    
    public void backtrace(List<List<Integer>> list, List<Integer> tempList, int[] candidates, int target, int start) {
        if(target < 0)
			return;
		else if(target == 0)
			list.add(new ArrayList<>(tempList));
		else {
			for(int i=start; i<candidates.length; i++) {
				if(i>start && candidates[i] == candidates[i-1])
					continue;
				tempList.add(candidates[i]);
				backtrace(list, tempList, candidates, target-candidates[i], i+1);
				tempList.remove(tempList.size()-1);
			}
		}
    }
}