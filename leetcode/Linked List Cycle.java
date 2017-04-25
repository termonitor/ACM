//leetcode 第一百四十一题
//Linked List Cycle
/**
给一个链表，判断它是否存在环？
**/
//rt:13ms

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
    public boolean hasCycle(ListNode head) {
        Set<ListNode> set = new HashSet<>();
        while(head != null) {
            if(set.contains(head))
                return true;
            set.add(head);
            head = head.next;
        }
        return false;
    }
}