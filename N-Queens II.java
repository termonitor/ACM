//leetcode 第五十二题
//N-Queens II
/**
N皇后问题，经典问题，递归解决，跟上一题一个套路，只不过输出有多少解法
**/
//rt:26ms

public class Solution {
    public int totalNQueens(int n) {
        List<List<String>> list = solveNQueens(n);
		return list.size();
    }
    
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



//比较吊的一个解法，记录一下，rt:2ms
/*
    常规n-queens解法, 数答案个数.
    用column标记此行之前的哪些column已经放置了queen. 棋盘坐标(row, col)对应column的第col位(LSB --> MSB, 下同).
    用diag标记此位置之前的哪些主对角线已经放置了queen. 棋盘坐标(row, col)对应diag的第(n - 1 + row - col)位.
    用antiDiag标记此位置之前的哪些副对角线已经放置了queen. 棋盘坐标(row, col)对应antiDiag的第(row + col)位.
*/
public class Solution {
    int count = 0;
    
    public int totalNQueens(int n) {
        dfs(0, n, 0, 0, 0);
        return count;
    }
    
    private void dfs(int row, int n, int column, int diag, int antiDiag) {
        if (row == n) {
            ++count;
            return;
        }
        for (int i = 0; i < n; ++i) {
            boolean isColSafe = ((1 << i) & column) == 0;
            boolean isDiagSafe = ((1 << (n - 1 + row - i)) & diag) == 0;
            boolean isAntiDiagSafe = ((1 << (row + i)) & antiDiag) == 0;
            if (isColSafe && isDiagSafe && isAntiDiagSafe) {
                dfs(row + 1, n, (1 << i) | column, (1 << (n - 1 + row - i)) | diag, (1 << (row + i)) | antiDiag);
            }
        }
    }
}