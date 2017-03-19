//leetcode 第一百一十二题
//Path Sum
/**
给出一棵二叉树，并给出一个sum，如果存在一条从根到叶子节点的一条路径，使得这条路径上所有节点的和等于sum，则返回true
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
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root == null)
            return false;
        if(root.left==null && root.right==null && sum-root.val==0)
            return true;
        return hasPathSum(root.left, sum-root.val)||hasPathSum(root.right, sum-root.val);
    }
}