//leetcode 第五十五题
//Jump Game
/**
跳跃游戏，给出一个数组，每个位置的数字代表能走几步，求能否达到最后一个节点
解题思想：思想很简单，遍历数组，求出可达最远的地方就好了。如果当前位置超过了最远地方，就表示不能达到最后一个节点。
**/
//rt:9ms

public class Solution {
    public boolean canJump(int[] nums) {
        int reachable = 0;
		for(int i=0; i<nums.length; i++) {
			if(i > reachable)
				return false;
			reachable = Math.max(reachable, i+nums[i]);
		}
		return true;
    }
}