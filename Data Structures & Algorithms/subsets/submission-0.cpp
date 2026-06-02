class Solution {
public:
    void generate(int idx, vector<int>&nums, vector<int>&curr, vector<vector<int>> &result){
        result.push_back(curr);

        for(int i=idx; i<nums.size(); i++){
            curr.push_back(nums[i]);

            generate(i+1, nums, curr, result);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        generate(0,nums,curr,result);
        return result;
    }
};
