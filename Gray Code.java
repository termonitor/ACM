//leetcode 第八十九题
//Gray Code
/**
给一个数字n，求小于该数字的所有格雷码
**/
//rt:1ms

public class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> list = new ArrayList<Integer>();
        for(int i=0; i<1<<n; i++)
            list.add(i^i>>1);
        return list;
    }
}