//leetcode 第一百题
//Same Tree
/**
判断两颗二叉树，是否为同一颗
**/
//rt:0ms

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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p==null && q==null)
    		return true;
    	if(p==null || q==null)
    		return false;
    	if(p.val == q.val)
    		return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    	return false;
    }
}



//另一种解法
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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        return traverse(p, q);
    }
    
    private boolean traverse(TreeNode r1, TreeNode r2) {
    	if(r1==null && r2==null)
    		return true;
    	if(r1==null || r2==null)
    		return false;
    	if(!traverse(r1.left, r2.left))
    		return false;
    	if(r1.val != r2.val)
    		return false;
    	if(!traverse(r1.right, r2.right))
    		return false;
    	return true;
    }
}