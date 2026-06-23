class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0]=1;
        //combinations(coins outside target inside) + unlimited supply(forward loop)
        for(int coin : coins){
            for (int j=coin ; j<=amount ; j++){
                dp[j]=dp[j-coin]+dp[j];
            }
        }
        return dp[amount];
    }
};
