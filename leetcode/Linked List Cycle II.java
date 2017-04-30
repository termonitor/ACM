//leetcode 第一百四十二题
//Linked List Cycle II
/**
给一个链表，判断它是否存在环，并返回环的头指针，没有则返回NULL
**/
//rt:1ms

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head == null)
            return null;
        ListNode walker = head;
        ListNode runner = head;
        while(runner!=null && runner.next!=null) {
            runner = runner.next.next;
            walker = walker.next;
            if(walker == runner) {
                while(head != walker) {
                    head = head.next;
                    walker = walker.next;
                }
                return walker;
            }
        }
        return null;
    }
}