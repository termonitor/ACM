//leetcode 第一百二十题
//Triangle
/**
给一个三角形，求从顶到底的一个最小的路径
**/
//rt:9ms

public class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int len = triangle.size();
        if(len == 0)
            return 0;
        int[] distance = new int[len];
        List<Integer> last = triangle.get(len-1);
        for(int i=0; i<last.size(); i++)
            distance[i] = last.get(i);
        for(int i=len-2; i>=0; i--) {
            last = triangle.get(i);
            for(int j=0; j<last.size(); j++)
                distance[j] = last.get(j) + Math.min(distance[j], distance[j+1]);
        }
        return distance[0];
    }
}