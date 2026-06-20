class Solution {
public:
    int solve(int start, int end, vector<int>&nums){
        int n=end-start+1;
        if(n<=0) return 0;
        if(n==1) return nums[start];
        if(n==2) return max(nums[start], nums[end]);

        vector<int> dp(nums.size(), -1);
        dp[start]=nums[start];
        dp[start+1]= max(nums[start], nums[start+1]);
        for(int i=start+2; i<=end; i++){
            int take=dp[i-2]+nums[i];
            int dont=dp[i-1];
            dp[i]=max(take, dont);
        }
        return dp[end];
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        return max(solve(0, nums.size()-2, nums), solve(1, nums.size()-1, nums)) ;
    }
};
