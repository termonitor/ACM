//leetcode 第一百一十九题
//Pascal's Triangle II
/**
给一个数字n，构造对应层数的帕斯卡三角形，给出第n层的数列
**/
//rt:3ms

public class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        List<Integer> tempList = new ArrayList<Integer>();
        tempList.add(1);
        list.add(tempList);
        for(int i=0; i<rowIndex; i++) {
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
        return list.get(rowIndex);
    }
}


//另一种解法
//rt:1ms

public class Solution {
    public List<Integer> getRow(int rowIndex) {
        int[] nums = new int[rowIndex+1];
        nums[0] = 1;
        for(int i=1; i<rowIndex+1; i++)
            for(int j=i; j>=1; j--)
                nums[j] += nums[j-1];
        List<Integer> list = new ArrayList<Integer>();
        for(int i=0; i<rowIndex+1; i++)
            list.add(nums[i]);
        return list;
    }
}