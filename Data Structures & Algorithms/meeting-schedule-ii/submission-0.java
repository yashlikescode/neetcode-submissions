/**
 * Definition of Interval:
 * public class Interval {
 *     public int start, end;
 *     public Interval(int start, int end) {
 *         this.start = start;
 *         this.end = end;
 *     }
 * }
 */

class Solution {
    public int minMeetingRooms(List<Interval> intervals) {
        HashMap<Integer,Integer> map = new HashMap<>();
        int maxEl = 0;
        int maxRoom = 0;
        int result = 0;
        for(Interval interval: intervals){
            maxEl = Math.max(maxEl,(Math.max(interval.start,interval.end)));
            if(map.containsKey(interval.start)){
                map.put(interval.start, map.get(interval.start)+1);
            } else {
                map.put(interval.start, 1);
            }

            if(map.containsKey(interval.end)){
                map.put(interval.end, map.get(interval.end)-1);
            } else {
                map.put(interval.end, -1);
            }
        }
        for(int i = 0; i <= maxEl; i++){
            if(map.containsKey(i)){
                maxRoom += map.get(i);
                result = Math.max(result,maxRoom);
            }
        }
        return result;
    }
}
