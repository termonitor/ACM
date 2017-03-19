//leetcode 第七题
//Reverse Integer
//反转整数，考虑溢出的情况以及正负的情况
//rt:43ms

public class Solution {
    public int reverse(int x) {
        String num = String.valueOf(x);
        int len = num.length();
        if(num.charAt(0) == '-') {
            //负数
            num = "-"+reverseAction(1, len-1, num);
        } else {
            num = reverseAction(0, len-1, num);
        }
        int n = 0;
        try {
            n = Integer.parseInt(num);
        } catch(NumberFormatException e) {
            n = 0;
        }
        return n;
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