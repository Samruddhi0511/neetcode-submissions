class Solution {
public:
    void generate(vector<int>&nums, vector<int>&curr, vector<vector<int>>&result, vector<bool>&used){
        if(curr.size()==nums.size()){
            result.push_back(curr);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(used[i]) continue;
            curr.push_back(nums[i]);
            used[i]=true;
            generate(nums, curr, result, used);
            curr.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        generate(nums, curr, result, used);
        return result;
    }
};
