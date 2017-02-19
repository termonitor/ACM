//leetcode 第三十九题
//Combination Sum
/**
给一个数组，给一个目标值，求出所有拿数组中的值相加能够得到目标值的组合。
这是一个dp问题，理解思想很好解决
**/
//rt:47ms

public class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
    	if(candidates==null || candidates.length ==0)
    		return list;
    	Arrays.sort(candidates);
    	List<List<List<Integer>>> dp = new ArrayList<List<List<Integer>>>();
    	for(int i=1; i<=target; i++) {
    		List<List<Integer>> newList = new ArrayList<List<Integer>>();
    		for(int j=0; j<candidates.length&&candidates[j]<=i; j++) {
    			if(candidates[j] == i)
    				newList.add(Arrays.asList(candidates[j]));
    			else
    				for(List<Integer> l : dp.get(i-candidates[j]-1)) {
    					if(candidates[j] <= l.get(0)) {
    						List<Integer> cl = new ArrayList<Integer>();
    						cl.add(candidates[j]);
    						cl.addAll(l);
    						newList.add(cl);
    					}
    				}
    		}
    		dp.add(newList);
    	}
    	return dp.get(target-1);
    }
}