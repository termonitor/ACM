//leetcode 第八十七题
//Scramble String
/**
有一个字符串，可能经过各种旋转而得到另外一个字符串，判断两个字符串是否同源
**/
//rt:5ms

public class Solution {
    public boolean isScramble(String s1, String s2) {
        if(s1.equals(s2))
            return true;
        int[] letters = new int[26];
        for(int i=0; i<s1.length(); i++) {
            letters[s1.charAt(i)-'a']++;
            letters[s2.charAt(i)-'a']--;
        }
        for(int i=0; i<26; i++)
            if(letters[i] != 0)
                return false;
        for(int i=1; i<s1.length(); i++) {
            if(isScramble(s1.substring(0, i), s2.substring(0, i))
                    && isScramble(s1.substring(i), s2.substring(i)))
                return true;
            if(isScramble(s1.substring(0, i), s2.substring(s2.length()-i))
                    && isScramble(s1.substring(i), s2.substring(0, s2.length()-i)))
                return true;
        }
        return false;
    }
}