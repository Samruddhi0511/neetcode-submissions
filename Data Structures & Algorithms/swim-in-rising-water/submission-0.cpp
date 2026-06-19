class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};

        vector<vector<bool>> vis(n, vector<bool>(n, false));

        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        vis[0][0]=true;

        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int curr_max=curr[0];
            int r=curr[1];
            int c=curr[2];

            if(r==n-1 && c==n-1) return curr_max;

            for(int i=0; i<4; i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc]){
                    vis[nr][nc]=true;
                    int next_max=max(curr_max, grid[nr][nc]);
                    pq.push({next_max, nr, nc});
                }
            }
        }
        return 0;
    }
};
