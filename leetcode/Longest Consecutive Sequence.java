//leetcode 第一百二十八题
//Longest Consecutive Sequence
/**
给一个数列，找出中间存在顺序的数列的最大长度
**/
//rt:18ms

public class Solution {
    public int longestConsecutive(int[] nums) {
        int res = 0;
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int n : nums) {
            if(!map.containsKey(n)) {
                int left = map.containsKey(n-1)?map.get(n-1):0;
                int right = map.containsKey(n+1)?map.get(n+1):0;
                int sum = left + right + 1;
                res = Math.max(res, sum);
                map.put(n, sum);
                map.put(n-left, sum);
                map.put(n+right, sum);
            }
            else
                continue;
        }
        return res;
    }
}


//other solution
//rt:11ms

public class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums == null || nums.length == 0) return 0;
    
        Set<Integer> set = new HashSet<Integer>();
        
        for(int num: nums) set.add(num);
        int max = 1;
        for(int num: nums) {
            if(set.remove(num)) {//num hasn't been visited
                int val = num;
                int sum = 1;
                while(set.remove(val-1)) val--;
                sum += num - val;
                
                val = num;
                while(set.remove(val+1)) val++;
                sum += val - num;
                
                max = Math.max(max, sum);
            }
        }
        return max;
    }
}