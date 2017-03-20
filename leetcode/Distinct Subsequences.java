//leetcode 第一百一十五题
//Distinct Subsequences
/**
给两串字符串T和S，T有可能是S去掉一些其他字符之后的子串，判断S中存在多少种这种情况
dp问题
**/
//rt:16ms

public class Solution {
    public int numDistinct(String s, String t) {
        int[][] mem = new int[t.length()+1][s.length()+1];
        for(int i=0; i<=s.length(); i++)
            mem[0][i] = 1;
        for(int i=0; i<t.length(); i++) {
            for(int j=0; j<s.length(); j++) {
                if(t.charAt(i) == s.charAt(j))
                    mem[i+1][j+1] = mem[i][j] + mem[i+1][j];
                else
                    mem[i+1][j+1] = mem[i+1][j];
            }
        }
        return mem[t.length()][s.length()];
    }
}