//leetcode 第九十五题
//Unique Binary Search Trees II
/**
求由1....n组成的二叉搜索树，总共有几种不同的结构，输出所有不同的结构
可以用dp解题，也可以用递归来解题
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
    public List<TreeNode> generateTrees(int n) {
        List<TreeNode>[] result = new List[n+1];
        result[0] = new ArrayList<TreeNode>();
        if(n == 0)
            return result[0];
        result[0].add(null);
        for(int len=1; len<=n; len++) {
            result[len] = new ArrayList<TreeNode>();
            for(int j=0; j<len; j++) {
                for(TreeNode lnode : result[j]) {
                    for(TreeNode rnode : result[len-j-1]) {
                        TreeNode root = new TreeNode(j+1);
                        root.left = lnode;
                        root.right = clone(rnode, j+1);
                        result[len].add(root);
                    }
                }
            }
        }
        return result[n];
    }
    
    public TreeNode clone(TreeNode n, int offset) {
        if(n == null)
            return null;
        TreeNode root = new TreeNode(n.val + offset);
        root.left = clone(n.left, offset);
        root.right = clone(n.right, offset);
        return root;
    }
    
}




//递归
//rt:4ms

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
    public List<TreeNode> generateTrees(int n) {
        if(n == 0)
            return new ArrayList<TreeNode>();
        return genTrees(1, n);
    }
    
    public List<TreeNode> genTrees(int start, int end) {
        List<TreeNode> list = new ArrayList<TreeNode>();
        if(start > end) {
            list.add(null);
            return list;
        }
        if(start == end) {
            list.add(new TreeNode(start));
            return list;
        }
        List<TreeNode> left, right;
        for(int i=start; i<=end; i++) {
            left = genTrees(start, i-1);
            right = genTrees(i+1, end);
            for(TreeNode lnode : left) {
                for(TreeNode rnode : right) {
                    TreeNode root = new TreeNode(i);
                    root.left = lnode;
                    root.right = rnode;
                    list.add(root);
                }
            }
        }
        return list;
    }
    
}