//leetcode 第九十九题
//Recover Binary Search Tree
/**
二叉搜索树中有两个数字的位置不小心被替换了，找出来，并替换回去
**/
//rt:5ms

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
    
    TreeNode firstElement = null;
    TreeNode secondElement = null;
    TreeNode preElement = new TreeNode(Integer.MIN_VALUE);
    
    public void recoverTree(TreeNode root) {
        traverse(root);
        int tmp =firstElement.val;
        firstElement.val = secondElement.val;
        secondElement.val = tmp;
    }
    
    public void traverse(TreeNode root) {
        if(root == null)
            return;
        traverse(root.left);
        if(firstElement==null && preElement.val >= root.val)
            firstElement = preElement;
        if(firstElement!=null && preElement.val >= root.val)
            secondElement = root;
        preElement = root;
        traverse(root.right);
    }
    
}