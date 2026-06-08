class Solution {
public:
    void dfs(int r, int c, int prevh, vector<vector<bool>>& ocean, vector<vector<int>>&heights){
        int rows=heights.size();
        int cols=heights[0].size();

        if(r<0 || r>=rows || c<0 || c>=cols || ocean[r][c]) return;

        if(heights[r][c]< prevh) return;

        ocean[r][c]=true;

        dfs(r+1,c,heights[r][c], ocean, heights);
        dfs(r-1,c,heights[r][c], ocean, heights);
        dfs(r,c+1,heights[r][c], ocean, heights);
        dfs(r,c-1,heights[r][c], ocean, heights);

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        if(heights.empty()) return result;

        int rows=heights.size();
        int cols=heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        //launch dfs from top and bottom
        for(int c=0; c<cols; c++){
            dfs(0, c , heights[0][c], pacific, heights);

            dfs(rows-1, c, heights[rows-1][c], atlantic, heights);
        }
        for(int r=0; r<rows; r++){
            dfs(r, 0 , heights[r][0], pacific, heights);

            dfs(r, cols-1, heights[r][cols-1], atlantic, heights);
        }
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(pacific[i][j] && atlantic[i][j]) result.push_back({i,j});
            }
        }

        return result;
    }
};
