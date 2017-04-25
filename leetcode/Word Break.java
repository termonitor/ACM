//leetcode 第一百三十九题
//Word Break
/**
给一个非空字符串s，和一组数据字典（由s的子字符串组成的），求s是否能够用数据字典中的多个字符串拼成
**/
//rt:15ms

public class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        boolean[] f = new boolean[s.length()+1];
        f[0] = true;
        for(int i=1; i<=s.length(); i++) {
            for(int j=0; j<i; j++) {
                if(f[j] && wordDict.contains(s.substring(j, i))) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[s.length()];
    }
}