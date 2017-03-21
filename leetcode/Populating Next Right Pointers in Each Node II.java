//leetcode 第一百一十七题
//Populating Next Right Pointers in Each Node II
/**
一棵非标准二叉树，在每个节点上加一个指针，使得该指针能够指向该节点所在行的下一个节点
层遍历
**/
//rt:8ms

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
//rt:2ms

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
        TreeLinkNode head = null;
        TreeLinkNode prev = null;
        TreeLinkNode cur = root;
        while(cur != null) {
            while(cur != null) {
                if(cur.left != null) {
                    if(prev != null)
                        prev.next = cur.left;
                    else
                        head = cur.left;
                    prev = cur.left;
                }
                if(cur.right != null) {
                    if(prev != null)
                        prev.next = cur.right;
                    else
                        head = cur.right;
                    prev = cur.right;
                }
                cur = cur.next;
            }
            cur = head;
            head = null;
            prev = null;
        }
    }
}