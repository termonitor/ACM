//leetcode 第九题
//Palindrome Number
/**
思路主要是将数字转为字符串，然后将字符串翻转，然后比较字符串，来验证是回文的，效率很低，以后回头再看
**/
//rt:356ms

public class Solution {
    public boolean isPalindrome(int x) {
        String oldStr = String.valueOf(x);
        int len = oldStr.length();
        String newStr = "";
        if(oldStr.charAt(0) == '-') {
            //负数
            // newStr = "-"+reverseAction(1, len-1, oldStr);
            return false;
        } else {
            newStr = reverseAction(0, len-1, oldStr);
        }
        return oldStr.equals(newStr);
    }
    
    public String reverseAction(int l, int r, String str) {
        String num = "";
        if(str!=null && str.equals("0"))
            return str;
        boolean flag = false;
        for(int i=r; i>=l; i--)
        {
            char c = str.charAt(i);
            if(c!='0' && !flag)
                flag = true;
            if(!flag)
                continue;
            num += str.charAt(i);
        }
        return num;
    }
}