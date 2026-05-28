class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using DataType = pair<long long, vector<int>>;
        priority_queue<DataType, vector<DataType>, greater<DataType> >min_heap;
        for(int i=0; i<points.size(); i++){
            long long a=points[i][0];
            long long b=points[i][1];

            long long ans = a*a + b*b;
            
            min_heap.push({ans, points[i]});
        }

        vector<vector<int>> results;
        for(int i=0; i<k; i++){
            
            results.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return results;
    }
};
