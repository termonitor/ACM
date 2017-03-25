//leetcode 第一百二十九题
//Sum Root to Leaf Numbers
/**
一个二叉树，从根节点到叶子节点的一条路径，比如说1->2->3能组成一个数字123，求所有路径组成的数字相加之和
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
    public int sumNumbers(TreeNode root) {
        return sum(root, 0);
    }
    
    private int sum(TreeNode root, int s) {
        if(root == null)
            return 0;
        if(root.right==null && root.left==null)
            return s*10+root.val;
        return sum(root.left, s*10+root.val) + sum(root.right, s*10+root.val);
    }
}