class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //p+n = total sum; p-n=target p=target+total /2
        int total_sum= accumulate(nums.begin(), nums.end(), 0);
        if((target+total_sum)%2!=0) return 0;
        if(target>total_sum) return 0;
        int sum=(total_sum + target) / 2 ;
        vector<int> dp(sum +1 , 0);
        dp[0]=1;
        for(int num : nums){
            for(int tar=sum ; tar >=num ;tar --){
                dp[tar]=dp[tar-num]+dp[tar];
            }
        }
        return dp[sum];
    }
};
