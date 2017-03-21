//leetcode 第一百一十六题
//Populating Next Right Pointers in Each Node
/**
一棵标准二叉树，在每个节点上加一个指针，使得该指针能够指向该节点所在行的下一个节点
层遍历
**/
//rt:10ms

/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void connect(TreeLinkNode root) {
        if(root == null)
            return;
        Queue<TreeLinkNode> queue = new LinkedList<TreeLinkNode>();
        queue.offer(root);
        while(!queue.isEmpty()) {
            int levelNum = queue.size();
            for(int i=0; i<levelNum; i++) {
                if(queue.peek().left != null)
                    queue.offer(queue.peek().left);
                if(queue.peek().right != null)
                    queue.offer(queue.peek().right);
                if(i==levelNum-1)
                    queue.poll().next = null;
                else {
                    TreeLinkNode t = queue.poll();
                    t.next = queue.peek();
                }
            }
        }
    }
}


//另一种解法
//rt:1ms

/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void connect(TreeLinkNode root) {
        TreeLinkNode levelStart = root;
        while(levelStart != null) {
            TreeLinkNode cur = levelStart;
            while(cur != null) {
                if(cur.left != null)
                    cur.left.next = cur.right;
                if(cur.right != null && cur.next !=null)
                    cur.right.next = cur.next.left;
                cur = cur.next;
            }
            levelStart = levelStart.left;
        }
    }
}