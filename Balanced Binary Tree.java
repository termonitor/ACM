//leetcode 第一百一十题
//Balanced Binary Tree
/**
判断一棵二叉树是否平衡
**/
//rt:2ms

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
    public boolean isBalanced(TreeNode root) {
        if(root == null)
            return true;
        return depth(root)!=-1;
    }
    
    public int depth(TreeNode root) {
        if(root == null)
            return 0;
        int lDepth = depth(root.left);
        if(lDepth == -1)
            return -1;
        int rDepth = depth(root.right);
        if(rDepth == -1)
            return -1;
        if(lDepth>rDepth+1 || rDepth>lDepth+1)
            return -1;
        return Math.max(lDepth, rDepth)+1;
    }
}