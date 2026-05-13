class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        //any value appears more than once
        unordered_map<int, int> map;
        for(int i : nums){
            map[i]++;
        }
        for(auto i:map){
            if (i.second > 1){
                return true;
            }
        }
        return false;
    }
};