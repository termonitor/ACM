//leetcode 第九十二题
//Reverse Linked List II
/**
给一个链表，m以及n，将链表中第m到第n个节点反转
**/
//rt:0ms

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if(head == null)
            return null;
        ListNode fakeHead = new ListNode(0);
        fakeHead.next = head;
        ListNode pre = fakeHead;
        for(int i=0; i<m-1; i++)
            pre = pre.next;
        ListNode start = pre.next;
        ListNode then = start.next;
        for(int i=0; i<n-m; i++) {
            start.next = then.next;
            then.next = pre.next;
            pre.next = then;
            then = start.next;
        }
        return fakeHead.next;
    }
}