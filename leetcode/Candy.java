//leetcode 第一百三十五题
//Candy
/**
这是一个分糖的游戏，有N个孩子，每个孩子有一个分数，给每个孩子发糖，要符合以下两个条件，1.每个孩子最少有一块糖。2.孩子的分数如果比他相邻的
孩子高，则应该比他相邻的孩子得到的糖多，求最少需要准备多少糖？
**/
//rt:5ms

public class Solution {
    public int candy(int[] ratings) {
        if(ratings==null || ratings.length==0)
            return 0;
        int prev = 1, total = 1, countDown=0;
        for(int i=1; i<ratings.length; i++) {
            if(ratings[i] >= ratings[i-1]) {
                if(countDown > 0) {
                    total += countDown*(countDown+1)/2;
                    if(countDown >= prev)
                        total += countDown-prev+1;
                    countDown = 0;
                    prev = 1;
                }
                prev = ratings[i]==ratings[i-1]?1:prev+1;
                total += prev;
            }
            else
                countDown++;
        }
        if(countDown > 0) {
            total += countDown*(countDown+1)/2;
            if(countDown >= prev)
                total += countDown-prev+1;
        }
        return total;
    }
}