//leetcode 第一百一十一题
//Minimum Depth of Binary Tree
/**
求一棵二叉树的最短路径
**/
//rt:1ms

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int minDepth(TreeNode root) {
        if(root == null)
            return 0;
        int lDepth = minDepth(root.left);
        int rDepth = minDepth(root.right);
        return (lDepth==0||rDepth==0)?(lDepth+rDepth+1):Math.min(lDepth, rDepth)+1;
    }
}