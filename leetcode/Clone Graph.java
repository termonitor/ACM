//leetcode 第一百三十三题
//Clone Graph
/**
深复制（clone）一个无向图
**/
//rt:19ms

//两种解法，一种利用队列，时间效率略低
/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     List<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */
public class Solution {
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        if(node == null)
            return null;
        Map<Integer, UndirectedGraphNode> map = new HashMap<>();
        Set<UndirectedGraphNode> visited = new HashSet<>();
        Integer hl = node.label;
        map.put(hl, new UndirectedGraphNode(hl));
        Queue<UndirectedGraphNode> queue =  new LinkedList<>();
        queue.add(node);
        while(!queue.isEmpty()) {
            UndirectedGraphNode ori = queue.poll();
            visited.add(ori);
            UndirectedGraphNode ele = map.get(ori.label);
            if(ele == null) {
                ele = new UndirectedGraphNode(ori.label);
                map.put(ori.label, ele);
            }
            for(UndirectedGraphNode udg : ori.neighbors) {
                UndirectedGraphNode tmp = map.get(udg.label);
                if(tmp == null) {
                    tmp = new UndirectedGraphNode(udg.label);
                    map.put(udg.label, tmp);
                }
                ele.neighbors.add(tmp);
                if(!visited.contains(udg) && !queue.contains(udg))
                    queue.add(udg);
            }
        }
        return map.get(hl);
    }
}


//一种利用递归，效率较高，rt:5ms
/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     List<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */
public class Solution {
    private HashMap<Integer, UndirectedGraphNode> map = new HashMap<>();
    
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        return clone(node);
    }
    
    public UndirectedGraphNode clone(UndirectedGraphNode node) {
        if(node == null)
            return null;
        if(map.containsKey(node.label))
            return map.get(node.label);
        UndirectedGraphNode clone = new UndirectedGraphNode(node.label);
        map.put(node.label, clone);
        for(UndirectedGraphNode ele : node.neighbors) {
            clone.neighbors.add(clone(ele));
        }
        return clone;
    }
}