#include <unordered_map>
#include <queue>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int n:nums){
            count[n]++;
        }
        //pq<type of data, container, order> name;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        for(auto& entry:count){
            //sorting done on basis of first netry ie here freq
            minHeap.push({entry.second, entry.first});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }

        vector<int> result;
        while(!minHeap.empty()){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;

    }
};
