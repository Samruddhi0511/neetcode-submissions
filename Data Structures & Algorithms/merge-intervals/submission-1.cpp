class Solution {
public:
    static bool cmp(const vector<int>&a, const vector<int>&b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> result;
        for(int i=0; i<n; i++){
            if(result.empty()){result.push_back(intervals[i]);continue;}
            vector<int> last=result.back();
            if(last[1]>=intervals[i][0]){
                result.pop_back();
                result.push_back({min(last[0], intervals[i][0]), max(last[1], intervals[i][1])});
            }
            else{
                result.push_back(intervals[i]);
            }
            
        }
        return result;
    }
};
