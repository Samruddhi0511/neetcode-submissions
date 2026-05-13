#include <set>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       vector<set<char>> rows(9);
       vector<set<char>> columns(9);
       vector<set<char>> boxes(9);
       for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            char c=board[i][j];
            if (c=='.'){
                continue;
            }
            //check if repeating in row
            if(rows[i].count(c)){
                return false;
            }
            else{
                rows[i].insert(c);
            }

            //check for cols
            if(columns[j].count(c)){
                return false;
            }
            else{
                columns[j].insert(c);
            }

            int boxIndex=(((i/3)*3)+(j/3));
            if(boxes[boxIndex].count(c)){
                return false;
            }
            else{
                boxes[boxIndex].insert(c);
            }
        }
       }
    }
};
