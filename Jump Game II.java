//leetcode 第四十五题
//Jump Game II
/**
跳跃游戏，给一个数组，数组里的每个数字表示在当前位置最多能走几部，求从起点（下标为0的地方）到终点最少跳几次。
采用贪心算法，用动态规划可能超时。。要不就是我用的不对。
**/
//rt:15ms

public class Solution {
    public int jump(int[] nums) {
        int sc = 0;
		int e = 0;
		int max = 0;
		for(int i=0; i<nums.length-1; i++) {
			max = Math.max(max, i+nums[i]);
			if(i==e) {
				sc++;
				e = max;
			}
		}
		return sc;
    }
}


//rt:10ms
public class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
		int[] pre = new int[n];
		int reach = 0;
		for(int i=0; i<n; i++) {
			if(i+nums[i] > reach) {
				for(int j=reach+1; j<=i+nums[i]&&j<n; j++)
					pre[j] = i;
				reach = i+nums[i];
			}
		}
		int ans = 0;
		int k = n-1;
		while(k > 0) {
			k = pre[k];
			ans++;
		}
		return ans;
    }
}