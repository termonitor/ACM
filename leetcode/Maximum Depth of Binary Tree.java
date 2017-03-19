//leetcode 第一百零四题
//Maximum Depth of Binary Tree
/**
给出一颗二叉树，求最深的深度
**/
//rt:0ms

//递归
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
    public int maxDepth(TreeNode root) {
        //深搜
        if(root == null)
            return 0;
        int leftDepth = maxDepth(root.left);
        int rightDepth = maxDepth(root.right);
        return leftDepth>rightDepth?leftDepth+1:rightDepth+1;
    }
}

//非递归，栈
//rt:6ms

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
    public int maxDepth(TreeNode root) {
        if(root == null)
            return 0;
        Stack<TreeNode> stack = new Stack<TreeNode>();
        Stack<Integer> value = new Stack<Integer>();
        stack.push(root);
        value.push(1);
        int maxDepth = 0;
        while(!stack.isEmpty()) {
            TreeNode node = stack.pop();
            int temp = value.pop();
            maxDepth = Math.max(temp, maxDepth);
            if(node.right != null) {
                stack.push(node.right);
                value.push(temp+1);
            }
            if(node.left != null) {
                stack.push(node.left);
                value.push(temp+1);
            }
        }
        return maxDepth;
    }
}