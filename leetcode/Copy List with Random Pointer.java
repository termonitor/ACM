//leetcode 第一百三十八题
//Copy List with Random Pointer
/**
给了一个特殊的数据结构，做深复制（clone）
**/
//rt:6ms

/**
 * Definition for singly-linked list with a random pointer.
 * class RandomListNode {
 *     int label;
 *     RandomListNode next, random;
 *     RandomListNode(int x) { this.label = x; }
 * };
 */
public class Solution {
    private Map<Integer, RandomListNode> ct = new HashMap<>();
    
    public RandomListNode copyRandomList(RandomListNode head) {
        return clone(head);
    }
    
    public RandomListNode clone(RandomListNode node) {
        if(node == null)
            return null;
        if(ct.containsKey(node.label))
            return ct.get(node.label);
        RandomListNode nnode = new RandomListNode(node.label);
        ct.put(node.label, nnode);
        nnode.next = clone(node.next);
        nnode.random = clone(node.random);
        return nnode;
    }
}