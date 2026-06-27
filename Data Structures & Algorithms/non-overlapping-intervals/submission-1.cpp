class Solution {
public:
    static bool cmp(const vector<int>&a, const vector<int>&b){
        return a[0]<b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        int prev=intervals[0][1];
        int count=0;
        for(int i=1; i<n; i++){
            if(intervals[i][0]<prev){
                count++;
                prev=min(prev,intervals[i][1] );
            }
            else{
                prev = intervals[i][1];
            }
        }
        return count;
    }
};
