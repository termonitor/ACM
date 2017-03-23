//leetcode 第一百二十五题
//Valid Palindrome
/**
判断一段字符串是否是回文的，只判断中间的字符数字，其他都排除
**/
//rt:6ms

public class Solution {
    public boolean isPalindrome(String s) {
        int len = s.length();
        if(len == 0)
            return true;
        int l=0, r=len-1;
        while(l<r) {
            while(l<len&&!judgeBefore(s.charAt(l)))
                l++;
            while(r>=0&&!judgeBefore(s.charAt(r)))
                r--;
            if(l<r && !judgeAfter(s.charAt(l), s.charAt(r)))
                return false;
            l++;
            r--;
        }
        return true;
    }
    
    public boolean judgeAfter(char a, char b) {
        if(a>='a' && a<='z')
            a -= 32;
        if(b>='a' && b<='z')
            b -= 32;
        return a==b?true:false;
    }
    
    private boolean judgeBefore(char c) {
        if(c>='a' && c<='z')
            return true;
        if(c>='A' && c<='Z')
            return true;
        if(c>='0' && c<='9')
            return true;
        return false;
    }
}