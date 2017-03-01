//leetcode 第四十三题
//Multiply Strings
/**
给两个字符串，求两个字符串大数的乘积。
思路：m长度的字符串与n长度的字符串相乘，一般最长的长度为m+n的字符串，因此采用一位一位相乘的方式，并在乘的过程中取进位，最后去掉多余的0
最好的方式是将两个字符串倒过来相乘，这样不用计算下标，时间复杂度O(n2)
**/
//rt:40ms

public class Solution {
    public String multiply(String num1, String num2) {
        num1 = new StringBuilder(num1).reverse().toString();
		num2 = new StringBuilder(num2).reverse().toString();
		int n = num1.length();
		int m = num2.length();
		char[] result = new char[m+n+1];
		for(int i=0; i<result.length; i++)
			result[i] = '0';
		StringBuilder sb = new StringBuilder();
		int multiFlag, addFlag;
		
		for(int i=0; i<n; i++) {
			multiFlag = 0;
			addFlag = 0;
			for(int j=0; j<m; j++) {
				int tmp1 = (num1.charAt(i)-'0')*(num2.charAt(j)-'0') + multiFlag;
				multiFlag = tmp1/10;
				tmp1 = tmp1%10;
				int tmp2 = (result[i+j]-'0') + tmp1 + addFlag;
				addFlag  = tmp2/10;
				result[i+j] = (char)(tmp2%10+'0');
			}
			result[i+m] += multiFlag+addFlag;
		}
		for(int i=result.length-1; i>0; i--) {
			if(sb.length()==0 && result[i]=='0')
				continue;
			sb.append(result[i]);
		}
		sb.append(result[0]);
		return sb.toString();
    }
}