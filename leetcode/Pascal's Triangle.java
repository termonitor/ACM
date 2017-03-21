//leetcode 第一百一十八题
//Pascal's Triangle
/**
给一个数字，构造对应层数的帕斯卡三角形
**/
//rt:1ms

public class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        if(numRows == 0)
            return list;
        List<Integer> tempList = new ArrayList<Integer>();
        tempList.add(1);
        list.add(tempList);
        for(int i=0; i<numRows-1; i++) {
            tempList = list.get(i);
            List<Integer> otherList = new ArrayList<Integer>();
            otherList.add(1);
            for(int j=0; j<tempList.size(); j++) {
                if(j == tempList.size()-1)
                    otherList.add(1);
                else {
                    otherList.add(tempList.get(j) + tempList.get(j+1));
                }
            }
            list.add(otherList);
        }
        return list;
    }
}