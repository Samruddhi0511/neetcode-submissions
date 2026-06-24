class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();

        vector<int> A(n+2, 1);
        for(int i=0; i<n; i++) A[i+1]=nums[i];

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int i=n ; i>=1; i--){
            for(int j=i; j<=n; j++){
                for(int k=i; k<=j ; k++){
                    int curr=A[i-1]*A[k]*A[j+1];
                    int total=dp[i][k-1] + dp[k+1][j] + curr;

                    dp[i][j]=max(dp[i][j], total);
                }
            }
        }
        return dp[1][n];
    }
};
