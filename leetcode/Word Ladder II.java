//leetcode 第一百二十六题
//Word Ladder II
/**
给一个起始字符串，目标字符串，以及一个字符串列表，从起始字符串开始一次只能替换一个字母，找到字符串列表中对应的一个字符串，重复
这个过程，直到字符串与目标字符串相同，返回所有情况的列表
**/
//rt:167ms

public class Solution {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        List<List<String>> results = new ArrayList<List<String>>();
        if(wordList.size() == 0)
            return results;
        int min = Integer.MAX_VALUE;
        Queue<String> queue = new LinkedList<String>();
        queue.offer(beginWord);
        Map<String, List<String>> map = new HashMap<String, List<String>>();
        Map<String, Integer> ladder = new HashMap<String, Integer>();
        for(String str : wordList)
            ladder.put(str, Integer.MAX_VALUE);
        ladder.put(beginWord, 0);

        while(!queue.isEmpty()) {
            String word = queue.poll();
            int step = ladder.get(word)+1;
            if(step > min)
                break;
            for(int i=0; i<word.length(); i++) {
                StringBuilder builder = new StringBuilder(word);
                for(char ch='a'; ch<='z'; ch++) {
                    builder.setCharAt(i, ch);
                    String newWord = builder.toString();
                    if(ladder.containsKey(newWord)) {
                        if(step > ladder.get(newWord))
                            continue;
                        else if(step < ladder.get(newWord)) {
                            queue.offer(newWord);
                            ladder.put(newWord, step);
                        }
                        if(map.containsKey(newWord))
                            map.get(newWord).add(word);
                        else {
                            List<String> l = new LinkedList<String>();
                            l.add(word);
                            map.put(newWord, l);
                        }
                        if(newWord.equals(endWord))
                            min = step;
                    }
                }
            }
        }
        List<String> result = new ArrayList<String>();
        backtrack(results, map, endWord, beginWord, result);
        return results;
    }
    
    public void backtrack(List<List<String>> results, Map<String, List<String>> map, String end, String start, List<String> list) {
        if(end.equals(start)) {
            list.add(0, start);
            results.add(new ArrayList<String>(list));
            list.remove(0);
            return;
        }
        list.add(0, end);
        if(map.get(end) != null)
            for(String s : map.get(end))
                backtrack(results, map, s, start, list);
        list.remove(0);
    }
}