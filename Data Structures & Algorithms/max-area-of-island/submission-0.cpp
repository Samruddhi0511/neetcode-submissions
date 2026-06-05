class Solution {
public:
    void dfs(int r, int c, vector<vector<int>> & grid, int &local){
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]==0) return;
        local++;
        grid[r][c]=0;
        dfs(r+1,c,grid,local);
        dfs(r-1,c,grid,local);
        dfs(r,c+1,grid,local);
        dfs(r,c-1,grid,local);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int maxarea=0;

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c]==1){
                    int local=0;
                    dfs(r,c,grid,local);
                    maxarea=max(maxarea, local);
                }
            }
        }
        return maxarea;
    }
};
