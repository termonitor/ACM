//leetcode 第七十一题
//Simplify Path
/**
给一个unix模式下的绝对路径，求出它最终的简化后的路径
**/
//rt:16ms

public class Solution {
    public String simplifyPath(String path) {
        Deque<String> stack = new LinkedList<>();
		Set<String> skip = new HashSet<>(Arrays.asList("..", ".", ""));
		for(String dir : path.split("/")) {
			if(dir.equals("..") && !stack.isEmpty())
				stack.pop();
			else if(!skip.contains(dir))
				stack.push(dir);
		}
		String res = "";
		for(String dir : stack)
			res = "/"+dir+res;
		return res.isEmpty()?"/":res;
    }
}