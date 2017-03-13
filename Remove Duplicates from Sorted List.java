//leetcode 第八十三题
//Remove Duplicates from Sorted List
/**
给一个链表，去除中间重复的所有元素使得重复的元素有且只有一个，并返回head
**/
//rt:1ms

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null)
            return null;
        ListNode fakeHead = new ListNode(0);
        fakeHead.next = head;
        ListNode pre = fakeHead;
        ListNode cur = head;
        while(cur != null) {
            while(cur.next != null && cur.val == cur.next.val) {
                cur = cur.next;
            }
            if(pre.next == cur) {
                pre = pre.next;
                cur = cur.next;
            } else {
                pre.next = cur;
            }
        }
        return fakeHead.next;
    }
}