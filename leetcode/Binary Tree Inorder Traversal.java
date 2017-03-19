//leetcode 第九十四题
//Binary Tree Inorder Traversal
/**
二叉树中序遍历
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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<Integer>();
        backtrack(list, root);
        return list;
    }
    
    public void backtrack(List<Integer> list, TreeNode root) {
        if(root != null) {
            backtrack(list, root.left);
            list.add(root.val);
            backtrack(list, root.right);
        }
    }
}