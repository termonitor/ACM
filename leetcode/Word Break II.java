//leetcode 第一百四十题
//Word Break II
/**
给一个非空字符串s，和一组数据字典（由s的子字符串组成的），求s是否能够用数据字典中的多个字符串拼成，并返回所有可能组成的情况
**/
//rt:20ms

public class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        return DFS(s ,wordDict, new HashMap<String, List<String>>());
    }
    
    public List<String> DFS(String s, List<String> wordDict, Map<String, List<String>> map) {
        if(map.containsKey(s))
            return map.get(s);
        List<String> res = new LinkedList<>();
        if(s.length() == 0) {
            res.add("");
            return res;
        }
        for(String word : wordDict) {
            if(s.startsWith(word)) {
                List<String> subString = DFS(s.substring(word.length()), wordDict, map);
                for(String sub : subString)
                    res.add(word + (sub.isEmpty()?"":" ") + sub);
            }
        }
        map.put(s, res);
        return res;
    }
}