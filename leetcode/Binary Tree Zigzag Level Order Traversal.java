//leetcode 第一百零三题
//Binary Tree Zigzag Level Order Traversal
/**
给出一颗二叉树，以Z层遍历的方式遍历出节点
**/
//rt:4ms

//利用双栈的方式 
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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> list = new LinkedList<List<Integer>>();
        Stack<TreeNode> cur_stack = new Stack<TreeNode>();
        Stack<TreeNode> next_stack = new Stack<TreeNode>();
        if(root == null)
            return list;
        cur_stack.push(root);
        int num = 1;
        while(!cur_stack.isEmpty()) {
            int levelNum = cur_stack.size();
            List<Integer> subList = new LinkedList<Integer>();
            for(int i=0; i<levelNum; i++) {
                if(num%2 == 1) {
                    if(cur_stack.peek().left != null)
                        next_stack.push(cur_stack.peek().left);
                    if (cur_stack.peek().right != null)
                        next_stack.push(cur_stack.peek().right);
                } else {
                    if (cur_stack.peek().right != null)
                        next_stack.push(cur_stack.peek().right);
                    if(cur_stack.peek().left != null)
                        next_stack.push(cur_stack.peek().left);
                }
                subList.add(cur_stack.pop().val);
            }
            if(!next_stack.isEmpty()) {
                num++;
                cur_stack = next_stack;
                next_stack = new Stack<TreeNode>();
            }
            list.add(subList);
        }
        return list;
    }
}


//递归调用
//rt:2ms

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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
       List<List<Integer>> list = new LinkedList<List<Integer>>();
        travel(root, list, 0);
        return list;
    }
    
    public void travel(TreeNode root, List<List<Integer>> list, int level) {
        if(root == null)
            return;
        if(list.size() <= level) {
            List<Integer> newList = new LinkedList<Integer>();
            list.add(newList);
        }
        List<Integer> collection = list.get(level);
        if(level%2 == 0)
            collection.add(root.val);
        else
            collection.add(0, root.val);
        travel(root.left, list, level+1);
        travel(root.right, list, level+1);
    }
}