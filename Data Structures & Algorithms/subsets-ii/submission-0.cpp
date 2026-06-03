class Solution {
public:
    void backtrack(int idx, vector<int>&nums, vector<int>&curr, vector<vector<int>>& result){
        result.push_back(curr);

        for(int i=idx; i<nums.size(); i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            curr.push_back(nums[i]);
            backtrack(i+1, nums, curr, result);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtrack(0, nums, curr, result);
        return result;
    }
};
