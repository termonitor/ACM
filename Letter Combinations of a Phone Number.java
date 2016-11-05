//leetcode 第十七题
//Letter Combinations of a Phone Number
/**
根据一个数字集合，计算出所有符合手机键盘的字母输入集合
**/
//rt:3ms

public class Solution {
    public String[] letter = {"", "","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    public List<String> letterCombinations(String digits) {
        List lc = new ArrayList<>();
		if(digits==null || digits.length()==0)
			return lc;
		List tmp = null;
		for(int i=0; i<digits.length(); i++) {
			tmp = getCombination(tmp, digits.charAt(i)-'0');
		}
		return tmp;
    }
    
    public List<String> getCombination(List<String> old, int num) {
		List newList = new ArrayList<>();
		if(num==0 || num==1)
			return old;
		if(old==null || old.size()==0) {
			for(int i=0; i<letter[num].length(); i++) {
				newList.add(letter[num].charAt(i)+"");
			}
			return newList;
		}
		for(int i=0; i<old.size(); i++) {
			String tmp = old.get(i);
			for(int j=0; j<letter[num].length(); j++) {
				newList.add(tmp+letter[num].charAt(j));
			}
		}
		return newList;
	}
}