//leetcode 第十一题
//Container With Most Water
/**

**/
//rt:9ms

public class Solution {
    public int maxArea(int[] height) {
        if(height.length < 2)
			return 0;
		int l, r;
		l = 0;
		r = height.length-1;
		int max = 0;
		while(l < r) {
			int v = Math.min(height[l], height[r])*(r-l);
			if(v > max)
				max = v;
			if(height[l]<height[r])
				l++;
			else
				r--;
		}
		return max;
    }
}