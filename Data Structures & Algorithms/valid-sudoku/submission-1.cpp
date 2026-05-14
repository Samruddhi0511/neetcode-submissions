class Solution {
public:
    unordered_map<char, int> getMap(vector<char> temp){
        unordered_map<char, int> map;
        for(int i: temp){
            if(i=='.') continue;
            map[i]++;
        }

        return map;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        //all rows checked
        for(int i=0; i<9; i++){
            vector<char> temp;
            for(int j=0; j<9; j++){
                temp.push_back(board[i][j]);
            }
            unordered_map<char, int> temp_map;
            temp_map=getMap(temp);

            for(auto it: temp_map){
                if(it.second>1) return false;
            }
        }

        //all cols checked
        for(int j=0; j<9; j++){
            vector<char> temp;
            for(int i=0; i<9; i++){
                temp.push_back(board[i][j]);
            }
            unordered_map<char, int> temp_map;
            temp_map=getMap(temp);

            for(auto it: temp_map){
                if(it.second>1) return false;
            }
        }

        //check the squares
        for(int box=0; box<9; box++){
            int rowStart=(box/3)*3;
            int colStart=(box%3)*3;
            vector<char> temp;
            for(int i=rowStart; i<rowStart+3; i++){
                
                for(int j=colStart; j<colStart+3; j++){
                    
                    temp.push_back(board[i][j]);
                }
            }
            unordered_map<char, int> temp_map;
            temp_map=getMap(temp);
            for(auto it: temp_map){
                if(it.second>1) return false;
            }
        }
        return true;

    }
};
