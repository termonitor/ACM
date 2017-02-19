//leetcode 第三十二题
//Longest Valid Parentheses
/**
给一串由'(',')'组成的字符串，求符合'()'规则的最长的字符串的长度
**/
//rt:25ms

public class Solution {
    public int longestValidParentheses(String s) {
        Stack<Integer> stack = new Stack<Integer>();
    	if (s == null || s.length() == 0)
    		return 0;
    	int max = 0;
    	int left = -1;
    	for(int j=0; j<s.length(); j++) {
    		if (s.charAt(j) == '(')
    			stack.push(j);
    		else {
    			if(stack.isEmpty())
    				left = j;
    			else {
    				stack.pop();
    				if (stack.isEmpty()) 
    					max = Math.max(max, j-left);
    				else
    					max = Math.max(max, j-stack.peek());
    			}
    		}
    	}
    	return max;
    }
}