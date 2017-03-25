//leetcode 第一百三十一题
//Palindrome Partitioning
/**
给一段字符串，它可能由很多的回文字符串组成，求出所有的组合
**/
//rt:9ms

public class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> list = new ArrayList<List<String>>();
        if(s.length() == 0)
            return list;
        backtrack(list, new ArrayList<String>(), s, 0);
        return list;
    }
    
    private void backtrack(List<List<String>> list, List<String> temp, String s, int start) {
        if(start == s.length()) {
            list.add(new ArrayList<String>(temp));
            return;
        }
        for(int i=1; i<=s.length()-start; i++) {
            String str = s.substring(start, start+i);
            if(isValidPalindrome(str)) {
                temp.add(str);
                backtrack(list, temp, s, start+i);
                temp.remove(temp.size()-1);
            }
        }
    }
    
    private boolean isValidPalindrome(String str) {
        if(str.length() == 0)
            return true;
        int l = 0;
        int r = str.length()-1;
        while(l < r) {
            if(l<r && str.charAt(l) != str.charAt(r))
                return false;
            l++;
            r--;
        }
        return true;
    }
}