//leetcode 第六十八题
//Text Justification
/**
给一堆字符串，和一个数字，表示每行最大的字符长度，将这一堆字符串按照顺序塞到每一行里，且要保证字符对齐。
**/
//rt:1ms

public class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> lines = new ArrayList<>();
		int index = 0;
		while(index < words.length) {
			int count = words[index].length();
			int last = index + 1;
			while(last < words.length) {
				if(words[last].length() + count + 1 > maxWidth)
					break;
				count += words[last].length()+1;
				last++;
			}
			StringBuilder sb = new StringBuilder();
			int diff = last - index - 1;
			//if last line or number of words in the line is 1, left-justified
			if(last == words.length || diff == 0) {
				for(int i=index; i<last; i++)
					sb.append(words[i]+" ");
				sb.deleteCharAt(sb.length()-1);
				for(int i=sb.length(); i<maxWidth; i++)
					sb.append(" ");
			} else {
				//middle justified
				int spaces = (maxWidth - count)/diff;
				int r = (maxWidth-count)%diff;
				for(int i=index; i<last; i++) {
					sb.append(words[i]);
					if(i < last-1) {
						for(int j=0; j<=(spaces+((i-index)<r?1:0)); j++) {
							sb.append(" ");
						}
					}
				}
			}
			lines.add(sb.toString());
			index = last;
		}
		return lines;
    }
}