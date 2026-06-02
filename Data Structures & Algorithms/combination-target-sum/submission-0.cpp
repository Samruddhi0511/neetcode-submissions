class Solution {
public:
    void generate(int idx, vector<int>&nums, vector<int>&curr, vector<vector<int>>& result, int target){
        
        if(target==0){
            result.push_back(curr);
            return;
        }
        if(target<0) return;

        for(int i=idx; i<nums.size(); i++){
            curr.push_back(nums[i]);
            generate(i, nums, curr, result, target-nums[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        generate(0, nums, curr, result, target);
        return result;
    }
};
