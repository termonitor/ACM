//leetcode 第十三题
//Roman to Integer
/**
罗马数字转阿拉伯数字
**/
//rt:101ms

public class Solution {
    public int romanToInt(String s) {
        int num = 0;
		Map<Character, Integer> map = new HashMap<>();
		map.put('M', 1000);
		map.put('D', 500);
		map.put('C', 100);
		map.put('L', 50);
		map.put('X', 10);
		map.put('V', 5);
		map.put('I', 1);
		for(int i=0; i<s.length(); i++) {
			if(i+1 < s.length()) {
				int j = map.get(s.charAt(i));
				int k = map.get(s.charAt(i+1));
				if(j < k)
					num -= j;
				else
					num += j;
			} else {
				num += map.get(s.charAt(i));
			}
		}
		return num;
    }
}