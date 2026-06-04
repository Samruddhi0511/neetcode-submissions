class Solution {
public:
    vector<vector<string>> ans;
    unordered_set<int> cols;
    unordered_set<int> negDiag;
    unordered_set<int> posDiag;
    void backtrack(int row, int n, vector<string>&board){
        //base case if row = board.size() 
        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int col=0; col<n; col++){
            if(cols.count(col) || negDiag.count(row-col) || posDiag.count(row+col)){
                continue;
            }

            board[row][col]='Q';
            cols.insert(col);
            negDiag.insert(row-col);
            posDiag.insert(row+col);

            backtrack(row+1, n, board);

            board[row][col]='.';
            cols.erase(col);
            negDiag.erase(row-col);
            posDiag.erase(row+col);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board(n, string(n, '.'));
        backtrack(0, n, board);
        return ans;
    }
};
