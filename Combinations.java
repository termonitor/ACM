//leetcode 第七十七题
//Combinations
/**
给出两个数字，n和k，返回由combinations of k numbers out of 1 ... n.
**/
//rt:71ms

public class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> list = new ArrayList<>();
		backtrack(list, new ArrayList<Integer>(), n, k, 1);
		return list;
    }
    
    public void backtrack(List<List<Integer>> list, List<Integer> tempList, int n, int k, int start) {
		if(tempList.size() == k)
			list.add(new ArrayList(tempList));
		else {
			for(int i=1; i<=n; i++) {
				if(i<start)
					continue;
				tempList.add(new Integer(i));
				backtrack(list, tempList, n, k, i+1);
				tempList.remove(new Integer(i));
			}
		}
	}
}