//leetcode 第二十一题
//Merge Two Sorted Lists
/**
合并两个有序的链表
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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1==null && l2==null)
			return null;
		if(l1 == null)
			return l2;
		if(l2 == null)
			return l1;
		ListNode head = null;
		ListNode tmp = null;
		if(l1.val < l2.val) {
			head = l1;
			l1 = head.next;
		} else {
			head = l2;
			l2 = head.next;
		}
		tmp = head;
		while(l1!=null || l2!=null) {
			if(l1 != null) {
				if(l2 != null) {
					if(l2.val < l1.val) {
						tmp.next = l2;
						l2 = l2.next;
						tmp = tmp.next;
					} else {
						tmp.next = l1;
						l1 = l1.next;
						tmp = tmp.next;
					}
				} else {
					tmp.next = l1;
					l1 = l1.next;
					tmp = tmp.next;
				}
			} else {
				if(l2 != null) {
					tmp.next = l2;
					l2 = l2.next;
					tmp = tmp.next;
				}
			}
		}
		return head;
    }
}