//leetcode 第一百一十四题
//Flatten Binary Tree to Linked List
/**
将二叉树，变成一条递增的列表
类似于后序遍历的一种方式
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
    
    private TreeNode prev = null;
    
    public void flatten(TreeNode root) {
        if(root == null)
            return;
        flatten(root.right);
        flatten(root.left);
        root.right = prev;
        root.left = null;
        prev = root;
    }
}