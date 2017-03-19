//leetcode 第八十六题
//Partition List
/**
给一条链表，给一个数字，根据这个数字将链表分为两部分，一部分为小于该数字的，一部分为大于等于该数字的
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
    public ListNode partition(ListNode head, int x) {
        ListNode small = new ListNode(0);
        ListNode big = new ListNode(0);
        ListNode fakeSmall = small;
        ListNode fakeBig = big;
        while(head != null) {
            if(head.val < x) {
                fakeSmall.next = head;
                fakeSmall = fakeSmall.next;
            } else {
                fakeBig.next = head;
                fakeBig = fakeBig.next;
            }
            head = head.next;
        }
        fakeSmall.next = big.next;
        fakeBig.next = null;
        return small.next;
    }
}