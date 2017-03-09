//leetcode 第七十六题
//Minimum Window Substring
/**
给两串字符串S和T，求S中具有T的所有字符的最短子字符串
**/
//rt:10ms

public class Solution {
    public String minWindow(String s, String t) {
        int[] srcHash = new int[255];
		//记录目标字符串每个字母出现次数
		for(int i=0; i<t.length(); i++) {
			srcHash[t.charAt(i)]++;
		}
		int start=0, i=0;
		//用于记录窗口内每个字母出现次数
		int[] destHash = new int[255];
		int found = 0;
		int begin = -1, end = s.length(), minLength = s.length();
		for(start = i = 0; i<s.length(); i++) {
			//每来一个字符给它的出现次数+1
			destHash[s.charAt(i)]++;
			//如果加1后这个字符的数量不超过目标串中该字符的数量，则找到了一个匹配字符
			if(destHash[s.charAt(i)] <= srcHash[s.charAt(i)])
				found++;
			//如果找到的匹配字符数等于目标串长度，说明找到了一个符合要求的子串
			if(found == t.length()) {
				//将开头没用的都跳过，没用是指该字符出现次数超过了目标串中出现的次数，并把它们出现次数都减1
				while(start<i && destHash[s.charAt(start)]>srcHash[s.charAt(start)]) {
					destHash[s.charAt(start)]--;
					start++;
				}
				//这时候start指向该子串开头的字母，判断该子串长度
				if(i-start < minLength) {
					minLength = i-start;
					begin = start;
					end = i;
				}
				//把开头的这个匹配字符跳过，并将匹配字符数减1
				destHash[s.charAt(start)]--;
				found--;
				//子串起始位置+1，开始看下一个子串
				start++;
			}
		}
		//如果begin没有修改过，返回空
		return begin==-1?"":s.substring(begin, end+1);
    }
}