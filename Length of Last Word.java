//leetcode 第五十八题
//Length of Last Word
/**
给一组由大小写和空格组成字符串，求最后一个单词的长度。
思路：从后往前计算即可，注意后面都是空格的情况就行了。
**/
//rt:5ms

public class Solution {
    public int lengthOfLastWord(String s) {
        int num = 0;
		for(int i=s.length()-1; i>=0; i--) {
			if(s.charAt(i) == ' ' && num != 0)
				break;
			if(s.charAt(i) != ' ')
			    num++;
		}
		return num;
    }
}