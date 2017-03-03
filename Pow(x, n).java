//leetcode 第五十题
//Pow(x, n)
/**
手写开方函数，二分法
**/
//rt:23ms

public class Solution {
    public double myPow(double x, int n) {
        double temp = x;
		if(n == 0)
			return 1;
		temp = myPow(x, n/2);
		if(n%2 == 0)
			return temp*temp;
		else {
			if(n>0)
				return x*temp*temp;
			else
				return temp*temp/x;
		}
    }
}