//leetcode 第六十题
//Permutation Sequence
/**
给出n个数字组成的字典序中，第k个字典序
采用类似递归的方式。
**/
//rt:21ms

public class Solution {
    public String getPermutation(int n, int k) {
        int pos = 0;
		List<Integer> numbers = new ArrayList<>();
		int[] factorial = new int[n+1];
		StringBuilder sb = new StringBuilder();
		
		//求阶乘
		int sum = 1;
		factorial[0] = 1;
		for(int i=1; i<=n; i++) {
			sum *= i;
			factorial[i] = sum;
		}
		
		for(int i=1; i<=n; i++) {
			numbers.add(i);
		}
		k--;
		for(int i=1; i<=n; i++) {
			int index = k/factorial[n-i];
			sb.append(numbers.get(index));
			numbers.remove(index);
			k -= index*factorial[n-i];
		}
		return sb.toString();
    }
}