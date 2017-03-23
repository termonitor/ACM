//leetcode 第一百二十七题
//Word Ladder
/**
给一个起始字符串，目标字符串，以及一个字符串列表，从起始字符串开始一次只能替换一个字母，找到字符串列表中对应的一个字符串，重复
这个过程，直到字符串与目标字符串相同，返回最短的一条路径的长度
**/
//rt:142ms

public class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if(wordList.size() == 0)
            return 0;
        int min = Integer.MAX_VALUE;
        Queue<String> queue = new LinkedList<String>();
        queue.offer(beginWord);
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
                        if(newWord.equals(endWord))
                            min = step;
                    }
                }
            }
        }
        return min==Integer.MAX_VALUE?0:min+1;
    }
}