//leetcode 第二十四题
//Swap Nodes in Pairs
/**
交换链表中的相邻的元素节点
**/
//rt:5ms

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head == null)
			return null;
		if(head.next == null)
			return head;
		ListNode top = new ListNode(0);
		top.next = head;
		ListNode tmp = head;
		if(tmp!=null && tmp.next!=null) {
			swap(top, tmp, tmp.next);
		}
		while(tmp.next!=null && tmp.next.next!=null) {
			swap(tmp, tmp.next, tmp.next.next);
			tmp = tmp.next.next;
		}
		return top.next;
    }
    
    public void swap(ListNode l0, ListNode l1, ListNode l2) {
		l0.next = l2.next;
		l1.next = l0.next;
		l0.next = l2;
		l2.next = l1;
	}
}