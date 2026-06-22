class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        if(n==0 || s[0]=='0') return 0;

        vector<int> dp(n+1, 0);
        dp[0]=1;
        dp[1]=1;

        for(int i=2; i<=n; i++){
            int single_digit=s[i-1]-'0';
            if(single_digit>=1 && single_digit<=9) dp[i]=dp[i-1]+dp[i];

            int two=(s[i-2]-'0')*10 + single_digit;
            if(two >= 10 && two <=26) dp[i]+=dp[i-2];
        }

        return dp[n];
    }
};
