//leetcode 第十九题
//Remove Nth Node From End of List
/**
删除一个链表的倒数第N个节点，并返回头节点
**/
//rt:15ms

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head == null)
			return null;
		ListNode next = head.next;
		if(next == null && n==1)
			return null;
		int len = 1;
		while(next != null) {
			next = next.next;
			len++;
		}
		if(len==1 && n==1)
			return null;
		next = head;
		for(int i=0; i<len-n-1; i++) {
			next = next.next;
		}
		if(next == head && n == len) {
			return head.next;
		}
		ListNode tmp = next.next;
		next.next = tmp.next;
		return head;
    }
}