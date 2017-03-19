//leetcode 第六十九题
//Sqrt(x)
/**
实现整数型的开方函数
**/
//rt:3ms

public class Solution {
    public int mySqrt(int x) {
        if(x == 0)
            return 0;
        int l = 1, r = Integer.MAX_VALUE;
        while(true) {
            int mid = l + (r-l)/2;
            if(mid > x/mid)
                r = mid-1;
            else {
                if(mid+1 > x/(mid+1))
                    return mid;
                l = mid+1;
            }
        }
    }
}