//leetcode 第五十七题
//Insert Interval
/**
给一个list，每一项都是一个区间，再给另外一个区间，把覆盖的区间都合并为一个区间，并输出
[1,2],[3,5],[6,7],[8,10],[12,16] + [4,9]  ===========>  [1,2],[3,10],[12,16]
**/
//rt:24ms

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
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        intervals.add(newInterval);
        return merge(intervals);
    }
    
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
					list.remove(list.get(j));
					break;
				}
				if(itl.start > l.end)
					continue;
				itl.start = l.start;
				itl.end = Math.max(itl.end, l.end);
				list.remove(list.get(j));
				break;
			}
			list.add(itl);
		}
		return list;
	}
}