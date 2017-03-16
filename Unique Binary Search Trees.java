//leetcode 第九十六题
//Unique Binary Search Trees
/**
求由1....n组成的二叉搜索树，总共有几种不同的结构
dp问题
**/
//rt:0ms

public class Solution {
    public int numTrees(int n) {
        int[] G = new int[n+1];
        G[0] = G[1] = 1;
        for(int i=2; i<=n; i++) {
            for(int j=1; j<=i; j++) {
                G[i] += G[j-1]*G[i-j];
            }
        }
        return G[n];
    }
}