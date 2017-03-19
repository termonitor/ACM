//leetcode 第一百零六题
//Construct Binary Tree from Inorder and Postorder Traversal
/**
根据中序后序遍历结果，构建二叉树
**/
//rt:33ms

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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return helper(inorder, postorder, 0, inorder.length-1, 0, postorder.length-1);
    }
    
    public TreeNode helper(int[] inorder, int[] postorder, int inStart, int inEnd, int postStart, int postEnd) {
        if(inStart>inEnd || postStart>postEnd)
            return null;
        TreeNode root = new TreeNode(postorder[postEnd]);
        int inIndex = 0;
        for(int i=inStart; i<=inEnd; i++) {
            if(root.val == inorder[i])
                inIndex = i;
        }
        root.left = helper(inorder, postorder, inStart, inIndex-1, postStart, postStart+inIndex-inStart-1);
        root.right = helper(inorder, postorder, inIndex+1, inEnd, postStart+inIndex-inStart, postEnd-1);
        return root;
    }
}