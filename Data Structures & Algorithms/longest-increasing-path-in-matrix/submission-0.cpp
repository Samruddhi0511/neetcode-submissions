class Solution {
public:
    int m,n;
    vector<pair<int, int>> directions={{-1,0},{1,0},{0,-1},{0,1}};

    int dfs(int i, int j, vector<vector<int>> &matrix, vector<vector<int>>&dp){
        if(dp[i][j]!=0) return dp[i][j];

        int maxx=1;
        for(auto & dir : directions){
            int next_i=i+dir.first;
            int next_j=j+dir.second;

            if(next_i>=0 && next_i<m && next_j >=0 && next_j<n){
                if(matrix[next_i][next_j]>matrix[i][j]) maxx=max(maxx, 1+dfs(next_i, next_j, matrix, dp));
            }
        }

        return dp[i][j]=maxx;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        m=matrix.size();
        n=matrix[0].size();

        vector<vector<int>> dp(m, vector<int> (n, 0));
        int maxx=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                maxx=max(maxx, dfs(i, j, matrix, dp));
            }
        }

        return maxx;
    }
};
