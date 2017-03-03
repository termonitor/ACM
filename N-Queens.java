//leetcode 第五十一题
//N-Queens
/**
N皇后问题，经典问题，递归解决
**/
//rt:23ms

public class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> list = new ArrayList<>();
		List<String> tempList = new ArrayList<>();
		//初始化tempList
		char[] c = new char[n];
		for(int i=0; i<n; i++) {
			c[i] = '.';
		}
		for(int i=0; i<n; i++) {
			tempList.add(new String(c));
		}
		backtrack(list, tempList, n, 0);
		return list;
    }
    
    public void backtrack(List<List<String>> list, List<String> tempList, int n, int count) {
		if(count == n)
			list.add(new ArrayList(tempList));
		else {
			for(int i=0; i<n; i++) {
				String str = tempList.get(count);
				if(!judge(tempList, count, i))
					continue;
				char[] c = str.toCharArray();
				c[i] = 'Q';
				tempList.set(count++, new String(c));
				backtrack(list, tempList, n, count);
				tempList.set(--count, str);
			}
		}
		
	}
	
	public boolean judge(List<String> list, int x, int y) {
 		//横着来，在递归的过程中，本身就已经保证同一行只存在一个Q了
// 		String line = list.get(x);
// 		if(line.contains("Q"))
// 			return false;
		
		//竖着来
		for(int i=0; i<list.size(); i++) {
			String str = list.get(i);
			if(str.charAt(y) == 'Q')
				return false;
		}
		
		//斜着来
		int tempx = x, tempy = y;
		while(x>0 && y>0) {
			x--;
			y--;
		}
		while(x<list.size() && y<list.size()) {
			String str = list.get(x);
			if(str.charAt(y) == 'Q')
				return false;
			x++;
			y++;
		}
		x = tempx;
		y = tempy;
		while(x<list.size()-1 && y>0) {
			x++;
			y--;
		}
		while(x>=0 && y<list.size()) {
			String str = list.get(x);
			if(str.charAt(y) == 'Q')
				return false;
			x--;
			y++;
		}
		
		return true;
	}
}