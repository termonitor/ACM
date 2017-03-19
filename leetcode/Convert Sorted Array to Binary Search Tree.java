//leetcode 第一百零八题
//Convert Sorted Array to Binary Search Tree
/**
给出一个递增的序列，建立一个高度平衡的二叉树
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
    public TreeNode sortedArrayToBST(int[] nums) {
        if(nums.length == 0)
            return null;
        TreeNode head = helper(nums, 0, nums.length-1);
        return head;
    }
    
    public TreeNode helper(int[] nums, int low, int high) {
        if(low > high)
            return null;
        int mid = (low+high)/2;
        TreeNode node = new TreeNode(nums[mid]);
        node.left = helper(nums, low, mid-1);
        node.right = helper(nums, mid+1, high);
        return node;
    }
}