//leetcode 第二十三题
//Merge k Sorted Lists
/**
这次是合并K个有序链表，利用到二十一题的思路，利用归并的方法，两两合并，并得到最终的结果
**/
//rt:14ms

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists==null || lists.length==0)
			return null;
		return subTask(lists, 0, lists.length-1);
    }
    
    public ListNode subTask(ListNode[] lists, int l, int r) {
		if(l < r) {
			int m = (l+r)/2;
			return mergeTwoLists(subTask(lists, l, m), subTask(lists, m+1, r));
		}
		return lists[l];
	}
    
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

/**
这次是合并K个有序链表，还有一种是利用了堆的思想，时间复杂度理论上和上一种方法一样。这里还利用到java的PriorityQueue数据结构
**/
//rt:22ms

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> heap = new PriorityQueue<ListNode>(10, new Comparator<ListNode>() {
			public int compare(ListNode l1, ListNode l2) {
				return l1.val - l2.val;
			}
		});
		for(int i=0; i<lists.length; i++) {
			ListNode node = lists[i];
			if(node != null) {
				heap.offer(node);
			}
		}
		ListNode head = null;
		ListNode pre = null;
		while(heap.size() > 0) {
			ListNode cur = heap.poll();
			if(head == null) {
				head = cur;
				pre = cur;
			} else {
				pre.next = cur;
			}
			pre = cur;
			if(cur.next != null)
				heap.offer(cur.next);
		}
		return head;
    }
    
}