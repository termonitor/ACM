//leetcode 第一百零一题
//Symmetric Tree
/**
判断一颗二叉树是否为中间对称的
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
    public boolean isSymmetric(TreeNode root) {
        if(root == null)
    		return true;
    	return isMirror(root.left, root.right);
    }
    
    public boolean isMirror(TreeNode p, TreeNode q) {
    	if(p==null && q==null)
    		return true;
    	if(p==null || q==null)
    		return false;
    	return (p.val==q.val) && isMirror(p.left, q.right) && isMirror(p.right, q.left);
    }
}