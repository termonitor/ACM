//leetcode 第一百三十二题
//Palindrome Partitioning II
/**
给一段字符串，它可能由很多的回文字符串组成，求出需要把字符串切分为多个回文串的最小次数
**/
//rt:32ms

public class Solution {
    public int minCut(String s) {
        char[] c = s.toCharArray();
        int n = c.length;
        int[] cut = new int[n];
        boolean[][] pal = new boolean[n][n];
        for(int i=0; i<n; i++) {
            int min = i;
            for(int j=0; j<=i; j++) {
                if(c[j]==c[i] && (j+1>i-1 || pal[j+1][i-1])) {
                    pal[j][i] = true;
                    min = j==0?0:Math.min(min, cut[j-1]+1);
                }
            }
            cut[i] = min;
        }
        return cut[n-1];
    }
}