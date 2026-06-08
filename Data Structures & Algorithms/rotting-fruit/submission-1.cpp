class Solution {
public:
    int time=0;
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int freshcount=0;
        queue<pair<int, int>> q;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c]==2){
                    q.push({r,c});
                }
                if(grid[r][c]==1) freshcount++;
            }
        }
        
        if(freshcount==0) return time;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};

        while(!q.empty()){
            int size=q.size();
            bool x=false;
            for(int i=0; i<size; i++){
                auto [r,c]=q.front();
                q.pop();

                for(int d=0; d<4; d++){
                    int nr=r+dr[d];
                    int nc=c+dc[d];

                    if(nr>=0 && nr<rows && nc>=0 && nc<cols && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        freshcount--;
                        q.push({nr, nc});
                        x=true;
                    }
                }
            }
            if(x) time++;
        }

        return (freshcount==0)?time :-1;
        
    }
};
