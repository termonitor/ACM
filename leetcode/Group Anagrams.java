//leetcode 第四十九题
//Group Anagrams
/**
给一个数字，找出所有的同字符异构组合
**/
//rt:38ms

public class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> list = new ArrayList<>();
		Map<String, List<String>> map = new HashMap<>();
		for(int i=0; i<strs.length; i++) {
			char[] cs = strs[i].toCharArray();
			Arrays.sort(cs);
			String code = new String(cs);
			if(map.containsKey(code)) {
				List<String> tmp = map.get(code);
				tmp.add(strs[i]);
				Collections.sort(tmp);
			} else {
				List<String> tmp = new ArrayList<>();
				tmp.add(strs[i]);
				Collections.sort(tmp);
				map.put(code, tmp);
			}
		}
		for(List<String> l:map.values()) {
			list.add(l);
		}
		return list;
    }
}