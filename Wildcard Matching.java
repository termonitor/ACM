//leetcode 第四十四题
//Wildcard Matching
/**
通配符匹配，？号能够匹配一个字符，*号能够匹配所有字符
这是一个dp问题，具体解法看代码
**/
//rt:118ms

public class Solution {
    public boolean isMatch(String s, String p) {
        boolean[][] match = new boolean[s.length()+1][p.length()+1];
		match[s.length()][p.length()] = true;
		for(int i=p.length()-1; i>=0; i--) {
			if(p.charAt(i) != '*')
				break;
			else
				match[s.length()][i] = true;
		}
		for(int i=s.length()-1; i>=0; i--) {
			for(int j=p.length()-1; j>=0; j--) {
				if(s.charAt(i)==p.charAt(j) || p.charAt(j)=='?')
					match[i][j] = match[i+1][j+1];
				else if(p.charAt(j) == '*')
					match[i][j] = match[i+1][j]||match[i][j+1];
				else
					match[i][j] = false;
			}
		}
		return match[0][0];
    }
}