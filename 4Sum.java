//leetcode 第十八题
//4Sum
/**
计算一个数组中4个数之和为target的集合
**/
//rt:77ms

public class Solution {
    public List<List<Integer>> ret = new ArrayList<>();
    
    public List<List<Integer>> fourSum(int[] nums, int target) {
        int len = nums.length;
        if(len < 4)
            return ret;
        Arrays.sort(nums);
        int[] midNums = new int[4];
        Set<String> isExit = new HashSet<String>();
        for(int i=0; i<len-3; i++) {
            midNums[0] = nums[i];
            for(int j=i+1; j<len-2; j++) {
                midNums[1] = nums[j];
                int l = j+1;
                int r = len-1;
                int sum = target - nums[i] - nums[j];
                while(l < r) {
                    int tmp = nums[l] + nums[r];
                    if(sum == tmp) {
                        String str = "";
                        str += nums[i];
                        str += nums[j];
                        str += nums[l];
                        str += nums[r];
                        if(!isExit.contains(str)) {
                            isExit.add(str);
                            midNums[2] = nums[l];
                            midNums[3] = nums[r];
                            List<Integer> mid = new ArrayList<>();
                            mid.add(midNums[0]);
                            mid.add(midNums[1]);
                            mid.add(midNums[2]);
                            mid.add(midNums[3]);
                            ret.add(mid);
                        }
                        l++;
                        r--;
                    } else if(sum > tmp)
                        l++;
                    else
                        r--;
                }
            }
        }
        return ret;
    }
}  