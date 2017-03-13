//leetcode 第八十四题
//Largest Rectangle in Histogram
/**
给一堆非负数字，代表一个宽为1，长为对应数字的矩形，求这些矩形拼起来的图形中，其中最大的矩形的面积
**/
//rt:28ms

public class Solution {
    public int largestRectangleArea(int[] heights) {
        int len = heights.length;
        Stack<Integer> stack = new Stack<Integer>();
        int maxArea = 0;
        for(int i=0; i<=len; i++) {
            int h = (i==len?0:heights[i]);
            if(stack.isEmpty() || h>=heights[stack.peek()])
                stack.push(i);
            else {
                int tp = stack.pop();
                maxArea = Math.max(maxArea, heights[tp]*(stack.isEmpty()?i:i-1-stack.peek()));
                i--;
            }
        }
        return maxArea;
    }
}