//leetcode 第二十题
//Valid Parentheses  
/**
判断字符的合法性，要求()[]{}必须两两对应
**/
//rt:8ms

public class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        int len = s.length();
        for(int i=0; i<len; i++) {
            if(stack.empty()) {
                stack.push(s.charAt(i));
            } else {
                Character c = stack.pop();
                if(s.charAt(i) == getContraryCharacter(c))
                    continue;
                else {
                    stack.push(c);
                    stack.push(s.charAt(i));
                }
            }
        }
        if(stack.empty())
            return true;
        return false;
    }
    
    public char getContraryCharacter(char c) {
        if(c == '(')
            return ')';
        if(c == '[')
            return ']';
        if(c == '{')
            return '}';
        return 'o';
    }
}