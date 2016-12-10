//leetcode 第二十五题
//Reverse Nodes in k-Group
/**
交换链表中的相邻K个元素节点
**/
//rt:9ms

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head == null)
			return null;
		if(head.next == null)
			return head;
		if(k==1)
		    return head;
        ListNode tmp1 = head;
        ListNode tmp2 = head;
        ListNode flag = null;
        int i = 0;
        while(tmp1!=null && tmp2!=null) {
            if(i%k == k-1) {
                //交换
                reverseNode(tmp1, tmp2);
                if(flag == null) {
                    head = tmp2;
                    flag = tmp1;
                } else {
                    flag.next = tmp2;
                    flag = tmp1;
                }
                tmp2 = tmp1.next;
                tmp1 = tmp2;
                i++;
                continue;
            }
            tmp2 = tmp2.next;
            i++;
        }
        return head;
    }
    
    public void reverseNode(ListNode node1, ListNode node2) {
        //a->node1->c->node2->b
        //return a->node2->c->node1->b
        //如果是只有两个节点,则直接交换
        if(node1.next == node2) {
            node1.next = node2.next;
            node2.next = node1;
            return;
        }
        
        ArrayList<ListNode> list = new ArrayList<>();
        ListNode tmp = node1;
        while(tmp!=null && tmp!=node2.next) {
            list.add(tmp);
            tmp = tmp.next;
        }
        int size = list.size();
        tmp = list.get(size-1).next;
        for(int i=size-1; i>0; i--) {
            list.get(i).next = list.get(i-1);
        }
        list.get(0).next = tmp;
    }
}




/**
** 另一种解法，10ms
**/
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head == null)
            return null;
        if(head.next == null)
            return head;
        if(k==1)
            return head;
        ArrayList<ListNode> list = new ArrayList<>();
        ListNode tmp = head;
        while(tmp != null) {
            list.add(tmp);
            tmp = tmp.next;
        }
        int size = list.size();
        int i=0;
        while(i < size) {
            if(i%k == k-1) {
                tmp = list.get(i).next;
                for(int j=i; i-k>0?j>i-k:j>0; j--) {
                    list.get(j).next = list.get(j - 1);
                }
                list.get(i-k>0?i-k+1:0).next = tmp;
                if(i != k-1) {
                    list.get(i-2*k+1).next = list.get(i);
                }
            }
            i++;
        }
        return list.get(size<k?0:k-1);
    }
}