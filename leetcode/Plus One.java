//leetcode 第六十六题
//Plus One
/**
给一个由个位数字组成的数组，表示一个数字，加一，求结果
**/
//rt:1ms

public class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;
		for(int i=n-1; i>=0; i--) {
			if(digits[i] < 9) {
				digits[i]++;
				return digits;
			}
			digits[i] = 0;
		}
		int[] newNumber = new int[n+1];
		newNumber[0] = 1;
		return newNumber;
    }
}