class Solution {
public:
    int solve(vector<int>& nums){
        int n = nums.size();
        
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> dp(nums.size(), -1);

        dp[0]=nums[0];
        dp[1]=max(nums[0], nums[1]);
        for(int i=2; i<nums.size(); i++){
            int take=dp[i-2]+nums[i];
            int dont=dp[i-1];

            dp[i]=max(take, dont);
        }

        return dp[nums.size()-1];

    }
    int rob(vector<int>& nums) {
        return solve(nums);
    }
};
