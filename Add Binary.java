//leetcode 第六十七题
//Add Binary
/**
给两个字符串，两个字符串的内容都是一串二进制的数，求两者之和。
**/
//rt:5ms

public class Solution {
    public String addBinary(String a, String b) {
        StringBuilder sb = new StringBuilder();
		int i=a.length()-1, j=b.length()-1, carry=0;
		while(i>=0 || j>=0) {
			int sum = carry;
			if(i >= 0)
				sum += a.charAt(i--)-'0';
			if(j >= 0)
				sum += b.charAt(j--)-'0';
			sb.append(sum%2);
			carry = sum/2;
		}
		if(carry != 0)
			sb.append(carry);
		return sb.reverse().toString();
    }
}