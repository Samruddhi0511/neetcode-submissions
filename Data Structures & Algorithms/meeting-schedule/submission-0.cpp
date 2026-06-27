/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool cmp(const Interval&a, const Interval& b){
        return a.start<b.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n=intervals.size();
        if(n<=1) return true;
        sort(intervals.begin(), intervals.end(), cmp);
        for(int i=1; i<n; i++){
            if(intervals[i].start<intervals[i-1].end) return false;
        }
        return true;
    }
};
