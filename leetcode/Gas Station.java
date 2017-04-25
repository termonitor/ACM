//leetcode 第一百三十四题
//Gas Station
/**
有N个点组成的一个圈圈，从一个点到另一个点要消耗cost[i]的汽油，但是每个点又有gas[i]的汽油，求随机选择一个点出发，能否完成一圈
**/
//rt:0ms

public class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int start = 0, tank = 0, total = 0;
        for(int i=0; i<gas.length; i++) {
            if((tank = tank+gas[i]-cost[i]) < 0) {
                start = i + 1;
                total += tank;
                tank = 0;
            }
        }
        return total+tank<0?-1:start;
    }
}