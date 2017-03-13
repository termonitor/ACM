//leetcode 第八十题
//Remove Duplicates from Sorted Array II
/**
给一个数组，计算这个数组中最多有多少不重复的字母（一个字母允许重复两次）
**/
//分为两种方式，一种比较low，一种比较high

//rt:11ms
//low的
public class Solution {
    public int removeDuplicates(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
		List<Integer> list = new ArrayList<>();
		int count = 0;
		for(int i=0; i<nums.length; i++) {
			Integer num = map.get(nums[i]);
			if(num == null) {
				count++;
				map.put(nums[i], 1);
				list.add(nums[i]);
			} else if(num == 1) {
				count++;
				map.put(nums[i], 2);
				list.add(nums[i]);
			}
		}
		for(int i=0; i<list.size(); i++)
			nums[i] = list.get(i);
		return count;
    }
}

//rt:1ms
//high的
public class Solution {
    public int removeDuplicates(int[] nums) {
        int i = 0;
		for(int n : nums) {
			if(i<2 || n>nums[i-2])
				nums[i++] = n;
		}
		return i;
    }
}