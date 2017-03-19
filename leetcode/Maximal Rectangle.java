//leetcode 第八十五题
//Maximal Rectangle
/**
给出一个由0和1组成的二维数组，寻找最大的由1组成的矩形的面积
dp问题
**/
//rt:12ms

public class Solution {
    public int maximalRectangle(char[][] matrix) {
        int m = matrix.length;
        if(m == 0)
            return 0;
        int n = matrix[0].length;
        int[] left = new int[n];
        int[] right = new int[n];
        int[] height = new int[n];
        for(int i=0; i<n; i++)
            right[i] = n;
        int max = 0;
        for(int i=0; i<m; i++) {
            int curLeft = 0, curRight = n;
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == '1')
                    left[j] = Math.max(left[j], curLeft);
                else {
                    left[j] = 0;
                    curLeft = j+1;
                }
            }
            for(int j=n-1; j>=0; j--) {
                if(matrix[i][j] == '1')
                    right[j] = Math.min(right[j], curRight);
                else {
                    right[j] = n;
                    curRight = j;
                }
            }
            for(int j=0; j<n; j++) {
                max = Math.max(max, (right[j]-left[j])*height[j]);
            }
        }
        return max;
    }
}