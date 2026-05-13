class Solution {
public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b){
        return a.first > b.first;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++){
            map[nums[i]]++;
        }

        vector<pair<int, int>> pairs;
        for(auto it: map){
            pairs.push_back({it.second, it.first});
        }

        sort(pairs.begin(), pairs.end(), cmp);
        vector<int> result;
        for(int i=0; i<k; i++){
            result.push_back(pairs[i].second);
        }
        return result;
    }
};
