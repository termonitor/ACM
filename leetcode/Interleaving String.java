//leetcode 第九十七题
//Interleaving String
/**
给出三个字符串s1,s2,s3，判断s3是否由s1和s2顺序交织组成。
dp问题
**/
//rt:6ms

public class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        if(s3.length() != s1.length()+s2.length())
            return false;
        boolean[][] tables = new boolean[s1.length()+1][s2.length()+1];
        for(int i=0; i<=s1.length(); i++) {
            for(int j=0; j<=s2.length(); j++) {
                if(i==0 && j==0)
                    tables[i][j] = true;
                else if(i==0)
                    tables[i][j] = tables[i][j-1] && s3.charAt(j-1)==s2.charAt(j-1);
                else if(j==0)
                    tables[i][j] = tables[i-1][j] && s3.charAt(i-1)==s1.charAt(i-1);
                else
                    tables[i][j] = (tables[i-1][j]&&s3.charAt(i+j-1)==s1.charAt(i-1))
                                    || (tables[i][j-1]&&s3.charAt(i+j-1)==s2.charAt(j-1));
            }
        }
        return tables[s1.length()][s2.length()];
    }
}