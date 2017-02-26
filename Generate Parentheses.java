//leetcode 第二十二题
//Generate Parentheses
/**
根据给的n值，生成合法的所有括号组合，采用递归的方法
**/
//rt:4ms

public class Solution {
    public static char[] word = {'(', ')'};
    
    public List<String> generateParenthesis(int n) {
        List<String> list = new ArrayList<>();
		String str = "";
		gpFunc(list, n, 0, str, 0, 0);
		return list;
    }
    
    public void gpFunc(List<String> list, int n, int o, String str, int l, int r) {
		if(o == 2*n+1) {
			String tmp = new String(str);
			list.add(tmp);
			return;
		}
		if(l==n && r==n) {
			gpFunc(list, n, o+1, str, l, r);
			return;
		}
		for(int i=0; i<2; i++) {
			if(i==0 && l==n)
				continue;
			if(i==1 && r==n)
				continue;
			str += word[i];
			if(i==0)
				l++;
			else if(i==1 && r<l)
				r++;
			else
				continue;
			gpFunc(list, n, o+1, str, l, r);
			if(i==0)
				l--;
			else
				r--;
			str = str.substring(0, o);
		}
	}
    
}