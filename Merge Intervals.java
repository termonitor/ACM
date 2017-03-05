//leetcode 第五十六题
//Merge Intervals
/**
给一个list，每一项都是一个区间，把含有重叠的区间进行合并，并输出
**/
//rt:27ms

/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public List<Interval> merge(List<Interval> intervals) {
        List<Interval> list = new ArrayList<>();
		if(intervals.size() == 0)
			return list;
		Collections.sort(intervals, new Comparator<Interval>() {

			@Override
			public int compare(Interval o1, Interval o2) {
				// TODO Auto-generated method stub
				if(o1.start < o2.start)
					return -1;
				else if(o1.start == o2.start)
					return 0;
				else
					return 1;
			}
			
		});
		list.add(intervals.get(0));
		for(int i=1; i<intervals.size(); i++) {
			Interval itl = intervals.get(i);
			for(int j=0; j<list.size(); j++) {
				Interval l = list.get(j);
				if(itl.start == l.start && itl.end == l.end) {
					list.remove(l);
					break;
				}
				if(itl.start > l.end)
					continue;
				itl.start = l.start;
				itl.end = Math.max(itl.end, l.end);
				list.remove(l);
				break;
			}
			list.add(itl);
		}
		return list;
    }
}