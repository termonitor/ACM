//leetcode 第三十八题
//Count and Say
/**
题意不好讲但很好理解，参见题目介绍吧，直接上模拟法解决
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
**/
//rt:6ms

public class Solution {
    public String countAndSay(int n) {
        //1 11 21 1211 111221 312211 13112221 1113213211
    	String str = "1";
    	while (n > 1) {
    		char pre = 0;
    		int num = 0;
    		StringBuilder sb = new StringBuilder();
    		for (int i=0; i<str.length(); i++) {
    			if(pre == 0) {
    				pre = str.charAt(i);
    				num = 1;
    				continue;
    			}
    			if (pre != str.charAt(i)) {
    				sb.append((char)('0'+num));
    				sb.append(pre);
    				pre = str.charAt(i);
    				num = 1;
    			} else {
    				num++;
    			}
    		}
    		//还要处理一轮
    		if(num != 0) {
    			sb.append((char)('0'+num));
    			sb.append(pre);
    		}
    		str = sb.toString();
    		n--;
    	}
    	return str;
    }
}