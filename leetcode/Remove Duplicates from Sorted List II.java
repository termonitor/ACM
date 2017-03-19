//leetcode 第八十二题
//Remove Duplicates from Sorted List II
/**
给一个链表，去除中间重复的所有元素，并返回head
**/
//rt:10ms
//一不小心又写了一个low方法。。
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
        //先扫描一下，找出重复的
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        ListNode temp = head;
        while(temp != null) {
            Integer num = map.get(temp.val);
            if(num == null) {
                map.put(temp.val, 1);
            } else {
                map.put(temp.val, num+1);
            }
            temp = temp.next;
        }
        //再一个个删掉
        temp = new ListNode(0);
        temp.next = head;
        ListNode t = temp;
        while(t.next != null) {
            ListNode first = t.next;
            Integer num = map.get(first.val);
            if(num == 1) {
                t = t.next;
                continue;
            }
            t.next = first.next;
        }
        return temp.next;
    }
}

//比我的稍微高级一点点
//rt:6ms
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
            } else {
                pre.next = cur.next;
            }
            cur = cur.next;
        }
        return fakeHead.next;
    }
}