//leetcode 第一百一十二题
//Path Sum II
/**
给出一棵二叉树，并给出一个sum，如果存在一条从根到叶子节点的一条路径，使得这条路径上所有节点的和等于sum，则返回所有符合这个条件的根到叶子节点的路径
**/
//rt:3ms

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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        backtrack(list, new ArrayList<Integer>(), root, sum);
        return list;
    }
    
    public void backtrack(List<List<Integer>> list, List<Integer> tempList, TreeNode root, int sum) {
        if(root == null)
            return;
        if(root.left==null && root.right==null && sum-root.val==0) {
            tempList.add(root.val);
            list.add(new ArrayList(tempList));
            tempList.remove(tempList.size()-1);
            return;
        }
        tempList.add(root.val);
        backtrack(list, tempList, root.left, sum-root.val);
        backtrack(list, tempList, root.right, sum-root.val);
        tempList.remove(tempList.size()-1);
    }
}