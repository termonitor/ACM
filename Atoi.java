//leetcode 第八题
//String to Integer (atoi)
/**
题意大概是将字符串转换为数字，并在在字符串部分不合法的时候，返回之前合法部分转换的数字，如果完全
不合法，则返回0，如果溢出的话，则返回INT32对应的最大值或者最小值。
因为在做第七题的时候，有用到String转int，因此直接参照java的Integer类的parseInt方法源代码，
做了部分修改，主要是将抛出异常的部分，按照题目要求做返回值的封装。
**/
//rt:39ms

public class Solution {
    public int myAtoi(String str) {
        if(str == null)
            return 0;
        str = str.trim();
        int result = 0;
        boolean negative = false;
        int i=0, len = str.length();
        int limit = -Integer.MAX_VALUE;
        int multmin;
        int digit;
        int radix = 10;
        if(len > 0) {
            char firstChar = str.charAt(0);
            if(firstChar < '0') {
                if(firstChar == '-') {
                    negative = true;
                    limit = Integer.MIN_VALUE;
                } else if(firstChar != '+')
                    return 0;
                if(len == 1)
                    return 0;
                i++;
            }
            multmin = limit/radix;
            while(i < len) {
                digit = Character.digit(str.charAt(i++), radix);
                if(digit < 0)
                    return negative?result:-result;
                if(result < multmin)
                    return negative?Integer.MIN_VALUE:Integer.MAX_VALUE;
                result *= radix;
                if(result < limit+digit)
                    return negative?Integer.MIN_VALUE:Integer.MAX_VALUE;
                result -= digit;
            }
        } else {
            return 0;
        }
        return negative?result:-result;
    } 
}