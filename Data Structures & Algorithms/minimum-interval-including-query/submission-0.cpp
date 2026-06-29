class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n=intervals.size();
        int m=queries.size();

        
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> queriesSorted;
        for(int i=0; i<m; i++){
            queriesSorted.push_back({queries[i], i});
        }

        sort(queriesSorted.begin(), queriesSorted.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        vector<int> res(m , -1);
        int i=0;
        for(const auto & [q, originalIdx ]: queriesSorted){
            while(i<n && intervals[i][0]<=q){
                int l=intervals[i][0];
                int r=intervals[i][1];
                minheap.push({r-l+1, r});
                i++;

            }
            while(!minheap.empty() && minheap.top().second < q){
                minheap.pop();
            }
            if(!minheap.empty()) res[originalIdx]=minheap.top().first;
        }

        return res;
    }
};
