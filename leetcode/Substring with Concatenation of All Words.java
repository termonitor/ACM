//leetcode 第三十题
//Substring with Concatenation of All Words

/**
给一个字符串，再给一组单词，找出有单词组成的子字符串在所给字符串中的位置
**/
//rt:33 ms

//两种解法，第一种解法耗时较短
public class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        int N = s.length();
    	List<Integer> indexes = new ArrayList<Integer>(s.length());
    	if (words.length == 0) {
    		return indexes;
    	}
    	int M = words[0].length();
    	if (N < M * words.length) {
    		return indexes;
    	}
    	int last = N - M + 1;
    	
    	//map each string in words array to some index and compute target counters
    	Map<String, Integer> mapping = new HashMap<String, Integer>(words.length);
    	int [][] table = new int[2][words.length];
    	int failures = 0, index = 0;
    	for (int i = 0; i < words.length; ++i) {
    		Integer mapped = mapping.get(words[i]);
    		if (mapped == null) {
    			++failures;
    			mapping.put(words[i], index);
    			mapped = index++;
    		}
    		++table[0][mapped];
    	}
    	
    	//find all occurrences at string S and map them to their current integer, -1 means no such string is in words array
    	int [] smapping = new int[last];
    	for (int i = 0; i < last; ++i) {
    		String section = s.substring(i, i + M);
    		Integer mapped = mapping.get(section);
    		if (mapped == null) {
    			smapping[i] = -1;
    		} else {
    			smapping[i] = mapped;
    		}
    	}
    	
    	//fix the number of linear scans
    	for (int i = 0; i < M; ++i) {
    		//reset scan variables
    		int currentFailures = failures; //number of current mismatches
    		int left = i, right = i;
    		Arrays.fill(table[1], 0);
    		//here, simple solve the minimum-window-substring problem
    		while (right < last) {
    			while (currentFailures > 0 && right < last) {
    				int target = smapping[right];
    				if (target != -1 && ++table[1][target] == table[0][target]) {
    					--currentFailures;
    				}
    				right += M;
    			}
    			while (currentFailures == 0 && left < right) {
    				int target = smapping[left];
    				if (target != -1 && --table[1][target] == table[0][target] - 1) {
    					int length = right - left;
    					//instead of checking every window, we know exactly the length we want
    					if ((length / M) ==  words.length) {
    						indexes.add(left);
    					}
    					++currentFailures;
    				}
    				left += M;
    			}
    		}
    		
    	}
    	return indexes;
    }
}


//第二种解法，耗时较多，rt：180ms
public class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> res = new ArrayList<Integer>();
    	if (s==null || words==null || words.length==0)
    		return res;
    	int len = words[0].length();
    	Map<String, Integer> map = new HashMap<String, Integer>();
    	for (String w : words)
    		map.put(w, map.containsKey(w) ? map.get(w)+1 : 1);
    	for (int i=0; i<=s.length()-len*words.length; i++) {
    		Map<String, Integer> copy = new HashMap<String, Integer>(map);
    		for (int j=0; j<words.length; j++) {
    			String str = s.substring(i+j*len, i+j*len+len);
    			if (copy.containsKey(str)) {
    				int count = copy.get(str);
    				if (count == 1)
    					copy.remove(str);
    				else
    					copy.put(str, count-1);
    				if (copy.isEmpty()) {
    					res.add(i);
    					break;
    				}
    			}
    			else
    				break;
    		}
    	}
    	return res;
    }
}