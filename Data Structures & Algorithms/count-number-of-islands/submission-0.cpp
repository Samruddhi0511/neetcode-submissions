class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>&grid){
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]=='0') return;
        grid[r][c]='0';
        
        dfs(r+1,c,grid);
        dfs(r-1,c,grid);
        dfs(r,c+1,grid);
        dfs(r,c-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int rows=grid.size();
        int cols=grid[0].size();
        int count=0;

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c]=='1'){
                    count++;
                    dfs(r,c,grid);
                }
            }
        }
        return count;
    }
};
