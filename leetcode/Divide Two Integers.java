//leetcode 第二十九题
//Divide Two Integers
/**
在不使用乘法、除法、减法的情况下，计算两个整数的除法运算。
**/
//rt:46 ms

/**
思路是，将两个数转换为long型，以防止数值越界的问题产生。采用二分查找的方式，递归的计算商值，能够提高效率。
**/
public class Solution {
    public int divide(int dividend, int divisor) {
        int sign = 1;
		if((dividend>0&&divisor<0) || (dividend<0&&divisor>0))
			sign = -1;
		long ldividend = Math.abs((long) dividend);
		long ldivisor = Math.abs((long) divisor);
		if(ldivisor == 0)
			return Integer.MAX_VALUE;
		if (ldividend==0 || ldividend<ldivisor)
			return 0;
		long lans = ldivide(ldividend, ldivisor);
		int ans;
		if(lans > Integer.MAX_VALUE) {
			ans = (sign==1)?Integer.MAX_VALUE:Integer.MIN_VALUE;
		} else {
			ans = (int)(sign * lans);
		}
		return ans;
    }
    
    private long ldivide(long ldividend, long ldivisor) {
		if(ldividend < ldivisor)
			return 0;
		long sum = ldivisor;
		long multiple = 1;
		while((sum+sum) <= ldividend) {
			sum += sum;
			multiple += multiple;
		}
		return multiple + ldivide(ldividend-sum, ldivisor);
	}
}
