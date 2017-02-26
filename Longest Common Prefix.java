//leetcode 第十四题
// Longest Common Prefix
/**
最长公共前缀字符串，思路就是先获取最短的那一条字符串，然后以这条字符串的各个子字符串作为前缀去寻找
**/
//rt:12ms

public class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs == null)
            return "";
        int len = strs.length;
        if(len == 0)
            return "";
        if(len == 1)
            return strs[0];
        int minLen = strs[0].length();
        int minStrNo = 0;
        for(int i=0; i<len; i++) {
            if(strs[i].length() < minLen) {
                minLen = strs[i].length();
                minStrNo = i;
            }
        }
        for(int i=strs[minStrNo].length(); i>=0; i--) {
            String temp = strs[minStrNo].substring(0, i);
            for(int j=0; j<len; j++) {
                if(j == minStrNo)
                    continue;
                else {
                    if(strs[j].startsWith(temp)) {
                        if(j==len-1 || j==len-2 && minStrNo==len-1) {
                            return temp;
                        }
                        continue;
                    }
                    else
                        break;
                }
            }
        }
        return "";
    }
}